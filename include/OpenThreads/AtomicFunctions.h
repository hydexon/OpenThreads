#ifndef _OPENTHREADS_ATOMICFUNCTIONS_
#define _OPENTHREADS_ATOMICFUNCTIONS_

#include <OpenThreads/Exports.h>
#include <stdint.h>

namespace OpenThreads
{
    /// Atomically swap the current value of a 32-bit integer with another value, with full memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original integer value upon swapping.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicExchange( int32_t volatile & rAtomic, int32_t value );

	/// Atomically swap the current value of a 32-bit integer with another value, with acquire semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original integer value upon swapping.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicExchangeAcquire( int32_t volatile & rAtomic, int32_t value );

	/// Atomically swap the current value of a 32-bit integer with another value, with release semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original integer value upon swapping.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicExchangeRelease( int32_t volatile & rAtomic, int32_t value );

	/// Atomically swap the current value of a 32-bit integer with another value, without any memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original integer value upon swapping.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicExchangeUnsafe( int32_t volatile & rAtomic, int32_t value );

	/// Atomically compare the current value of a 32-bit integer with another value, swapping in a different value if
	/// the values match, with full memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original integer value when the comparison occurred.  If this is the same as @c compare, the integer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicCompareExchange( int32_t volatile & rAtomic, int32_t value, int32_t compare );

	/// Atomically compare the current value of a 32-bit integer with another value, swapping in a different value if
	/// the values match, with acquire semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original integer value when the comparison occurred.  If this is the same as @c compare, the integer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicCompareExchangeAcquire( int32_t volatile & rAtomic, int32_t value, int32_t compare );

	/// Atomically compare the current value of a 32-bit integer with another value, swapping in a different value if
	/// the values match, with release semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original integer value when the comparison occurred.  If this is the same as @c compare, the integer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicCompareExchangeRelease( int32_t volatile & rAtomic, int32_t value, int32_t compare );

	/// Atomically compare the current value of a 32-bit integer with another value, swapping in a different value if
	/// the values match, without any memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original integer value when the comparison occurred.  If this is the same as @c compare, the integer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicCompareExchangeUnsafe( int32_t volatile & rAtomic, int32_t value, int32_t compare );

	/// Atomically increment a 32-bit integer, with full memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	///
	/// @return  New value after incrementing.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicIncrement( int32_t volatile & rAtomic );

	/// Atomically increment a 32-bit integer, with acquire semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	///
	/// @return  New value after incrementing.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicIncrementAcquire( int32_t volatile & rAtomic );

	/// Atomically increment a 32-bit integer, with release semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	///
	/// @return  New value after incrementing.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicIncrementRelease( int32_t volatile & rAtomic );

	/// Atomically increment a 32-bit integer, without any memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	///
	/// @return  New value after incrementing.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicIncrementUnsafe( int32_t volatile & rAtomic );

	/// Atomically decrement a 32-bit integer, with full memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	///
	/// @return  New value after decrementing.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicDecrement( int32_t volatile & rAtomic );

	/// Atomically decrement a 32-bit integer, with acquire semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	///
	/// @return  New value after decrementing.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicDecrementAcquire( int32_t volatile & rAtomic );

	/// Atomically decrement a 32-bit integer, with release semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	///
	/// @return  New value after decrementing.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicDecrementRelease( int32_t volatile & rAtomic );

	/// Atomically decrement a 32-bit integer, without any memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	///
	/// @return  New value after decrementing.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicDecrementUnsafe( int32_t volatile & rAtomic );

	/// Atomically add a value to a 32-bit integer, with full memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to add.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicAdd( int32_t volatile & rAtomic, int32_t value );

	/// Atomically add a value to a 32-bit integer, with acquire semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to add.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicAddAcquire( int32_t volatile & rAtomic, int32_t value );

	/// Atomically add a value to a 32-bit integer, with release semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to add.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicAddRelease( int32_t volatile & rAtomic, int32_t value );

	/// Atomically add a value to a 32-bit integer, without any memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to add.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicAddUnsafe( int32_t volatile & rAtomic, int32_t value );

	/// Atomically subtract a value from a 32-bit integer, with full memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to subtract.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicSubtract( int32_t volatile & rAtomic, int32_t value );

	/// Atomically subtract a value from a 32-bit integer, with acquire semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to subtract.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicSubtractAcquire( int32_t volatile & rAtomic, int32_t value );

	/// Atomically subtract a value from a 32-bit integer, with release semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to subtract.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicSubtractRelease( int32_t volatile & rAtomic, int32_t value );

	/// Atomically subtract a value from a 32-bit integer, without any memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value to subtract.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicSubtractUnsafe( int32_t volatile & rAtomic, int32_t value );

	/// Atomically AND a 32-bit integer with another value, with full memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to AND.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicAnd( int32_t volatile & rAtomic, int32_t value );

	/// Atomically AND a 32-bit integer with another value, with acquire semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to AND.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicAndAcquire( int32_t volatile & rAtomic, int32_t value );

	/// Atomically AND a 32-bit integer with another value, with release semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to AND.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicAndRelease( int32_t volatile & rAtomic, int32_t value );

	/// Atomically AND a 32-bit integer with another value, without any memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to AND.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicAndUnsafe( int32_t volatile & rAtomic, int32_t value );

	/// Atomically OR a 32-bit integer with another value, with full memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to OR.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicOr( int32_t volatile & rAtomic, int32_t value );

	/// Atomically OR a 32-bit integer with another value, with acquire semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to OR.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicOrAcquire( int32_t volatile & rAtomic, int32_t value );

	/// Atomically OR a 32-bit integer with another value, with release semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to OR.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicOrRelease( int32_t volatile & rAtomic, int32_t value );

	/// Atomically OR a 32-bit integer with another value, without any memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to OR.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicOrUnsafe( int32_t volatile & rAtomic, int32_t value );

	/// Atomically XOR a 32-bit integer with another value, with full memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to XOR.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicXor( int32_t volatile & rAtomic, int32_t value );

	/// Atomically XOR a 32-bit integer with another value, with acquire semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to XOR.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicXorAcquire( int32_t volatile & rAtomic, int32_t value );

	/// Atomically XOR a 32-bit integer with another value, with release semantics.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to XOR.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicXorRelease( int32_t volatile & rAtomic, int32_t value );

	/// Atomically XOR a 32-bit integer with another value, without any memory barriers.
	///
	/// @param[in] rAtomic  Integer to update.
	/// @param[in] value    Value with which to XOR.
	///
	/// @return  Original integer value prior to updating.
	OPENTHREAD_EXPORT_DIRECTIVE int32_t AtomicXorUnsafe( int32_t volatile & rAtomic, int32_t value );

	/// Atomically swap the current value of pointer with another value, with full memory barriers.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original pointer value upon swapping.
	OPENTHREAD_EXPORT_DIRECTIVE void* AtomicExchangePointer( void* volatile & rAtomic, void* value );

	/// Atomically swap the current value of a pointer with another value, with acquire semantics.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original pointer value upon swapping.
	OPENTHREAD_EXPORT_DIRECTIVE void* AtomicExchangePointerAcquire( void* volatile & rAtomic, void* value );

	/// Atomically swap the current value of a pointer with another value, with release semantics.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original pointer value upon swapping.
	OPENTHREAD_EXPORT_DIRECTIVE void* AtomicExchangePointerRelease( void* volatile & rAtomic, void* value );

	/// Atomically swap the current value of a pointer with another value, without any memory barriers.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original pointer value upon swapping.
	OPENTHREAD_EXPORT_DIRECTIVE void* AtomicExchangePointerUnsafe( void* volatile & rAtomic, void* value );

	/// Atomically compare the current value of a pointer with another value, swapping in a different value if
	/// the values match, with full memory barriers.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original pointer value when the comparison occurred.  If this is the same as @c compare, the pointer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	OPENTHREAD_EXPORT_DIRECTIVE void* AtomicCompareExchangePointer( void* volatile & rAtomic, void* value, void* compare );

	/// Atomically compare the current value of a pointer with another value, swapping in a different value if
	/// the values match, with acquire semantics.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original pointer value when the comparison occurred.  If this is the same as @c compare, the pointer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	OPENTHREAD_EXPORT_DIRECTIVE void* AtomicCompareExchangePointerAcquire( void* volatile & rAtomic, void* value, void* compare );

	/// Atomically compare the current value of a pointer with another value, swapping in a different value if
	/// the values match, with release semantics.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original pointer value when the comparison occurred.  If this is the same as @c compare, the pointer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	OPENTHREAD_EXPORT_DIRECTIVE void* AtomicCompareExchangePointerRelease( void* volatile & rAtomic, void* value, void* compare );

	/// Atomically compare the current value of a pointer with another value, swapping in a different value if
	/// the values match, without any memory barriers.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original pointer value when the comparison occurred.  If this is the same as @c compare, the pointer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	OPENTHREAD_EXPORT_DIRECTIVE void* AtomicCompareExchangePointerUnsafe( void* volatile & rAtomic, void* value, void* compare );

	/// Atomically swap the current value of pointer with another value, with full memory barriers.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original pointer value upon swapping.
	template< typename T >
	inline T* AtomicExchange( T* volatile & rAtomic, T* value );

	/// Atomically swap the current value of a pointer with another value, with acquire semantics.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original pointer value upon swapping.
	template< typename T >
	inline T* AtomicExchangeAcquire( T* volatile & rAtomic, T* value );

	/// Atomically swap the current value of a pointer with another value, with release semantics.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original pointer value upon swapping.
	template< typename T >
	inline T* AtomicExchangeRelease( T* volatile & rAtomic, T* value );

	/// Atomically swap the current value of a pointer with another value, without any memory barriers.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	///
	/// @return  Original pointer value upon swapping.
	template< typename T >
	inline T* AtomicExchangeUnsafe( T* volatile & rAtomic, T* value );

	/// Atomically compare the current value of a pointer with another value, swapping in a different value if
	/// the values match, with full memory barriers.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original pointer value when the comparison occurred.  If this is the same as @c compare, the pointer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	template< typename T >
	inline T* AtomicCompareExchange( T* volatile & rAtomic, T* value, T* compare );

	/// Atomically compare the current value of a pointer with another value, swapping in a different value if
	/// the values match, with acquire semantics.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original pointer value when the comparison occurred.  If this is the same as @c compare, the pointer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	template< typename T >
	inline T* AtomicCompareExchangeAcquire( T* volatile & rAtomic, T* value, T* compare );

	/// Atomically compare the current value of a pointer with another value, swapping in a different value if
	/// the values match, with release semantics.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original pointer value when the comparison occurred.  If this is the same as @c compare, the pointer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	template< typename T >
	inline T* AtomicCompareExchangeRelease( T* volatile & rAtomic, T* value, T* compare );

	/// Atomically compare the current value of a pointer with another value, swapping in a different value if
	/// the values match, without any memory barriers.
	///
	/// @param[in] rAtomic  Pointer to update.
	/// @param[in] value    Value to swap.
	/// @param[in] compare  Value against which to compare.
	///
	/// @return  Original pointer value when the comparison occurred.  If this is the same as @c compare, the pointer's
	///          value will have been updated to match @c value, otherwise it will have been left unchanged.
	template< typename T >
	inline T* AtomicCompareExchangeUnsafe( T* volatile & rAtomic, T* value, T* compare );

	//@}

    //////////////////////////////////
    // IMPLEMENTING OPTIONAL
    /////////////////////////////////
}

template< typename T >
T* OpenThreads::AtomicExchange(T* volatile & rAtomic, T* value)
{
	return reinterpret_cast< T* >(AtomicExchangePointer(
		reinterpret_cast< void* volatile& >(rAtomic),
		reinterpret_cast< void* >(value) ));
}

template< typename T >
T* OpenThreads::AtomicExchangeAcquire( T* volatile & rAtomic, T* value )
{
	return reinterpret_cast< T* >(AtomicExchangePointerAcquire(
		reinterpret_cast< void* volatile& >(rAtomic),
		reinterpret_cast< void* >(value) ));
}

template< typename T >
T* OpenThreads::AtomicExchangeRelease( T* volatile & rAtomic, T* value )
{
	return reinterpret_cast< T* >(AtomicExchangePointerRelease(
		reinterpret_cast< void* volatile& >(rAtomic),
		reinterpret_cast< void* >(value) ));
}

template< typename T >
T* OpenThreads::AtomicExchangeUnsafe( T* volatile & rAtomic, T* value )
{
	return reinterpret_cast< T* >(AtomicExchangePointerUnsafe(
		reinterpret_cast< void* volatile& >(rAtomic),
		reinterpret_cast< void* >(value) ));
}

template< typename T >
T* OpenThreads::AtomicCompareExchange(T* volatile & rAtomic, T* value, T* compare)
{
	return reinterpret_cast< T* >(AtomicCompareExchangePointer(
		reinterpret_cast< void* volatile& >(rAtomic),
		reinterpret_cast< void* >(value),
		reinterpret_cast< void* >(compare) ));
}

template< typename T >
T* OpenThreads::AtomicCompareExchangeAcquire( T* volatile & rAtomic, T* value, T* compare )
{
	return reinterpret_cast< T* >(AtomicCompareExchangePointerAcquire(
		reinterpret_cast< void* volatile& >(rAtomic),
		reinterpret_cast< void* >(value),
		reinterpret_cast< void* >(compare) ));
}

template< typename T >
T* OpenThreads::AtomicCompareExchangeRelease( T* volatile & rAtomic, T* value, T* compare )
{
	return reinterpret_cast< T* >(AtomicCompareExchangePointerRelease(
		reinterpret_cast< void* volatile& >(rAtomic),
		reinterpret_cast< void* >(value),
		reinterpret_cast< void* >(compare) ));
}

template< typename T >
T* OpenThreads::AtomicCompareExchangeUnsafe( T* volatile & rAtomic, T* value, T* compare )
{
	return reinterpret_cast< T* >(AtomicCompareExchangePointerUnsafe(
		reinterpret_cast< void* volatile& >(rAtomic),
		reinterpret_cast< void* >(value),
		reinterpret_cast< void* >(compare) ));
}


#endif

