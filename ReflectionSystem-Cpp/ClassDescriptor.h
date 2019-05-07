#pragma once
#include "TypeDescriptor.h"
#include "SystemMacros.h"
#include <vector>
#include "Field.h"

BEGIN_NAMESPACE

class ClassDescriptor :
	public TypeDescriptor
{
public:
	std::vector<Field> m_Members;

public:
	ClassDescriptor(void(*init)(ClassDescriptor*)) : TypeDescriptor()
	{
		init(this);
	}

	//StructDescriptor(const char* name, size_t size, const std::initializer_list<Field>& init) : TypeDescriptor(name, size), m_Members(init) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

END_NAMESPACE