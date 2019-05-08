#pragma once
#include "TypeDescriptor.h"

BEGIN_NAMESPACE

template <typename PrimitiveType>
class PrimitiveDataTypeDescriptor : public TypeDescriptor
{
public:
	PrimitiveDataTypeDescriptor() : TypeDescriptor((PrimitiveType*)nullptr) {}

	virtual void DumpToOStream(const void* obj, std::ostream& outStream, const size_t indentLevel = 0) const override
	{
		outStream << GetTypeName() << "{" << *(const PrimitiveType*)obj << "}" << std::endl;
	}
};

END_NAMESPACE