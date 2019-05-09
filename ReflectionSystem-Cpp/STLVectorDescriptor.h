#pragma once
 
#include "STLContainerDescriptor.h"
#include <vector>
#include <memory>
#include "TypeResolver.h"

BEGIN_NAMESPACE

class STLVectorDescriptor : public STLContainerDescriptor
{
	TypeDescriptor* m_ItemTypeDesc;

public:
	template<typename ItemType, typename Alloc = std::allocator<ItemType>>  
	STLVectorDescriptor(ItemType*) : STLContainerDescriptor((std::vector<ItemType, Alloc>*)nullptr), m_ItemTypeDesc(TypeResolver<ItemType>::GetTypeDescriptor())
	{	
		using VectorType = std::vector<ItemType, Alloc>;

		GetContainerSize = [](const void* voidVectorPtr) -> size_t
		{
			const auto& vec = *(static_cast<const VectorType*>(voidVectorPtr));
			return vec.size();
		};

		GetContainerItem = [](const void* voidVecPtr, size_t index) -> const void*
		{
			const auto& vec = *(static_cast<const VectorType*>(voidVecPtr));
			return &vec[index];
		};
	}

	virtual void DumpToOStream(const void* obj, std::ostream& outStream, const size_t indentLevel = 0) const override;
};

END_NAMESPACE