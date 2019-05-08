#include "TypeResolverHelper.h"
#include "STLVectorDescriptor.h"

USING_NAMESPACE

template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<int, std::allocator<int>>(std::vector<int, std::allocator<int>>*)
{
	static STLVectorDescriptor vectorDescriptor((int*)nullptr);
	return &vectorDescriptor;
}

template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<double, std::allocator<double>>(std::vector<double, std::allocator<double>>*)
{
	static STLVectorDescriptor vectorDescriptor((double*)nullptr);
	return &vectorDescriptor;
}

template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<char, std::allocator<char>>(std::vector<char, std::allocator<char>>*)
{
	static STLVectorDescriptor vectorDescriptor((char*)nullptr);
	return &vectorDescriptor;
}

unsigned int TypeResolverHelper::CalculateHashForTypeName(const std::string& typeName)
{
	return 0; //#TODO Implement the hash 
}

//template<>
//TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<std::string>()
//{
//	static STLVectorDescriptor vectorDescriptor((std::string*)nullptr);
//	return &vectorDescriptor;
//}

template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<int, std::allocator<int>>(std::vector<int, std::allocator<int>>*);
template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<double, std::allocator<double>>(std::vector<double, std::allocator<double>>*);
template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<char, std::allocator<char>>(std::vector<char, std::allocator<char>>*);
//template<>
//TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<std::string>();
