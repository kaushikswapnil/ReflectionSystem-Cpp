#pragma once
#include "TypeResolver.h"
#include "SystemMacros.h"
#include "ClassDescriptor.h"

#define REFLECT() \
	friend class SCOPE_NAMESPACE::DefaultResolver; \
	static SCOPE_NAMESPACE::ClassDescriptor Reflection; \
	static void InitReflection(SCOPE_NAMESPACE::ClassDescriptor*); \
	virtual SCOPE_NAMESPACE::ClassDescriptor* const GetClassDescriptor();

#define REFLECT_BEGIN(_Type) \
	SCOPE_NAMESPACE::ClassDescriptor* const _Type::GetClassDescriptor() { return &_Type::Reflection; } \
	SCOPE_NAMESPACE::ClassDescriptor _Type::Reflection{_Type::InitReflection}; \
	void _Type::InitReflection(SCOPE_NAMESPACE::ClassDescriptor* typeDesc) \
	{ \
		using type = _Type; \
		type default_instance; \
		type* default_instance_ptr = &default_instance; \
		typeDesc->SetTypeName(typeid(type).name()); \
		typeDesc->SetTypeSize(sizeof(type)); \
		\
		std::vector<SCOPE_NAMESPACE::Field> members;

#define REFLECT_MEMBER(_Name) \
		members.push_back(SCOPE_NAMESPACE::Field(#_Name, &type::_Name, default_instance_ptr)); 

#define REFLECT_END() \
		typeDesc ->SetMembers(members); \
	}