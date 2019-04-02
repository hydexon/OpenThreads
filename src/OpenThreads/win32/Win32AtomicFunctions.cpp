#include <OpenThreads/AtomicFunctions.h>

#define VC_EXTRALEAN
#include <windows.h>

#define _GENERATE_ATOMIC_WORKER( PREFIX, OPERATION, PARAM_LIST, ACTION ) \
    PREFIX OpenThreads::Atomic##OPERATION PARAM_LIST ACTION \
    PREFIX OpenThreads::Atomic##OPERATION##Acquire PARAM_LIST ACTION \
    PREFIX OpenThreads::Atomic##OPERATION##Release PARAM_LIST ACTION \
    PREFIX OpenThreads::Atomic##OPERATION##Unsafe PARAM_LIST ACTION

//static_assert(sizeof(LONG) == sizeof(int32_t) );

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Exchange,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        return _InterlockedExchange( reinterpret_cast< volatile LONG* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    CompareExchange,
    ( int32_t volatile & rAtomic, int32_t value, int32_t compare ),
    {
        return _InterlockedCompareExchange( reinterpret_cast< volatile LONG* >( &rAtomic ), value, compare );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Increment,
    ( int32_t volatile & rAtomic ),
    {
        return _InterlockedIncrement( reinterpret_cast< volatile LONG* >( &rAtomic ) );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Decrement,
    ( int32_t volatile & rAtomic ),
    {
        return _InterlockedDecrement( reinterpret_cast< volatile LONG* >( &rAtomic ) );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Add,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        return _InterlockedExchangeAdd( reinterpret_cast< volatile LONG* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Subtract,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        return _InterlockedExchangeAdd( reinterpret_cast< volatile LONG* >( &rAtomic ), -value );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    And,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        int32_t originalValueNew = rAtomic;
        int32_t originalValueOld;
        do
        {
            originalValueOld = originalValueNew;
            originalValueNew = _InterlockedCompareExchange(
                reinterpret_cast< volatile LONG* >( &rAtomic ),
                originalValueOld & value,
                originalValueOld );
        } while( originalValueNew != originalValueOld );

        return originalValueNew;
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Or,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        int32_t originalValueNew = rAtomic;
        int32_t originalValueOld;
        do
        {
            originalValueOld = originalValueNew;
            originalValueNew = _InterlockedCompareExchange(
                reinterpret_cast< volatile LONG* >( &rAtomic ),
                originalValueOld | value,
                originalValueOld );
        } while( originalValueNew != originalValueOld );

        return originalValueNew;
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Xor,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        int32_t originalValueNew = rAtomic;
        int32_t originalValueOld;
        do
        {
            originalValueOld = originalValueNew;
            originalValueNew = _InterlockedCompareExchange(
                reinterpret_cast< volatile LONG* >( &rAtomic ),
                originalValueOld ^ value,
                originalValueOld );
        } while( originalValueNew != originalValueOld );

        return originalValueNew;
    } )

//--- 64 begins

_GENERATE_ATOMIC_WORKER(
    int64_t,
    Exchange,
    ( int64_t volatile & rAtomic, int64_t value ),
    {
        return _InterlockedExchange64( reinterpret_cast< volatile LONG64* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    int64_t,
    CompareExchange,
    ( int64_t volatile & rAtomic, int64_t value, int64_t compare ),
    {
        return _InterlockedCompareExchange64( reinterpret_cast< volatile LONG64* >( &rAtomic ), value, compare );
    } )

_GENERATE_ATOMIC_WORKER(
    int64_t,
    Increment,
    ( int64_t volatile & rAtomic ),
    {
        return _InterlockedIncrement64( reinterpret_cast< volatile LONG64* >( &rAtomic ) );
    } )

_GENERATE_ATOMIC_WORKER(
    int64_t,
    Decrement,
    ( int64_t volatile & rAtomic ),
    {
        return _InterlockedDecrement64( reinterpret_cast< volatile LONG64* >( &rAtomic ) );
    } )

_GENERATE_ATOMIC_WORKER(
    int64_t,
    Add,
    ( int64_t volatile & rAtomic, int64_t value ),
    {
        return _InterlockedExchangeAdd64( reinterpret_cast< volatile LONG64* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    int64_t,
    Subtract,
    ( int64_t volatile & rAtomic, int64_t value ),
    {
        return _InterlockedExchangeAdd64( reinterpret_cast< volatile LONG64* >( &rAtomic ), -value );
    } )

_GENERATE_ATOMIC_WORKER(
    int64_t,
    And,
    ( int64_t volatile & rAtomic, int64_t value ),
    {
        int64_t originalValueNew = rAtomic;
        int64_t originalValueOld;
        do
        {
            originalValueOld = originalValueNew;
            originalValueNew = _InterlockedCompareExchange64(
                reinterpret_cast< volatile LONG64* >( &rAtomic ),
                originalValueOld & value,
                originalValueOld );
        } while( originalValueNew != originalValueOld );

        return originalValueNew;
    } )

_GENERATE_ATOMIC_WORKER(
    int64_t,
    Or,
    ( int64_t volatile & rAtomic, int64_t value ),
    {
        int64_t originalValueNew = rAtomic;
        int64_t originalValueOld;
        do
        {
            originalValueOld = originalValueNew;
            originalValueNew = _InterlockedCompareExchange64(
                reinterpret_cast< volatile LONG64* >( &rAtomic ),
                originalValueOld | value,
                originalValueOld );
        } while( originalValueNew != originalValueOld );

        return originalValueNew;
    } )

_GENERATE_ATOMIC_WORKER(
    int64_t,
    Xor,
    ( int64_t volatile & rAtomic, int64_t value ),
    {
        int64_t originalValueNew = rAtomic;
        int64_t originalValueOld;
        do
        {
            originalValueOld = originalValueNew;
            originalValueNew = _InterlockedCompareExchange64(
                reinterpret_cast< volatile LONG64* >( &rAtomic ),
                originalValueOld ^ value,
                originalValueOld );
        } while( originalValueNew != originalValueOld );

        return originalValueNew;
    } )

//--- 64-bit ends
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#if !defined( ENVIRONMENT32 )

_GENERATE_ATOMIC_WORKER(
    void*,
    ExchangePointer,
    ( void* volatile & rAtomic, void* value ),
    {
        return reinterpret_cast< void* >( _InterlockedExchange(
            reinterpret_cast< volatile long* >( &rAtomic ),
            reinterpret_cast< long >( value ) ) );
    } )

_GENERATE_ATOMIC_WORKER(
    void*,
    CompareExchangePointer,
    ( void* volatile & rAtomic, void* value, void* compare ),
    {
        return reinterpret_cast< void* >( _InterlockedCompareExchange(
            reinterpret_cast< volatile long* >( &rAtomic ),
            reinterpret_cast< long >( value ),
            reinterpret_cast< long >( compare ) ) );
    } )

#else

_GENERATE_ATOMIC_WORKER(
    void*,
    ExchangePointer,
    ( void* volatile & rAtomic, void* value ),
    {
        return static_cast< void* >( _InterlockedExchangePointer(
            reinterpret_cast< void* volatile * >( &rAtomic ),
            value ) );
    } )

_GENERATE_ATOMIC_WORKER(
    void*,
    CompareExchangePointer,
    ( void* volatile & rAtomic, void* value, void* compare ),
    {
        return static_cast< void* >( _InterlockedCompareExchangePointer(
            reinterpret_cast< void* volatile * >( &rAtomic ),
            value,
            compare ) );
    } )

#endif

#undef _GENERATE_ATOMIC_WORKER