#include "TypeResolver.h"
#include "PrimitiveDataTypeDescriptor.h"

USING_NAMESPACE

template<>
TypeDescriptor* DefaultResolver::GetPrimitiveDataTypeDescriptor<int>()
{
	static PrimitiveDataTypeDescriptor<int> intTypeDescriptor;
	return &intTypeDescriptor;
}

template<>
TypeDescriptor* DefaultResolver::GetPrimitiveDataTypeDescriptor<double>()
{
	static PrimitiveDataTypeDescriptor<double> doubleTypeDescriptor;
	return &doubleTypeDescriptor;
}

template<>
TypeDescriptor* DefaultResolver::GetPrimitiveDataTypeDescriptor<char>()
{
	static PrimitiveDataTypeDescriptor<int> charTypeDescriptor;
	return &charTypeDescriptor;
}

template<>
TypeDescriptor* DefaultResolver::GetPrimitiveDataTypeDescriptor<std::string>()
{
	static PrimitiveDataTypeDescriptor<std::string> stdStringTypeDescriptor;
	return &stdStringTypeDescriptor;
}

template<>
TypeDescriptor* DefaultResolver::GetPrimitiveDataTypeDescriptor<int>();
template<>
TypeDescriptor* DefaultResolver::GetPrimitiveDataTypeDescriptor<double>();
template<>
TypeDescriptor* DefaultResolver::GetPrimitiveDataTypeDescriptor<char>();
template<>
TypeDescriptor* DefaultResolver::GetPrimitiveDataTypeDescriptor<std::string>();