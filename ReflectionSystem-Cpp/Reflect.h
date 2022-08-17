#pragma once
#include "TypeResolver.h"
#include "SystemMacros.h"
#include "ClassDescriptor.h"

BEGIN_NAMESPACE

template <typename T, typename std::enable_if<HasSuper<T>::value == true, int>::type = 0>
static void InitializeSuperValue(ClassDescriptor* class_desc)
{
	class_desc->SetBaseClassDescriptor(TypeResolver<T::Super>::GetClassDescriptor());
}

template <typename T, typename std::enable_if<HasSuper<T>::value == false, int>::type = 0>
static void InitializeSuperValue(ClassDescriptor* class_desc)
{
	class_desc->SetBaseClassDescriptor(nullptr);
}

END_NAMESPACE

#define REFLECT() \
	friend class SCOPE_NAMESPACE::DefaultResolver; \
	friend class SCOPE_NAMESPACE::TypeDescriptor; \
	friend class SCOPE_NAMESPACE::ClassDescriptor; \
	friend class SCOPE_NAMESPACE::Field; \
	static SCOPE_NAMESPACE::ClassDescriptor Reflection; \
	static void InitReflection(SCOPE_NAMESPACE::ClassDescriptor*); \
	void ReflectSelfToStream(); \
	virtual SCOPE_NAMESPACE::ClassDescriptor* const GetClassDescriptor();

#define REFLECT_INHERITED(_Super) \
	typedef _Super Super; \
	REFLECT()

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
		SCOPE_NAMESPACE::InitializeSuperValue<type>(typeDesc); \
		std::vector<SCOPE_NAMESPACE::Field*> members;

#define REFLECT_MEMBER(_Name) \
		members.push_back(new SCOPE_NAMESPACE::FieldImpl<decltype(type::_Name), type>(#_Name, &type::_Name, default_instance_ptr)); 

#define REFLECT_END() \
		typeDesc ->SetMembers(members); \
	}