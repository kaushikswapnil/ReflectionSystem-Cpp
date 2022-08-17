#pragma once
#include "TypeResolver.h"
#include <stddef.h>

BEGIN_NAMESPACE

class Field
{
public:
	template<typename FieldType, typename OwnerType>
	Field(const char* fieldName, FieldType OwnerType::*fieldPtr, OwnerType* default_instance) : 
		m_FieldName(fieldName), 
		m_FieldOffset(offsetof(OwnerType, *fieldPtr)), //#TODO Obtain offset automatically
		m_FieldTypeDescriptor(TypeResolver<FieldType>::GetTypeDescriptor()), 
		m_OwnerTypeDescriptor(TypeResolver<OwnerType>::GetClassDescriptor()) 
		{
			FieldType* field_type_instance_ptr = &(default_instance->*fieldPtr);
			std::intptr_t field_offset = reinterpret_cast<BytePointer>(field_type_instance_ptr) - reinterpret_cast<BytePointer>(default_instance);
			if (field_offset != m_FieldOffset)
			{
				m_FieldOffset = field_offset;
			}
		}
	virtual ~Field() {};

	const std::string& GetFieldName() const { return m_FieldName; }
	void SetFieldName(std::string val) { m_FieldName = val; }

	const std::intptr_t GetFieldOffset() const { return m_FieldOffset; }
	void SetFieldOffset(std::intptr_t val) { m_FieldOffset = val; }

	const TypeDescriptor* GetFieldTypeDescriptor() const { return m_FieldTypeDescriptor; }
	const ClassDescriptor* GetOwnerTypeDescriptor() const { return m_OwnerTypeDescriptor; }

	void DumpToOStream(const BytePointer obj, std::ostream& outStream, const size_t indentLevel = 0) const;

protected:
	std::string m_FieldName;
	std::intptr_t m_FieldOffset;
	TypeDescriptor* m_FieldTypeDescriptor;
	ClassDescriptor* m_OwnerTypeDescriptor;
};

END_NAMESPACE