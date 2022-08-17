#pragma once

#include "SystemMacros.h"
#include "TypeDescriptor.h"

BEGIN_NAMESPACE

class STLContainerDescriptor : public TypeDescriptor
{
public:
	STLContainerDescriptor(const char* name, const size_t size) : TypeDescriptor(name, size), GetContainerSize(nullptr), GetContainerItem(nullptr) {}
	template<typename ContainerType>
	STLContainerDescriptor(ContainerType* dummy) : TypeDescriptor(dummy), GetContainerSize(nullptr), GetContainerItem(nullptr) {}

	template<typename CastType = void>
	const CastType& GetItem(const BytePointer object, const size_t index)
	{
		return static_cast<const CastType*>(GetContainerItem(object, index));
	}

	const size_t GetSize(const BytePointer object)
	{
		return GetContainerSize(object);
	}

protected:
	size_t(*GetContainerSize)(const BytePointer);
	BytePointer const (*GetContainerItem)(BytePointer const, size_t);
};

END_NAMESPACE