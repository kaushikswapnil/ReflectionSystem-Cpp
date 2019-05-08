#include "PrimitiveTypeResolver.h"
#include "PrimitiveTypeDescriptors.h"

USING_NAMESPACE

//uint64_t constexpr mix(char m, uint64_t s)
//{
//	return ((s << 7) + ~(s >> 3)) + ~m;
//}
//
//uint64_t constexpr hash(const char * m)
//{
//	return (*m) ? mix(*m, hash(m + 1)) : 0;
//}
//
//
//
//
//TypeDescriptor* constexpr PrimitiveTypeResolver::GetTypeDescriptorForTypeName(const char* typeName)
//{
//	TypeDescriptor* retVal = nullptr;
//
//	static IntDescriptor intDescriptor;
//	static CharDescriptor charDescriptor;
//	static DoubleDescriptor doubleDescriptor;
//
//	switch (hash(typeName))
//	{
//		case hash("int"):
//		retVal = &intDescriptor;
//		break;
//
//		case hash("double"):
//		retVal = &doubleDescriptor;
//		break;
//
//		case hash("char"):
//		retVal = &charDescriptor;
//		break;
//
//		default:
//		static_assert(false, "Could not find typedescriptor for this type.");
//		break;
//	}
//
//	return retVal;
//}

ExoticPrimitiveTypeResolver& PrimitiveTypeResolver::GetExoticPrimitiveTypeResolver()
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