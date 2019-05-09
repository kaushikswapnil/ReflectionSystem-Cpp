#include "STLContainerTypeResolver.h"
#include "STLVectorDescriptor.h"

USING_NAMESPACE

template<>
TypeDescriptor* STLContainerTypeResolver::GetSTDVectorTypeDescriptor<int>(std::vector<int, std::allocator<int>>*)
{
	static STLVectorDescriptor vectorDescriptor((int*)nullptr);
	return &vectorDescriptor;
}

template<>
TypeDescriptor* STLContainerTypeResolver::GetSTDVectorTypeDescriptor<double>(std::vector<double, std::allocator<double>>*)
{
	static STLVectorDescriptor vectorDescriptor((double*)nullptr);
	return &vectorDescriptor;
}

template<>
TypeDescriptor* STLContainerTypeResolver::GetSTDVectorTypeDescriptor<char>(std::vector<char, std::allocator<char>>*)
{
	static STLVectorDescriptor vectorDescriptor((char*)nullptr);
	return &vectorDescriptor;
}

template<>
TypeDescriptor* STLContainerTypeResolver::GetSTDVectorTypeDescriptor<int>(std::vector<int, std::allocator<int>>*);
template<>
TypeDescriptor* STLContainerTypeResolver::GetSTDVectorTypeDescriptor<double>(std::vector<double, std::allocator<double>>*);
template<>
TypeDescriptor* STLContainerTypeResolver::GetSTDVectorTypeDescriptor<char>(std::vector<char, std::allocator<char>>*);