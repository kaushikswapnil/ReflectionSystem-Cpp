#pragma once
#include "SystemMacros.h"

BEGIN_NAMESPACE

template<typename T>
struct IsPrimitivelyHandledDataType
{
	enum { value = std::is_fundamental<T>::value };
};

template<>
struct IsPrimitivelyHandledDataType<std::string>
{
	enum { value = true };
};

END_NAMESPACE