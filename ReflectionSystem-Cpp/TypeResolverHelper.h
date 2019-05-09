#pragma once
#include "SystemMacros.h"
#include <vector>

BEGIN_NAMESPACE

class TypeDescriptor;

class TypeResolverHelper
{
public:
	
	static unsigned int CalculateHashForTypeName(const std::string& typeName);
};

END_NAMESPACE

