#pragma once
#include "SystemMacros.h"
#include <vector>

BEGIN_NAMESPACE

//======================
//STL Containers
template<typename T>
struct IsSupportedSTLContainer
{
	enum { value = false };
};

//#TODO Check for ItemType support as well
template<typename ItemType, typename Alloc>
struct IsSupportedSTLContainer<std::vector<ItemType, Alloc>>
{
	enum { value = true };
};

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

//END of STLContainers
//=======================

template<typename T>
struct IsPrimitivelyHandledDataType
{
	enum { value = (std::is_fundamental<T>::value || IsSupportedSTLContainer<T>::value) };
};

template<>
struct IsPrimitivelyHandledDataType<std::string>
{
	enum { value = true };
};


END_NAMESPACE