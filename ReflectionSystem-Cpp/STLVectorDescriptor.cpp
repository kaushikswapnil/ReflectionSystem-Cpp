#include "STLVectorDescriptor.h"
#include <iostream>

USING_NAMESPACE

void STLVectorDescriptor::Dump(const void* obj, const size_t indentLevel) const
{
	const size_t numItems = GetContainerSize(obj);
	std::cout << GetTypeName() << "{";
	for (size_t iter = 0; iter < numItems; ++iter)
	{
		std::cout << std::endl;
		std::cout << std::string(4 * (indentLevel + 1), ' ') << "[" << iter << "] ";
		m_ItemTypeDesc->Dump(GetContainerItem(obj, iter), indentLevel + 1);
	}
	if (numItems != 0) std::cout << std::endl << std::string(4 * (indentLevel), ' ');
	std::cout << "}";
}
