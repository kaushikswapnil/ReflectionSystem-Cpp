#include "Field.h"
#include "TypeDescriptor.h"

USING_NAMESPACE

void ReflectionSystem::Field::DumpToOStream(const void* obj, std::ostream& outStream, const size_t indentLevel /*= 0*/) const
{
	outStream << GetFieldName() << " = ";
	m_FieldTypeDescriptor->DumpToOStream(obj, outStream, indentLevel + 1);
}
