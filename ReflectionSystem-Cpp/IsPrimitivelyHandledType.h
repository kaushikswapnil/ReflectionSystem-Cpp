#pragma once
#include "SystemMacros.h"

BEGIN_NAMESPACE

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