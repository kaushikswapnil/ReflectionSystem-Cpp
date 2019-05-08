#pragma once
#include "SystemMacros.h"
#include <type_traits>
#include <vector>
#include "ExoticPrimitiveTypeResolver.h"
#include "IsPrimitivelyHandledType.h"

BEGIN_NAMESPACE

class TypeDescriptor;

class PrimitiveTypeResolver
{
private:
	template<typename T>
	static TypeDescriptor* GetPrimitiveDataTypeDescriptor();	

	static ExoticPrimitiveTypeResolver& GetExoticPrimitiveTypeResolver();

public:
	template<typename T, typename std::enable_if<IsPrimitivelyHandledDataType<T>::value, int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		//return GetTypeDescriptorForTypeName(typeid(T).name());
		return GetPrimitiveDataTypeDescriptor<T>();
	}

	template<typename T, typename std::enable_if<!(IsPrimitivelyHandledDataType<T>::value), int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		return GetExoticPrimitiveTypeResolver().GetTypeDescriptor<T>();
	}
};

END_NAMESPACE
USING_NAMESPACE 