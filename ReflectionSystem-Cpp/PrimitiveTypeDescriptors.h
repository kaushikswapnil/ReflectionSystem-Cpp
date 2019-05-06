#pragma once
#include "TypeDescriptor.h"
#include <iostream>

BEGIN_NAMESPACE

class IntDescriptor : public TypeDescriptor
{
public:
	IntDescriptor() : TypeDescriptor("int", sizeof(int)) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

class DoubleDescriptor : public TypeDescriptor
{
public:
	DoubleDescriptor() : TypeDescriptor("double", sizeof(double)) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

class FloatDescriptor : public TypeDescriptor
{
public:
	FloatDescriptor() : TypeDescriptor("float", sizeof(float)) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

class CharDescriptor : public TypeDescriptor
{
public:
	CharDescriptor() : TypeDescriptor("char", sizeof(char)) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

class STDStringDescriptor : public TypeDescriptor
{
public:
	STDStringDescriptor() : TypeDescriptor("std::string", sizeof(std::string)) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

END_NAMESPACE