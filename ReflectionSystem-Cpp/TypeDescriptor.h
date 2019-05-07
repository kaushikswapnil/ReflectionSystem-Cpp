#pragma once
#include <string>
#include "SystemMacros.h"

BEGIN_NAMESPACE
class TypeDescriptor
{
public:
	TypeDescriptor(const char* typeName, const size_t size) : m_TypeName(typeName), m_Size(size) {}
	TypeDescriptor(const std::string& typeName, const size_t size) : m_TypeName(typeName), m_Size(size) {}
	template<typename ItemType>
	TypeDescriptor(ItemType*) : TypeDescriptor(typeid(std::remove_reference<ItemType>::type).name(), sizeof(std::remove_reference<ItemType>::type)) {}
	virtual ~TypeDescriptor() {}

	virtual void Dump(const void* obj, const size_t indentLevel = 0) const = 0;

	virtual const std::string& GetTypeName() const { return m_TypeName; }
	void SetTypeName(const char* value) { m_TypeName = value; }
	void SetTypeName(const std::string& value) { m_TypeName = value; }

	virtual const size_t GetSize() const { return m_Size; }
	void SetSize(const size_t value) { m_Size = value; } //#TODO Eventually remove this. Size should not be resettable

protected:
	std::string m_TypeName;
	size_t m_Size;
};
END_NAMESPACE

