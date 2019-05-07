#pragma once
#include "TypeDescriptor.h"
#include "SystemMacros.h"
#include <vector>

BEGIN_NAMESPACE

class StructDescriptor :
	public TypeDescriptor
{
public:
	struct Member
	{
		const char* m_Name;
		size_t m_Offset;
		TypeDescriptor* m_Type;
	};

	std::vector<Member> m_Members;

public:
	StructDescriptor(void(*init)(StructDescriptor*)) : TypeDescriptor("#TODO", 0)
	{
		init(this);
	}

	StructDescriptor(const char* name, size_t size, const std::initializer_list<Member>& init) : TypeDescriptor(name, size), m_Members(init) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

END_NAMESPACE