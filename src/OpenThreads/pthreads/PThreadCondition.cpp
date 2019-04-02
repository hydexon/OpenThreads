/* -*-c++-*- OpenThreads library, Copyright (C) 2002 - 2007  The Open Thread Group
 *
 * This library is open source and may be redistributed and/or modified under  
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/


//
// PThreadCondition.c++ - C++ Condition class built on top of posix threads.
// ~~~~~~~~~~~~~~~~~~~~
//

#if defined(_MSC_VER) || defined(__MINGW32__)
#  include <time.h>
#else
#  include <sys/time.h>
#endif

#include <stdio.h>

#include <OpenThreads/Condition.h>
#include "PThreadConditionPrivateData.h"
#include "PThreadMutexPrivateData.h"

#include <errno.h>

using namespace OpenThreads;

#if defined(_MSC_VER) || defined(__MINGW32__)
int gettimeofday(struct timeval* tp, void* tzp) {
    LARGE_INTEGER t;

    if(QueryPerformanceCounter(&t)) {
        /* hardware supports a performance counter */
        static int been_here = 0;
        static LARGE_INTEGER f;
        if( !been_here )
        {
            been_here = 1;
            QueryPerformanceFrequency(&f);
        }
        tp->tv_sec = t.QuadPart/f.QuadPart;
        tp->tv_usec = ((float)t.QuadPart/f.QuadPart*1000*1000)
                  - (tp->tv_sec*1000*1000);
    } else {
        /* hardware doesn't support a performance counter, so get the
               time in a more traditional way. */
        DWORD t;
        t = timeGetTime();
        tp->tv_sec = t / 1000;
        tp->tv_usec = t % 1000;
    }

    /* 0 indicates that the call succeeded. */
    return 0;
}
#endif

//----------------------------------------------------------------------------
// This cancel cleanup handler is necessary to ensure that the barrier's
// mutex gets unlocked on cancel. Otherwise deadlocks could occur with 
// later joins.
//
void condition_cleanup_handler(void *arg) {

    pthread_mutex_t *mutex = static_cast<pthread_mutex_t *>(arg);
    
    pthread_mutex_unlock(mutex);

}

//----------------------------------------------------------------------------
//
// Decription: Constructor
//
// Use: public.
//
Condition::Condition() {

    PThreadConditionPrivateData *pd =
        new PThreadConditionPrivateData();

    int status = pthread_cond_init( &pd->condition, NULL );
    if (status)
    {
        printf("Error: pthread_cond_init(,) returned error status, status = %d\n",status);
    }

    _prvData = static_cast<void *>(pd);

}

//----------------------------------------------------------------------------
//
// Decription: Destructor
//
// Use: public.
//
Condition::~Condition() {

    PThreadConditionPrivateData *pd =
        static_cast<PThreadConditionPrivateData *>(_prvData);

    int status = pthread_cond_destroy( &pd->condition );
    if (status)
    {
        printf("Error: pthread_cond_destroy(,) returned error status, status = %d\n",status);
    }

    delete pd;

}

//----------------------------------------------------------------------------
//
// Decription: wait on a condition
//
// Use: public.
//
int Condition::wait(Mutex *mutex) {

    PThreadConditionPrivateData *pd =
        static_cast<PThreadConditionPrivateData *>(_prvData);

    PThreadMutexPrivateData *mpd =
        static_cast<PThreadMutexPrivateData *>(mutex->_prvData);

    int status;
    
    pthread_cleanup_push(condition_cleanup_handler, &mpd->mutex);

    status = pthread_cond_wait( &pd->condition, &mpd->mutex );

    pthread_cleanup_pop(0);

    return status;


}

//----------------------------------------------------------------------------
//
// Decription: wait on a condition, for a specified period of time
//
// Use: public.
//
int Condition::wait(Mutex *mutex, unsigned long int ms) {

    PThreadConditionPrivateData *pd =
        static_cast<PThreadConditionPrivateData *>(_prvData);

    PThreadMutexPrivateData *mpd =
        static_cast<PThreadMutexPrivateData *>(mutex->_prvData);


    // wait time is now in ms milliseconds, so need to convert to seconds and nanoseconds for timespec strucuture.
    unsigned int sec = ms / 1000;
    unsigned int nsec = (ms % 1000) * 1000000;

    // add to the current time    
    struct ::timeval now;
    ::gettimeofday( &now, 0 );

    sec += now.tv_sec;
    nsec += now.tv_usec*1000;

    // now pass on any overflow from nsec onto seconds.
    sec += nsec / 1000000000;
    nsec = nsec % 1000000000;

    struct timespec abstime;
    abstime.tv_sec = sec;
    abstime.tv_nsec = nsec;

    int status;

    pthread_cleanup_push(condition_cleanup_handler, &mpd->mutex);

    status = pthread_cond_timedwait( &pd->condition, &mpd->mutex, &abstime );

    pthread_cleanup_pop(0);

    return status;

}

//----------------------------------------------------------------------------
//
// Decription: signal a thread to wake up.
//
// Use: public.
//
int Condition::signal() {

    PThreadConditionPrivateData *pd =
        static_cast<PThreadConditionPrivateData *>(_prvData);

    return pthread_cond_signal( &pd->condition );
}

//----------------------------------------------------------------------------
//
// Decription: signal many threads to wake up.
//
// Use: public.
//
int Condition::broadcast() {

    PThreadConditionPrivateData *pd =
        static_cast<PThreadConditionPrivateData *>(_prvData);

    return pthread_cond_broadcast( &pd->condition );
}


//---------------------------------------------------------
// ConditionEx Pthreads implementation begins here
//---------------------------------------------------------


void event_init(Condition::Handle* evt, bool manual_reset, bool initial_state)
{
    evt->manual_reset = manual_reset;
    evt->is_signaled = initial_state;
    evt->waiting_threads = 0;

    pthread_cond_init (&evt->condition, NULL);
    pthread_mutex_init (&evt->lock, NULL);
}

void event_destroy(ConditionEx::Handle* evt)
{
    pthread_mutex_destroy (&evt->lock);
    pthread_cond_destroy (&evt->condition);
}

bool event_wait(ConditionEx::Handle* evt, const timespec* timeout)
{
    bool result = true;

    // grab the lock first
    pthread_mutex_lock (&evt->lock);

    // Condition is currently signaled
    if (evt->is_signaled)
    {
        if (!evt->manual_reset)
        {
            // AUTO: reset state
            evt->is_signaled = 0;
        }
    }
    else // evt is currently not signaled
    {
        evt->waiting_threads++;

        if ( timeout )
        {
            if ( pthread_cond_timedwait (&evt->condition, &evt->lock, timeout) == ETIMEDOUT )
            {
                result = false;
            }
        }
        else
        {
            pthread_cond_wait (&evt->condition, &evt->lock);
        }

        evt->waiting_threads--;
    }

    // Now we can let go of the lock
    pthread_mutex_unlock (&evt->lock);

    return result;
}

void event_signal(ConditionEx::Handle* evt)
{
    // grab the lock first
    pthread_mutex_lock (&evt->lock);

    // Manual-reset evt
    if (evt->manual_reset)
    {
        // signal evt
        evt->is_signaled = true;

        // wakeup all
        pthread_cond_broadcast (&evt->condition);
    }
    // Auto-reset evt
    else
    {
        if (evt->waiting_threads == 0)
        {
            // No waiters: signal evt
            evt->is_signaled = true;
        }
        else
        {
            // Waiters: wakeup one waiter
            pthread_cond_signal (&evt->condition);
        }
    }

    // Now we can let go of the lock
    pthread_mutex_unlock (&evt->lock);
}

void event_pulse(ConditionEx::Handle* evt)
{
    // grab the lock first
    pthread_mutex_lock (&evt->lock);

    // Manual-reset evt
    if (evt->manual_reset)
    {
        // Wakeup all waiters
        pthread_cond_broadcast (&evt->condition);
    }

    // Auto-reset evt: wakeup one waiter
    else
    {
        pthread_cond_signal (&evt->condition);

        // Reset evt
        evt->is_signaled = false;
    }

    // Now we can let go of the lock
    pthread_mutex_unlock (&evt->lock);
}

void event_reset(ConditionEx::Handle* evt)
{
    // Grab the lock first
    pthread_mutex_lock (&evt->lock);

    // Reset evt
    evt->is_signaled = false;

    // Now we can let go of the lock
    pthread_mutex_unlock (&evt->lock);
}

/// Constructor.
///
/// @param[in] resetMode      Whether the condition should automatically reset after releasing a thread when signaled
///                           or whether the condition will remain signaled until Reset() is called.
/// @param[in] bInitialState  True to initialize this condition in the signaled state, false to initialize non-signaled.
ConditionEx::ConditionEx( bool bManualReset, bool bInitialState )
{
    event_init(&m_Handle, bManualReset, bInitialState);
}

ConditionEx::~ConditionEx()
{
    event_destroy(&m_Handle);
}

void ConditionEx::Signal()
{
    event_signal(&m_Handle);
}

void ConditionEx::Reset()
{
    event_reset(&m_Handle);
}

bool ConditionEx::Wait()
{
    return event_wait(&m_Handle, NULL);
}

bool ConditionEx::Wait( uint32_t timeoutMs )
{
    struct timespec spec;
    spec.tv_sec = timeoutMs / 1000;
    spec.tv_nsec = ( timeoutMs % 1000 ) * 1000000;
    return event_wait(&m_Handle, &spec);
}
