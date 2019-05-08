#pragma once
#include "TypeDescriptor.h"
#include "SystemMacros.h"
#include <vector>
#include "Field.h"

BEGIN_NAMESPACE

class ClassDescriptor :
	public TypeDescriptor
{
public:
	std::vector<Field> m_Members;

public:
	ClassDescriptor(void(*init)(ClassDescriptor*)) : TypeDescriptor(), m_Members()
	{
		init(this);
	}

	virtual void DumpToOStream(const void* obj, std::ostream& outStream, const size_t indentLevel = 0) const override;
};

END_NAMESPACE