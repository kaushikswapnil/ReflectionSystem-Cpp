#include "ClassDescriptor.h"
#include <iostream>

USING_NAMESPACE

void ClassDescriptor::DumpToOStream( BytePointer const obj, std::ostream& outStream, const size_t indentLevel) const
{
	//#TODO Change field descriptor so that we can simply call dump on the fields
	outStream << GetTypeName() << " ";
	const bool has_parent_members = (HasBaseClassDescriptor() && !GetBaseClassDescriptor()->GetMembers().empty());
	if (!GetMembers().empty() || has_parent_members)
	{
		outStream << std::endl << std::string(4 * (indentLevel), ' ') << "{" << std::endl;

		if (has_parent_members)
		{
			for (const Field* field : GetBaseClassDescriptor()->GetMembers())
			{
				outStream << std::string(4 * (indentLevel + 1), ' ');
				outStream << "{i} ";
				field->DumpToOStream(obj, outStream, indentLevel + 1);
			}
		}

		for (const Field* field : m_Members)
		{
			outStream << std::string(4 * (indentLevel + 1), ' ');
			field->DumpToOStream(obj, outStream, indentLevel + 1);
		}

		outStream << std::string(4 * indentLevel, ' ') << "}" << std::endl;
	}
	else
	{
		outStream << "{ }";
	}
}
