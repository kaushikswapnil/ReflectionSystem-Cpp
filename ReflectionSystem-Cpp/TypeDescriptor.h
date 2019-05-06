#pragma once
#include <string>
#include "SystemMacros.h"

BEGIN_NAMESPACE
class TypeDescriptor
{
public:
	TypeDescriptor(const char* name, const size_t size) : m_Name(name), m_Size(size) {}
	virtual ~TypeDescriptor() {}
	virtual std::string GetTypeName() const { return m_Name; }
	virtual void Dump(const void* obj, const size_t indentLevel = 0) const = 0;

	const char* m_Name;
	size_t m_Size;
};
END_NAMESPACE

