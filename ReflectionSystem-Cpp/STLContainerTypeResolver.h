#pragma once

#include "SystemMacros.h"
#include "TypeResolverHelper.h"

BEGIN_NAMESPACE

class TypeDescriptor;

class STLContainerTypeResolver
{
private:
	template<typename T>
	struct SupportedSTLContainerTypeFlags
	{
		enum
		{
			IsVector = false,
			HoldsPrimitiveData = false
		};
	};

	template<typename T, typename Alloc>
	struct SupportedSTLContainerTypeFlags<std::vector<T, Alloc>>
	{
		enum
		{
			IsVector = true,
			HoldsPrimitiveData = std::is_fundamental<T>::value
		};
	};

public:
	template<typename T, typename std::enable_if<((SupportedSTLContainerTypeFlags<T>::IsVector == false) || (SupportedSTLContainerTypeFlags<T>::HoldsPrimitiveData == false)), int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor() { static_assert(false, "Cannot obtain type descriptor for this object"); return nullptr; }

	template<typename T, typename std::enable_if<((SupportedSTLContainerTypeFlags<T>::IsVector == true) && (SupportedSTLContainerTypeFlags<T>::HoldsPrimitiveData == true)), int>::type = 0>
	static TypeDescriptor* GetTypeDescriptor() { return GetSTDVectorTypeDescriptor((T*)nullptr); }

private:
	template<typename ItemType>
	static TypeDescriptor* GetSTDVectorTypeDescriptor(std::vector<ItemType>*);
};

END_NAMESPACE