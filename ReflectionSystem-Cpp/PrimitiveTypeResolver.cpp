#include "PrimitiveTypeResolver.h"
#include "PrimitiveTypeDescriptors.h"

USING_NAMESPACE

ReflectionSystem::ExoticPrimitiveTypeResolver& ReflectionSystem::PrimitiveTypeResolver::GetExoticPrimitiveTypeResolver()
{
	static ExoticPrimitiveTypeResolver exoticPrimitiveTypeResolver;
	return exoticPrimitiveTypeResolver;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<int>()
{
	static IntDescriptor intTypeDescriptor;
	return &intTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<double>()
{
	static DoubleDescriptor doubleTypeDescriptor;
	return &doubleTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<char>()
{
	static CharDescriptor charTypeDescriptor;
	return &charTypeDescriptor;
}

template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<int>();
template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<double>();
template<>
TypeDescriptor* PrimitiveTypeResolver::GetPrimitiveDataTypeDescriptor<char>();