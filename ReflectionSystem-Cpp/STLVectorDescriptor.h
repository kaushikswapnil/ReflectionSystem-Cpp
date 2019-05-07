#pragma once
 
#include "STLContainerDescriptor.h"
#include <vector>
#include <memory>
#include "TypeResolver.h"

BEGIN_NAMESPACE

class STLVectorDescriptor : public STLContainerDescriptor
{
	TypeDescriptor* m_ItemTypeDesc;
	size_t(*GetSize)(const void*);
	const void* (*GetItem)(const void*, size_t);

public:
	template<typename ItemType, typename Alloc = std::allocator<ItemType>>  
	STLVectorDescriptor(ItemType*) : STLContainerDescriptor((std::vector<ItemType, Alloc>*)nullptr), m_ItemTypeDesc(TypeResolver<ItemType>::GetTypeDescriptor())
	{	
		using VectorType = std::vector<ItemType, Alloc>;

		GetSize = [](const void* voidVectorPtr) -> size_t
		{
			const auto& vec = *(static_cast<const VectorType*>(voidVectorPtr));
			return vec.size();
		};

		GetItem = [](const void* voidVecPtr, size_t index) -> const void*
		{
			const auto& vec = *(static_cast<const VectorType*>(voidVecPtr));
			return &vec[index];
		};
	}

	virtual void Dump(const void* obj, const size_t indentLevel) const override;
};

END_NAMESPACE