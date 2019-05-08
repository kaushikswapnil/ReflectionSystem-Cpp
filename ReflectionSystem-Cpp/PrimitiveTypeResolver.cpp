#include "PrimitiveTypeResolver.h"
#include "PrimitiveDataTypeDescriptor.h"

USING_NAMESPACE

ExoticPrimitiveTypeResolver& PrimitiveTypeResolver::GetExoticPrimitiveTypeResolver()
{
	static ExoticPrimitiveTypeResolver exoticPrimitiveTypeResolver;
	return exoticPrimitiveTypeResolver;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<int>()
{
	static PrimitiveDataTypeDescriptor<int> intTypeDescriptor;
	return &intTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<double>()
{
	static PrimitiveDataTypeDescriptor<double> doubleTypeDescriptor;
	return &doubleTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<char>()
{
	static PrimitiveDataTypeDescriptor<int> charTypeDescriptor;
	return &charTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<std::string>()
{
	static PrimitiveDataTypeDescriptor<std::string> stdStringTypeDescriptor;
	return &stdStringTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<int>();
template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<double>();
template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<char>();
template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<std::string>();