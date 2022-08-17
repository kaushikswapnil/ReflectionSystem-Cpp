#include "ClassDescriptor.h"
#include <iostream>

USING_NAMESPACE

void ClassDescriptor::DumpToOStream( BytePointer const obj, std::ostream& outStream, const size_t indentLevel) const
{
	//#TODO Change field descriptor so that we can simply call dump on the fields
	outStream << GetTypeName() << " ";
	if (!GetMembers().empty())
	{
		outStream << std::endl << std::string(4 * (indentLevel), ' ') << "{" << std::endl;
		for (const Field& member : m_Members)
		{
			outStream << std::string(4 * (indentLevel + 1), ' ');
			BytePointer const member_ptr = obj + member.GetFieldOffset();
			member.DumpToOStream(member_ptr, outStream, indentLevel + 1);
		}

		outStream << std::string(4 * indentLevel, ' ') << "}" << std::endl;
	}
	else
	{
		outStream << "{ }";
	}
}
