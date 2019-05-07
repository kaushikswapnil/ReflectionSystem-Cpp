#pragma once
#include "TypeDescriptor.h"

BEGIN_NAMESPACE

class IntDescriptor : public TypeDescriptor
{
public:
	IntDescriptor() : TypeDescriptor((int*)nullptr) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

class DoubleDescriptor : public TypeDescriptor
{
public:
	DoubleDescriptor() : TypeDescriptor((double*)nullptr) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

class FloatDescriptor : public TypeDescriptor
{
public:
	FloatDescriptor() : TypeDescriptor((float*)nullptr) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

class CharDescriptor : public TypeDescriptor
{
public:
	CharDescriptor() : TypeDescriptor((char*)nullptr) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

class STDStringDescriptor : public TypeDescriptor
{
public:
	STDStringDescriptor() : TypeDescriptor((std::string*)nullptr) {}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

END_NAMESPACE