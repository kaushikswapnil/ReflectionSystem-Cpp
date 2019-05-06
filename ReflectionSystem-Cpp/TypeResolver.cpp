#include "TypeResolver.h"

template<>
TypeDescriptor* DefaultResolver::GetPrimitiveTypeDescriptor<int>()
{
	static TypeDescriptor_Int intTypeDescriptor;
	return &intTypeDescriptor;
}

template<>
TypeDescriptor* DefaultResolver::GetPrimitiveTypeDescriptor<double>()
{
	static TypeDescriptor_Double doubleTypeDescriptor;
	return &doubleTypeDescriptor;
}

template<>
TypeDescriptor* DefaultResolver::GetPrimitiveTypeDescriptor<std::string>()
{
	static TypeDescriptor_STDString stringTypeDescriptor;
	return &stringTypeDescriptor;
}

template<>
TypeDescriptor* DefaultResolver::GetPrimitiveTypeDescriptor<int>();
template<>
TypeDescriptor* DefaultResolver::GetPrimitiveTypeDescriptor<double>();
template<>
TypeDescriptor* DefaultResolver::GetPrimitiveTypeDescriptor<std::string>();