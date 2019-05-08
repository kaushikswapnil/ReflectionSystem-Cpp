#pragma once
#include "SystemMacros.h"
#include <vector>

BEGIN_NAMESPACE

class TypeDescriptor;

class TypeResolverHelper
{
public:
	template<typename ItemType, typename Alloc>
	static TypeDescriptor* GetSTDVectorTypeDescriptor(std::vector<ItemType, Alloc>*); 
	static unsigned int CalculateHashForTypeName(const std::string& typeName);
};

END_NAMESPACE

