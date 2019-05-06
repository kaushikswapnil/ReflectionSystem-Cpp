#include "TypeResolverHelper.h"
#include "STLVectorDescriptor.h"

USING_NAMESPACE

template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<int, std::allocator<int>>(std::vector<int, std::allocator<int>>* dummy)
{
	static STLVectorDescriptor vectorDescriptor((int*)nullptr);
	return &vectorDescriptor;
}

template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<double, std::allocator<double>>(std::vector<double, std::allocator<double>>* dummy)
{
	static STLVectorDescriptor vectorDescriptor((double*)nullptr);
	return &vectorDescriptor;
}

template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<char, std::allocator<char>>(std::vector<char, std::allocator<char>>* dummy)
{
	static STLVectorDescriptor vectorDescriptor((char*)nullptr);
	return &vectorDescriptor;
}

//template<>
//TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<std::string>()
//{
//	static STLVectorDescriptor vectorDescriptor((std::string*)nullptr);
//	return &vectorDescriptor;
//}

template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<int, std::allocator<int>>(std::vector<int, std::allocator<int>>* dummy);
template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<double, std::allocator<double>>(std::vector<double, std::allocator<double>>* dummy);
template<>
TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<char, std::allocator<char>>(std::vector<char, std::allocator<char>>* dummy);
//template<>
//TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<std::string>();
