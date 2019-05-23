#pragma once
#include "TypeDescriptor.h"
#include "SystemMacros.h"
#include <vector>
#include "Field.h"

BEGIN_NAMESPACE

class ClassDescriptor :	public TypeDescriptor
{
public:
	ClassDescriptor(void(*init)(ClassDescriptor*)) : TypeDescriptor(), m_Members(), m_BaseClassDescriptor(nullptr), m_DerivedClassDescriptors()
	{
		init(this);
	}

	virtual void DumpToOStream(const void* obj, std::ostream& outStream, const size_t indentLevel = 0) const override;
	
	const std::vector<ReflectionSystem::Field>& GetMembers() const { return m_Members; }
	void SetMembers(const std::vector<ReflectionSystem::Field>& val) { m_Members = val; }

private:
	std::vector<Field> m_Members;
	ClassDescriptor* m_BaseClassDescriptor;
	std::vector<ClassDescriptor*> m_DerivedClassDescriptors;
};

END_NAMESPACE