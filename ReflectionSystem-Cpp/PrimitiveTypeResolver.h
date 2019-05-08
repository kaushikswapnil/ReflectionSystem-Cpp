#pragma once
#include "SystemMacros.h"
#include <type_traits>
#include <vector>
#include "ExoticPrimitiveTypeResolver.h"

BEGIN_NAMESPACE

class TypeDescriptor;

//uint64_t constexpr mix(char m, uint64_t s);
//uint64_t constexpr hash(const char * m);


class PrimitiveTypeResolver
{
private:
	template<typename T>
	static TypeDescriptor* GetPrimitiveDataTypeDescriptor();

	template<typename T>
	struct IsPrimitiveDataType
	{
		enum { value = std::is_fundamental<T>::value };
	};

	static ExoticPrimitiveTypeResolver& GetExoticPrimitiveTypeResolver();

	//static TypeDescriptor& constexpr GetTypeDescriptorForTypeName(const char* typeName);

public:
	template<typename T, typename std::enable_if<IsPrimitiveDataType<T>::value, int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		//return GetTypeDescriptorForTypeName(typeid(T).name());
		return GetPrimitiveDataTypeDescriptor<T>();
	}

	template<typename T, typename std::enable_if<!(IsPrimitiveDataType<T>::value), int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		return GetExoticPrimitiveTypeResolver().GetTypeDescriptor<T>();
	}
};

END_NAMESPACE
USING_NAMESPACE 