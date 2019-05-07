#include "Field.h"
#include "TypeDescriptor.h"

USING_NAMESPACE

Field::~Field()
{
}

void ReflectionSystem::Field::Dump(const void* obj, const size_t indentLevel /*= 0*/) const
{
	m_FieldTypeDescriptor->Dump(obj, indentLevel);
}
