#pragma once
#include "TypeDescriptor.h"
#include <string>

BEGIN_NAMESPACE

template <typename PrimitiveType>
class PrimitiveDataTypeDescriptor : public TypeDescriptor
{
public:
	PrimitiveDataTypeDescriptor() : TypeDescriptor((PrimitiveType*)nullptr) {}

	virtual void DumpToOStream(const void* obj, std::ostream& outStream, const size_t indentLevel = 0) const override
	{
		PrimitiveType val = *((const PrimitiveType*)obj);
		const std::string value_str = std::to_string(val);
		outStream << GetTypeName() << "{" << value_str << "}" << std::endl;
	}
};

template<>
class PrimitiveDataTypeDescriptor<std::string> : public TypeDescriptor
{
public:
	PrimitiveDataTypeDescriptor() : TypeDescriptor((std::string*)nullptr) {}

	virtual void DumpToOStream(const void* obj, std::ostream& outStream, const size_t indentLevel = 0) const override
	{
		std::string val = *((const std::string*)obj);
		outStream << GetTypeName() << "{" << val << "}" << std::endl;
	}
};

END_NAMESPACE