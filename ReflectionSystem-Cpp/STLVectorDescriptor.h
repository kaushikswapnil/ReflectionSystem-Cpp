#pragma once
 
#include "STLContainerDescriptor.h"
#include <vector>
#include "TypeResolver.h"

BEGIN_NAMESPACE

class STLVectorDescriptor : public STLContainerDescriptor
{
	TypeDescriptor* m_ItemTypeDesc;
	size_t(*GetSize)(const void*);
	const void* (*GetItem)(const void*, size_t);

public:
	template<typename ItemType>
	STLVectorDescriptor(ItemType*) : STLContainerDescriptor("std::vector<>", sizeof(std::vector<ItemType>)), m_ItemTypeDesc(TypeResolver<ItemType>::GetTypeDescriptor())
	{
		GetSize = [](const void* voidVectorPtr) -> size_t
		{
			const auto& vec = *(static_cast<const std::vector<ItemType>*>(voidVectorPtr));
			return vec.size();
		};

		GetItem = [](const void* voidVecPtr, size_t index) -> const void*
		{
			const auto& vec = *(static_cast<const std::vector<ItemType>*>(voidVecPtr));
			return &vec[index];
		};
	}

	virtual std::string GetTypeName() const override;

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

END_NAMESPACE