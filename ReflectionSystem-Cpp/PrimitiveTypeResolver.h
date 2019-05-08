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
	//Unhandled types
	template<typename T, typename std::enable_if<!(IsPrimitivelyHandledDataType<T>::value), int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		static_assert(false, "This type does not have a relevant TypeDescriptor.");
	}

	//For primitive data types. #TODO Use flags later
	template<typename T, typename std::enable_if<((std::is_fundamental<T>::value || IsPrimitivelyHandledDataType<T>::value) && !(IsSupportedSTLContainer<T>::value)), int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		return GetPrimitiveDataTypeDescriptor<T>();
	}

	template<typename T, typename std::enable_if<(IsSupportedSTLContainer<T>::value), int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		return GetExoticPrimitiveTypeResolver().GetTypeDescriptor<T>();
	}
};

END_NAMESPACE
USING_NAMESPACE 