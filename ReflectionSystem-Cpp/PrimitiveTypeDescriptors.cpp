#include "PrimitiveTypeDescriptors.h"

void TypeDescriptor_Int::Dump(const void* obj, const size_t indentLevel) const
{
	std::cout << GetTypeName() << "{" << *(const int*)obj << "}";
}

void TypeDescriptor_Double::Dump(const void* obj, const size_t indentLevel) const
{
	std::cout << GetTypeName() << "{" << *(const double*)obj << "}";
}

void TypeDescriptor_STDString::Dump(const void* obj, const size_t indentLevel) const
{
	std::cout << "std::string{\"" << *(const std::string*) obj << "\"}";
}
