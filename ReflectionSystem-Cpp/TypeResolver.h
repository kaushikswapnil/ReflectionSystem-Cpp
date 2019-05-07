#pragma once
#include <type_traits>

#include "SystemMacros.h"
#include "PrimitiveTypeResolver.h"

BEGIN_NAMESPACE

//#TODO USE MACROS TO ALLOW STORAGE OF THE TYPEDEF IN DEFAULT RESOLVER

class TypeDescriptor;

class DefaultResolver
{
private:
	//This uses substitution failure is not an error (SFINAE), a feature that says if a template argument 
	//in template functions cannot be substituted, then it is not an error, and instead, the overloaded function is discarded
	//Therefore in this case if the template type T does not have a member Reflection, then it cant be substituted 
	//and decltype cannot know its type, hence the value for IsReflected will be the sizeof the return type for whichever function
	//is created
	template <typename T>
	struct IsReflected
	{
		template <typename T>
		static char func(decltype(&T::Reflection));
		template <typename T>
		static int func(...);

		enum { value = (sizeof(func<T>(nullptr)) == sizeof(char)) };
	};

	template<typename T>
	static TypeDescriptor* GetPrimitiveTypeDescriptor()
	{
		return GetPrimitiveTypeResolver().GetTypeDescriptor<T>();
	}

	static PrimitiveTypeResolver& GetPrimitiveTypeResolver();

public:
	//A similar SFINAE is utilized here. enable_if has a member variable called type if 
	//the passed condition is true, otherwise it does not. This allows the correct GetTypeDescriptor 
	// to be created for the templated T.
	template <typename T, typename std::enable_if<IsReflected<T>::value == true, int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		return &T::Reflection;
	}

	//#TODO This function should be able to identify non-primitive non-reflected types eventually, so that it can return a nullptr
	template <typename T, typename std::enable_if<IsReflected<T>::value == false, int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		return GetPrimitiveTypeDescriptor<T>();
	}
};

//Primary type resolver
template<typename T>
class TypeResolver
{
public:
	static TypeDescriptor* GetTypeDescriptor()
	{
		return DefaultResolver::GetTypeDescriptor<T>();
	}

	static unsigned int GetTypeID()
	{
		return TypeResolverHelper::CalculateHashForTypeName(typeid(T).name());
	}
};

END_NAMESPACE