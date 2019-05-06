#pragma once
#include "TypeDescriptor.h"
#include <iostream>

struct TypeDescriptor_Int : public TypeDescriptor
{
	TypeDescriptor_Int() : TypeDescriptor("int", sizeof(int)) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

struct TypeDescriptor_Double : public TypeDescriptor
{
	TypeDescriptor_Double() : TypeDescriptor("double", sizeof(double)) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

struct TypeDescriptor_STDString : public TypeDescriptor
{
	TypeDescriptor_STDString() : TypeDescriptor("std::string", sizeof(std::string)) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};
