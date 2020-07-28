#ifndef N_STACK_HPP_INCLUDED
#define N_STACK_HPP_INCLUDED

#include <Core/NType.hpp>
namespace Neurotec { namespace Collections { namespace Internal
{
#include <Collections/NStack.h>
}}}

namespace Neurotec { namespace Collections
{

class NStack : private Internal::NStack
{
	N_DECLARE_PRIMITIVE_CLASS(NStack)

public:
	explicit NStack(NSizeType elementSize)
	{
		NCheck(Internal::NStackInit(this, elementSize, NULL));
	}

	NStack(const NType & elementType)
	{
		NCheck(Internal::NStackInit(this, 0, elementType.GetHandle()));
	}

	NStack(NTypeOfProc pElementTypeOf)
	{
		NCheck(Internal::NStackInitP(this, 0, pElementTypeOf));
	}

	NStack(NSizeType elementSize, NInt capacity)
	{
		NCheck(Internal::NStackInitWithCapacity(this, elementSize, NULL, capacity));
	}

	NStack(const NType & elementType, NInt capacity)
	{
		NCheck(Internal::NStackInitWithCapacity(this, 0, elementType.GetHandle(), capacity));
	}

	NStack(NTypeOfProc pElementTypeOf, NInt capacity)
	{
		NCheck(Internal::NStackInitWithCapacityP(this, 0, pElementTypeOf, capacity));
	}

	NStack(NSizeType elementSize, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NStackInitEx(this, elementSize, NULL, capacity, maxCapacity, growthDelta, alignment));
	}

	NStack(const NType & elementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NStackInitEx(this, 0, elementType.GetHandle(), capacity, maxCapacity, growthDelta, alignment));
	}

	NStack(NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NStackInitExP(this, 0, pElementTypeOf, capacity, maxCapacity, growthDelta, alignment));
	}

	~NStack()
	{
		NCheck(Internal::NStackDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NStackGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NStackSetCapacity(this, value));
	}

	NInt GetCount()
	{
		NInt value;
		NCheck(Internal::NStackGetCount(this, &value));
		return value;
	}

	bool Contains(const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NStackContains(this, NULL, pValue, valueSize, &result));
		return result != 0;
	}

	bool Contains(const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NStackContains(this, valueType.GetHandle(), pValue, valueSize, &result));
		return result != 0;
	}

	bool Contains(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NStackContainsP(this, pValueTypeOf, pValue, valueSize, &result));
		return result != 0;
	}

	void * GetTop(NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NStackGetTop(this, elementSize, NULL, &pValue));
		return pValue;
	}

	void * GetTop(const NType & elementType)
	{
		void * pValue;
		NCheck(Internal::NStackGetTop(this, 0, elementType.GetHandle(), &pValue));
		return pValue;
	}

	void * GetTop(NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NStackGetTopP(this, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void Peek(void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPeek(this, NULL, pValue, valueSize));
	}

	void Peek(const NType & valueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPeek(this, valueType.GetHandle(), pValue, valueSize));
	}

	void Peek(NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPeekP(this, pValueTypeOf, pValue, valueSize));
	}

	void Pop(void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPop(this, NULL, pValue, valueSize));
	}

	void Pop(const NType & valueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPop(this, valueType.GetHandle(), pValue, valueSize));
	}

	void Pop(NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPopP(this, pValueTypeOf, pValue, valueSize));
	}

	void Push(const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPush(this, NULL, pValue, valueSize));
	}

	void Push(const NType & valueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPush(this, valueType.GetHandle(), pValue, valueSize));
	}

	void Push(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPushP(this, pValueTypeOf, pValue, valueSize));
	}

	void Clear()
	{
		NCheck(Internal::NStackClear(this));
	}

	NInt CopyTo(void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NStackCopyTo(this, NULL, pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(const NType & valueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NStackCopyTo(this, valueType.GetHandle(), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NStackCopyToP(this, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void * ToArray(NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NStackToArray(this, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	void * ToArray(const NType & valueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NStackToArray(this, 0, valueType.GetHandle(), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NStackToArrayP(this, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}
};

}}

#endif // !N_STACK_HPP_INCLUDED
