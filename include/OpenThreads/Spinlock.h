#ifndef _OPENTHREADS_SPINLOCK_
#define _OPENTHREADS_SPINLOCK_

#include <OpenThreads/Exports.h>
#include <OpenThreads/AtomicFunctions.h>
#include <OpenThreads/Thread.h>
#include <assert.h>

namespace OpenThreads 
{
    class OPENTHREAD_EXPORT_DIRECTIVE SpinLock 
    {
    public:
        inline SpinLock();

        inline int lock();
        inline int unlock();
        inline int trylock();    
        inline bool is_locked();

    private:
        volatile int32_t m_counter;
    };
}

OpenThreads::SpinLock::SpinLock() : m_counter(0) {}
int OpenThreads::SpinLock::lock() 
{
    while( OpenThreads::AtomicCompareExchangeAcquire(m_counter, 1, 0) != 0) {
        OpenThreads::Thread::YieldCurrentThread();
    }
    return 0;
}

int OpenThreads::SpinLock::unlock() 
{
    assert( m_counter != 0);
    OpenThreads::AtomicExchangeRelease(m_counter, 0);

    return 0;
}

int OpenThreads::SpinLock::trylock() 
{
    return (OpenThreads::AtomicCompareExchangeAcquire(m_counter, 1, 0) ? 0 : -1);
}

bool OpenThreads::SpinLock::is_locked()
{
    return (m_counter != 0);
}



#endif

