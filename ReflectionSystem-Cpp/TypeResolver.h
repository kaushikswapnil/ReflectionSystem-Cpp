#pragma once
#include <type_traits>
#include <string>
#include <vector>
#include "PrimitiveTypeDescriptors.h"
#include "TypeDescriptor_STDVector.h"

struct DefaultResolver
{
	//This uses substitution failure is not an error (SFINAE), a feature that says if a template argument 
	//in template functions cannot be substituted, then it is not an error, and instead, the overloaded function is discarded
	//Therefore in this case if the template type T does not have a member Reflection, then it cant be substituted 
	//and decltype cannot know its type, hence the value for IsReflected will be the sizeof the return type for whichever function
	//is created
	template <typename T> 
	static char func(decltype(&T::Reflection));
	template <typename T> 
	static int func(...);
	template <typename T>
	struct IsReflected
	{
		enum { value = (sizeof(func<T>(nullptr)) == sizeof(char)) };
	};

	template<typename T> 
	static TypeDescriptor* GetPrimitiveTypeDescriptor();

	template <typename T, typename std::enable_if<IsReflected<T>::value, int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor()
	{
		return &T::Reflection;
	}

	//#TODO This function should be able to identify non-primitive non-reflected types eventually, so that it can return a nullptr
	template <typename T, typename std::enable_if<!IsReflected<T>::value, int>::type = 0>
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
};

//#TODO THIS IS A HORRIBLE THING TO DO
struct TypeDescriptor_STDVector : public TypeDescriptor
{
	TypeDescriptor* m_ItemTypeDesc;
	size_t(*GetSize)(const void*);
	const void* (*GetItem)(const void*, size_t);

	template<typename ItemType>
	TypeDescriptor_STDVector(ItemType*) : TypeDescriptor("std::vector<>", sizeof(std::vector<ItemType>)), m_ItemTypeDesc(TypeResolver<ItemType>::GetTypeDescriptor())
	{
		GetSize = [](const void* voidVectorPtr) -> size_t
		{
			const auto& vec = *(static_cast<const std::vector<ItemType>*>(voidVectorPtr));
			return vec.size();
		};

		GetItem = [](const void* voidVecPtr, size_t index) -> const void*
		{
			const auto& vec = *(static_cast<const std::vector<ItemType>*>(voidVecPtr));
			return &vec[index];
		};
	}

	virtual std::string GetTypeName() const override
	{
		return std::string("std::vector<") + m_ItemTypeDesc->GetTypeName() + ">";
	}

	virtual void Dump(const void* obj, const size_t indentLevel) const override
	{
		const size_t numItems = GetSize(obj);
		std::cout << GetTypeName()<< "{";
		for (size_t iter = 0; iter < numItems; ++iter)
		{
			std::cout << std::endl;
			std::cout << std::string(4 * (indentLevel + 1), ' ') << "[" << iter << "] ";
			m_ItemTypeDesc->Dump(GetItem(obj, iter), indentLevel + 1);
		}
		if (numItems != 0) std::cout << std::endl << std::string(4 * (indentLevel), ' ');
		std::cout << "}";
	}
};

// Partially specialize TypeResolver<> for std::vectors
template<typename T>
class TypeResolver<std::vector<T>>
{
public:
	static TypeDescriptor* GetTypeDescriptor()
	{
		static TypeDescriptor_STDVector typeDesc{ (T*) nullptr };
		return &typeDesc;
	}
};