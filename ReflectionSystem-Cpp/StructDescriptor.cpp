#include "StructDescriptor.h"
#include <iostream>

USING_NAMESPACE

void StructDescriptor::Dump(const void* obj, const size_t indentLevel) const
{
	std::cout << m_TypeName << " {";
	for (const Member& member : m_Members)
	{
		std::cout << std::endl;
		std::cout << std::string(4 * (indentLevel + 1), ' ') << member.m_Name << " = ";
		member.m_Type->Dump((char*)obj + member.m_Offset, indentLevel + 1);
	}
	if (!m_Members.empty()) std::cout << std::endl << std::string(4 * indentLevel, ' ');
	std::cout << "}";
}
