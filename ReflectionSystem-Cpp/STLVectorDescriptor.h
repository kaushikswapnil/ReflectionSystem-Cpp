#pragma once
 
#include "STLContainerDescriptor.h"
#include <vector>
#include <memory>

BEGIN_NAMESPACE

class STLVectorDescriptor : public STLContainerDescriptor
{
	TypeDescriptor* m_ItemTypeDesc;

public:
	template<typename VectorType>  
	STLVectorDescriptor(TypeDescriptor* itemDescriptor, const VectorType* dummy = nullptr) : STLContainerDescriptor(dummy), m_ItemTypeDesc(itemDescriptor)
	{	
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