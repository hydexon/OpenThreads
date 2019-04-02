#include <OpenThreads/AtomicFunctions.h>


#ifdef _WIN32 
#error "Win32 has their own intrinsics, use it instead Clang/Gcc ones!"
#endif


#define _GENERATE_ATOMIC_WORKER( PREFIX, OPERATION, PARAM_LIST, ACTION ) \
    PREFIX OpenThreads::Atomic##OPERATION PARAM_LIST ACTION \
    PREFIX OpenThreads::Atomic##OPERATION##Acquire PARAM_LIST ACTION \
    PREFIX OpenThreads::Atomic##OPERATION##Release PARAM_LIST ACTION \
    PREFIX OpenThreads::Atomic##OPERATION##Unsafe PARAM_LIST ACTION

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Exchange,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        return __sync_val_compare_and_swap( static_cast< int32_t volatile* >( &rAtomic ), *static_cast< int32_t volatile* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    CompareExchange,
    ( int32_t volatile & rAtomic, int32_t value, int32_t compare ),
    {
        return __sync_val_compare_and_swap( static_cast< int32_t volatile* >( &rAtomic ), compare, value );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Increment,
    ( int32_t volatile & rAtomic ),
    {
        return __sync_add_and_fetch( static_cast< int32_t volatile* >( &rAtomic ), 1 );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Decrement,
    ( int32_t volatile & rAtomic ),
    {
        return __sync_sub_and_fetch( static_cast< int32_t volatile* >( &rAtomic ), 1 );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Add,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        return __sync_fetch_and_add( static_cast< int32_t volatile* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Subtract,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        return __sync_fetch_and_sub( static_cast< int32_t volatile* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    And,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        return __sync_fetch_and_and( static_cast< int32_t volatile* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Or,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        return __sync_fetch_and_or( static_cast< int32_t volatile* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    int32_t,
    Xor,
    ( int32_t volatile & rAtomic, int32_t value ),
    {
        return __sync_fetch_and_xor( static_cast< int32_t volatile* >( &rAtomic ), value );
    } )

_GENERATE_ATOMIC_WORKER(
    void*,
    ExchangePointer,
    ( void* volatile & rAtomic, void* value ),
    {
        return static_cast<void*>( __sync_val_compare_and_swap( static_cast< void* volatile* >( &rAtomic ), rAtomic, value ) );
    } )

_GENERATE_ATOMIC_WORKER(
    void*,
    CompareExchangePointer,
    ( void* volatile & rAtomic, void* value, void* compare ),
    {
        return static_cast<void*>( __sync_val_compare_and_swap( reinterpret_cast< void* volatile* >( &rAtomic ), compare, value ) );
    } )

#undef _GENERATE_ATOMIC_WORKER
