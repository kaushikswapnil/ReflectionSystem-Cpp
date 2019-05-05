#pragma once

#define REFLECT() \
	friend struct DefaultResolver; \
	static TypeDescriptor_Struct Reflection; \
	static void InitReflection(TypeDescriptor_Struct*);

#define REFLECT_STRUCT_BEGIN(_Type) \
	TypeDescriptor_Struct _Type::Reflection{_Type::InitReflection}; \
	void _Type::InitReflection(TypeDescriptor_Struct* typeDesc) \ 
	{ \
		using type = _Type;
		typeDesc->m_Name = #_Type; \
		typeDesc->m_Size = sizeof(_Type); \
		typeDesc->m_Members = \
		{

#define REFLECT_STRUCT_MEMBER(_Name) \
			{#_Name, offsetof(type, _Name), TypeResolver<decltype(type::_Name)>::GetTypeDescriptor()},

#define REFLECT_STRUCT_END() \
		}; \
	} 