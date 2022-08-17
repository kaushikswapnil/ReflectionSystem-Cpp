#pragma once
#include <string>
#include "SystemMacros.h"

BEGIN_NAMESPACE

typedef uint8_t* BytePointer;

class TypeDescriptor
{
protected: 
	//These constructors are used by the derived classes to allow for Init style construction
	TypeDescriptor() : m_TypeName(), m_TypeSize(0) {} //Used for init style creations
	TypeDescriptor(const char* typeName, const size_t size) : m_TypeName(typeName), m_TypeSize(size) {}
	TypeDescriptor(const std::string& typeName, const size_t size) : m_TypeName(typeName), m_TypeSize(size) {}
public:
	template<typename ItemType>
	TypeDescriptor(ItemType*) : TypeDescriptor(typeid(std::remove_reference<ItemType>::type).name(), sizeof(std::remove_reference<ItemType>::type)) {}
	virtual ~TypeDescriptor() {}

	virtual void DumpToOStream(BytePointer const obj, std::ostream& outStream, const size_t indentLevel = 0) const = 0;

	virtual const std::string& GetTypeName() const { return m_TypeName; }

	virtual const size_t GetTypeSize() const { return m_TypeSize; }

	//These functions are used by derived classes to facilitate init style creations
	//#TODO Eventually move to protected
	void SetTypeSize(const size_t value) { m_TypeSize = value; } 
	void SetTypeName(const char* value) { m_TypeName = value; }
	void SetTypeName(const std::string& value) { m_TypeName = value; }

protected:
	std::string m_TypeName;
	size_t m_TypeSize;
};
END_NAMESPACE

