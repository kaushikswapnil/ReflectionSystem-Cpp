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
};

END_NAMESPACE