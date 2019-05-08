#include "PrimitiveTypeResolver.h"
#include "PrimitiveTypeDescriptors.h"

USING_NAMESPACE

ExoticPrimitiveTypeResolver& PrimitiveTypeResolver::GetExoticPrimitiveTypeResolver()
{
	static ExoticPrimitiveTypeResolver exoticPrimitiveTypeResolver;
	return exoticPrimitiveTypeResolver;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<int>()
{
	static PrimitiveTypeDescriptor<int> intTypeDescriptor;
	return &intTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<double>()
{
	static PrimitiveTypeDescriptor<double> doubleTypeDescriptor;
	return &doubleTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<char>()
{
	static PrimitiveTypeDescriptor<int> charTypeDescriptor;
	return &charTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<std::string>()
{
	static PrimitiveTypeDescriptor<std::string> stdStringTypeDescriptor;
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