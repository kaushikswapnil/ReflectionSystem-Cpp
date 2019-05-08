#pragma once
#include "TypeResolver.h"
#include "SystemMacros.h"
#include "ClassDescriptor.h"
#include <stddef.h>

#define REFLECT() \
	friend class SCOPE_NAMESPACE::DefaultResolver; \
	static SCOPE_NAMESPACE::ClassDescriptor Reflection; \
	static void InitReflection(SCOPE_NAMESPACE::ClassDescriptor*);

#define REFLECT_BEGIN(_Type) \
	SCOPE_NAMESPACE::ClassDescriptor _Type::Reflection{_Type::InitReflection}; \
	void _Type::InitReflection(SCOPE_NAMESPACE::ClassDescriptor* typeDesc) \
	{ \
		using type = _Type; \
		typeDesc->SetTypeName(typeid(type).name()); \
		typeDesc->SetSize(sizeof(type)); \

#define REFLECT_MEMBER(_Name) typeDesc->m_Members.push_back(SCOPE_NAMESPACE::Field(#_Name, &type::_Name, offsetof(type, _Name)));

#define REFLECT_END() \
	}