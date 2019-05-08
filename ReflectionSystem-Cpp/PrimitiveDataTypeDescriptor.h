#pragma once
#include "TypeDescriptor.h"
#include <iostream>

BEGIN_NAMESPACE

template <typename PrimitiveType>
class PrimitiveDataTypeDescriptor : public TypeDescriptor
{
public:
	PrimitiveDataTypeDescriptor() : TypeDescriptor((PrimitiveType*)nullptr) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override
	{
		std::cout << GetTypeName() << "{" << *(const PrimitiveType*)obj << "}";
	}
};

END_NAMESPACE