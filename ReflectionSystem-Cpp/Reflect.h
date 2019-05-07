#pragma once
#include "TypeResolver.h"
#include <cstddef>
#include "SystemMacros.h"
#include "StructDescriptor.h"

#define REFLECT() \
	friend class SCOPE_NAMESPACE::DefaultResolver; \
	static SCOPE_NAMESPACE::StructDescriptor Reflection; \
	static void InitReflection(SCOPE_NAMESPACE::StructDescriptor*);

#define REFLECT_STRUCT_BEGIN(_Type) \
	SCOPE_NAMESPACE::StructDescriptor _Type::Reflection{_Type::InitReflection}; \
	void _Type::InitReflection(SCOPE_NAMESPACE::StructDescriptor* typeDesc) \
	{ \
		using type = _Type; \
		typeDesc->SetTypeName(#_Type); \
		typeDesc->SetSize(sizeof(_Type)); \
		typeDesc->m_Members = \
		{

#define REFLECT_STRUCT_MEMBER(_Name) \
			{#_Name, offsetof(type, _Name), SCOPE_NAMESPACE::TypeResolver<decltype(type::_Name)>::GetTypeDescriptor()},

#define REFLECT_STRUCT_END() \
		}; \
	} 