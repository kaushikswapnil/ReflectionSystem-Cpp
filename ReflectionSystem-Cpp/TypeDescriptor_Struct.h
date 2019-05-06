#pragma once
#include "TypeDescriptor.h"
#include <vector>

struct TypeDescriptor_Struct : TypeDescriptor
{
	struct Member
	{
		const char* m_Name;
		size_t m_Offset;
		TypeDescriptor* m_Type;
	};

	std::vector<Member> m_Members;

	TypeDescriptor_Struct(void(*init)(TypeDescriptor_Struct*)) : TypeDescriptor(nullptr, 0)
	{
		init(this);
	}

	TypeDescriptor_Struct(const char* name, size_t size, const std::initializer_list<Member>& init) : TypeDescriptor(name, size), m_Members(init) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};
