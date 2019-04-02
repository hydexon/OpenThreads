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
// Win32Condition.c++ - C++ Condition class built on top of posix threads.
// ~~~~~~~~~~~~~~~~~~~~
//
#include <OpenThreads/Condition.h>
#include  <OpenThreads/Thread.h>
#include "Win32ConditionPrivateData.h"

#include <assert.h>

using namespace OpenThreads;
Win32ConditionPrivateData::~Win32ConditionPrivateData()
{
}

//----------------------------------------------------------------------------
//
// Description: Constructor
//
// Use: public.
//
Condition::Condition() {
    Win32ConditionPrivateData *pd =
        new Win32ConditionPrivateData();
    _prvData = static_cast<void *>(pd);
}
//----------------------------------------------------------------------------
//
// Description: Destructor
//
// Use: public.
//
Condition::~Condition() {
    Win32ConditionPrivateData *pd =
       static_cast<Win32ConditionPrivateData *>(_prvData);

    delete pd;
}

//----------------------------------------------------------------------------
//
// Description: wait on a condition
//
// Use: public.
//
int Condition::wait(Mutex *mutex) {

    Win32ConditionPrivateData *pd =
        static_cast<Win32ConditionPrivateData *>(_prvData);

    return pd->wait(*mutex, INFINITE);
}
//----------------------------------------------------------------------------
//
// Description: wait on a condition, for a specified period of time
//
// Use: public.
//
int Condition::wait(Mutex *mutex, unsigned long ms) {

    Win32ConditionPrivateData *pd =
        static_cast<Win32ConditionPrivateData *>(_prvData);

    return pd->wait(*mutex, ms);
}
//----------------------------------------------------------------------------
//
// Description: signal a thread to wake up.
//
// Use: public.
//
int Condition::signal() {

    Win32ConditionPrivateData *pd =
        static_cast<Win32ConditionPrivateData *>(_prvData);
    return pd->signal();
}
//----------------------------------------------------------------------------
//
// Description: signal many threads to wake up.
//
// Use: public.
//
int Condition::broadcast() {

    Win32ConditionPrivateData *pd =
        static_cast<Win32ConditionPrivateData *>(_prvData);
    return pd->broadcast();
}

//---------------------------------------------------------
// ConditionEx Win32 implementation begins here
//---------------------------------------------------------

ConditionEx::ConditionEx( bool bManualReset, bool bInitialState )
{
    m_Handle = ::CreateEvent( NULL, bManualReset, bInitialState, NULL );
    assert( m_Handle );
    if ( !m_Handle )
    {
        //Helium::Print( "Failed to create event (%s)\n", Helium::GetErrorString().c_str() );
         assert(0);
    }
}

/// Destructor.
ConditionEx::~ConditionEx()
{
    BOOL result = ::CloseHandle(m_Handle);
    assert( result );
    if ( result != TRUE )
    {
        //printf( "Failed to close event (%s)\n", Helium::GetErrorString().c_str() );
        assert(0);
    }
}

/// Signal this condition.
///
/// This is used to notify threads waiting on this signal to wake up.  The effect differs based on whether this is a
/// manual-reset or auto-reset condition.
/// - For manual-reset conditions, all waiting threads will be signaled, and the condition will be left in the signaled
///   state until Reset() is called.
/// - For auto-reset conditions, the condition will remain signaled until one waiting thread is released, after which
///   the condition will automatically be reset.  If no threads are waiting when the condition is signaled, it will
///   remain in the signaled state until either a thread does attempt to wait on it or Reset() is called.
///
/// @see Wait(), Reset()
void ConditionEx::Signal()
{
    BOOL result = ::SetEvent(m_Handle);
    assert( result );
    if ( result != TRUE )
    {
        //Helium::Print( "Failed to signal event (%s)\n", Helium::GetErrorString().c_str() );
         assert(0);
    }
}

/// Reset this condition to the non-signaled state.
///
/// @see Signal(), Wait()
void ConditionEx::Reset()
{
    BOOL result = ::ResetEvent(m_Handle);
    assert( result );
    if ( result != TRUE )
    {
        //Helium::Print( "Failed to reset event (%s)\n", Helium::GetErrorString().c_str() );
         assert(0);
    }
}

/// Wait indefinitely on this condition.
///
/// This causes the current thread to sleep until the condition is signaled.  If the condition is currently in the
/// signaled state, the thread will wake up immediately.  The behavior of the condition when signaled is determined by
/// the reset mode of the condition (see Signal() for more information).
///
/// @return  True if the condition was signaled, false if waiting was interrupted.
///
/// @see Signal, Reset()
bool ConditionEx::Wait()
{
    DWORD result = ::WaitForSingleObject( m_Handle, INFINITE );

    return ( result == WAIT_OBJECT_0 );
}

/// Wait on this condition for up to a given period of time.
///
/// This causes the current thread to sleep until the condition is signaled.  If the condition is currently in the
/// signaled state, the thread will wake up immediately.  The behavior of the condition when signaled is determined by
/// the reset mode of the condition (see Signal() for more information).
///
/// @param[in] timeoutMs  Maximum number of milliseconds to wait for the condition to be signaled.
///
/// @return  True if the condition was signaled, false if waiting was interrupted.
///
/// @see Signal, Reset()
bool ConditionEx::Wait( unsigned int timeout )
{
    DWORD result = ::WaitForSingleObject(m_Handle, timeout);

    if ( result != WAIT_OBJECT_0 )
    {
        if ( result != WAIT_TIMEOUT )
        {
            //Helium::Print( "Failed to wait for event (%s)\n", Helium::GetErrorString().c_str() );
             assert(0);
        }

        return false;
    }

    return true;
}
