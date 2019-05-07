#include "PrimitiveTypeDescriptors.h"
#include <iostream>

USING_NAMESPACE

void IntDescriptor::Dump(const void* obj, const size_t indentLevel) const
{
	std::cout << GetTypeName() << "{" << *(const int*)obj << "}";
}

void DoubleDescriptor::Dump(const void* obj, const size_t indentLevel) const
{
	std::cout << GetTypeName() << "{" << *(const double*)obj << "}";
}

void FloatDescriptor::Dump(const void* obj, const size_t indentLevel) const
{
	std::cout << GetTypeName() << "{" << *(const float*)obj << "}";
}

void CharDescriptor::Dump(const void* obj, const size_t indentLevel) const
{
	std::cout << GetTypeName() << "{" << *(const char*)obj << "}";
}

void STDStringDescriptor::Dump(const void* obj, const size_t indentLevel) const
{
	std::cout << "std::string{\"" << *(const std::string*) obj << "\"}";
}
