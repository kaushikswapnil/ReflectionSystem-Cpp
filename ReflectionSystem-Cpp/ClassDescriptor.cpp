#include "ClassDescriptor.h"
#include <iostream>

USING_NAMESPACE

void ClassDescriptor::Dump(const void* obj, const size_t indentLevel) const
{
	//#TODO Change field descriptor so that we can simply call dump on the fields
	std::cout << m_TypeName << " {";
	for (const Field& member : m_Members)
	{
		std::cout << std::endl;
		std::cout << std::string(4 * (indentLevel + 1), ' ') << member.GetFieldName() << " = ";
		member.Dump((char*)obj + member.GetFieldOffset(), indentLevel + 1);
	}
	if (!m_Members.empty()) std::cout << std::endl << std::string(4 * indentLevel, ' ');
	std::cout << "}";
}
