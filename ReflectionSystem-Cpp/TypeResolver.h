#pragma once

//Fetches type descriptors for primitive classes
template <typename T>
TypeDescriptor* GetPrimitiveTypeDescriptor();

struct DefaultResolver
{
	template <typename T> static char func(decltype(&T::Reflection));
	template <typename T> static int func(...);
	template <typename T>
	struct IsReflected
	{
		enum { value = (sizeof(func<T>(nullptr)) == sizeof(char)) };
	};

	template <typename T, typename std::enable_if<IsReflected<T>::value, int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor
	{
		return T::Reflection;
	}

		template <typename T, typename std::enable_if<!IsReflected<T>::value, int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor
	{
		return GetPrimitiveTypeDescriptor();
	}
};

//Primary type resolver
template<typename T>
struct TypeResolver
{
	static TypeDescriptor* GetTypeDescriptor()
	{
		return DefaultResolver::GetTypeDescriptor<T>();
	}
};

// Partially specialize TypeResolver<> for std::vectors:
template <typename T>
class TypeResolver<std::vector<T>> 
{
public:
	static TypeDescriptor* get() {
		static TypeDescriptor_STDVector typeDesc{ (T*) nullptr };
		return &typeDesc;
	}
};