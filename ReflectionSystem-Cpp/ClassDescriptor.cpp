#include "ClassDescriptor.h"
#include <iostream>

USING_NAMESPACE

void ClassDescriptor::DumpToOStream(const void* obj, std::ostream& outStream, const size_t indentLevel) const
{
	//#TODO Change field descriptor so that we can simply call dump on the fields
	outStream << GetTypeName() << " ";
	if (!m_Members.empty())
	{
		outStream << std::endl << std::string(4 * (indentLevel), ' ') << "{" << std::endl;
		for (const Field& member : m_Members)
		{
			outStream << std::string(4 * (indentLevel + 1), ' ');
			member.DumpToOStream((char*)obj + member.GetFieldOffset(), outStream, indentLevel + 1);
		}

		outStream << std::string(4 * indentLevel, ' ') << "}" << std::endl;
	}
	else
	{
		outStream << "{ }";
	}
}
