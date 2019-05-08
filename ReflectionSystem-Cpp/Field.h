#pragma once
#include "TypeResolver.h"
#include <stddef.h>

BEGIN_NAMESPACE

class Field
{
public:
	template<typename FieldType, typename OwnerType>
	Field(const char* fieldName, FieldType OwnerType::*fieldPtr) : 
		m_FieldName(fieldName), 
		m_FieldOffset(offsetof(OwnerType, *fieldPtr)), //#TODO Obtain offset automatically
		m_FieldTypeDescriptor(TypeResolver<FieldType>::GetTypeDescriptor()), 
		m_OwnerTypeDescriptor(TypeResolver<OwnerType>::GetTypeDescriptor()) 
		{}
	virtual ~Field() {};

	const std::string& GetFieldName() const { return m_FieldName; }
	void SetFieldName(std::string val) { m_FieldName = val; }

	const size_t GetFieldOffset() const { return m_FieldOffset; }
	void SetFieldOffset(size_t val) { m_FieldOffset = val; }

	const TypeDescriptor* GetFieldTypeDescriptor() const { return m_FieldTypeDescriptor; }
	const TypeDescriptor* GetOwnerTypeDescriptor() const { return m_OwnerTypeDescriptor; }

	void Dump(const void* obj, const size_t indentLevel = 0) const;

protected:
	std::string m_FieldName;
	size_t m_FieldOffset;
	TypeDescriptor* m_FieldTypeDescriptor;
	TypeDescriptor* m_OwnerTypeDescriptor;
};

END_NAMESPACE