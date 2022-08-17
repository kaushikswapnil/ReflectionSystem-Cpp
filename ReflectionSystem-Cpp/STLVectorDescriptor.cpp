#include "STLVectorDescriptor.h"
#include <iostream>

USING_NAMESPACE

void STLVectorDescriptor::DumpToOStream(BytePointer const obj, std::ostream& outStream, const size_t indentLevel) const
{
	const size_t numItems = GetContainerSize(obj);
	outStream << GetTypeName();
	if (numItems > 0)
	{
		outStream << std::endl << std::string(4 * (indentLevel), ' ') << "{" << std::endl;
		for (size_t iter = 0; iter < numItems; ++iter)
		{
			outStream << std::string(4 * (indentLevel + 1), ' ') << "[" << iter << "] ";
			m_ItemTypeDesc->DumpToOStream(GetContainerItem(obj, iter), outStream, indentLevel + 1);
		}
		outStream << std::string(4* (indentLevel), ' ') << "}";
	}
	else
	{
		outStream << "{ }";
	}
	outStream << std::endl;
}
