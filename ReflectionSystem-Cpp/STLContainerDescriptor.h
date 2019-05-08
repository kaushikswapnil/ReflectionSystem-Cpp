#pragma once

#include "SystemMacros.h"
#include "TypeDescriptor.h"

BEGIN_NAMESPACE

class STLContainerDescriptor : public TypeDescriptor
{
public:
	STLContainerDescriptor(const char* name, const size_t size) : TypeDescriptor(name, size) {}
	template<typename ContainerType>
	STLContainerDescriptor(ContainerType* dummy) : TypeDescriptor(dummy) {}

	template<typename CastType = void>
	const CastType& GetItem(const void* object, const size_t index)
	{
		return static_cast<const CastType*>(GetContainerItem(object, index));
	}

	const size_t GetSize(const void* object)
	{
		return GetContainerSize(object);
	}

protected:
	size_t(*GetContainerSize)(const void*);
	const void* (*GetContainerItem)(const void*, size_t);
};

END_NAMESPACE