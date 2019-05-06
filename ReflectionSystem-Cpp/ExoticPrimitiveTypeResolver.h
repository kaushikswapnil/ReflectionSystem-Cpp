#pragma once

#include "SystemMacros.h"
#include "TypeResolverHelper.h"

BEGIN_NAMESPACE

class TypeDescriptor;

class ExoticPrimitiveTypeResolver
{
private:
	template<typename T>
	struct ExoticPrimitiveTypeFlags
	{
		enum
		{
			IsVector = false,
			HoldsPrimitiveData = false
		};
	};

	template<typename T, typename Alloc>
	struct ExoticPrimitiveTypeFlags<std::vector<T, Alloc>>
	{
		enum
		{
			IsVector = true,
			HoldsPrimitiveData = std::is_fundamental<T>::value
		};
	};

public:
	template<typename T, typename std::enable_if<((ExoticPrimitiveTypeFlags<T>::IsVector == false) || (ExoticPrimitiveTypeFlags<T>::HoldsPrimitiveData == false)), int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor() { static_assert(false, "Cannot obtain type descriptor for this object"); return nullptr; }

	template<typename T, typename std::enable_if<((ExoticPrimitiveTypeFlags<T>::IsVector == true) && (ExoticPrimitiveTypeFlags<T>::HoldsPrimitiveData == true)), int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor() { return TypeResolverHelper::GetSTDVectorTypeDescriptor((T*)nullptr); }

private:
	template<typename T>
	static TypeDescriptor* GetVectorTypeDescriptor() { return TypeResolverHelper::GetSTDVectorTypeDescriptor<T>(); }
};

END_NAMESPACE