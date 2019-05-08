#include "Field.h"
#include "TypeDescriptor.h"

USING_NAMESPACE

void ReflectionSystem::Field::Dump(const void* obj, const size_t indentLevel /*= 0*/) const
{
	m_FieldTypeDescriptor->Dump(obj, indentLevel);
}
