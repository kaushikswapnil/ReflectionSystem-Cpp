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
		GetContainerSize = [](BytePointer const voidVectorPtr) -> size_t
		{
			const auto& vec = *(reinterpret_cast<const VectorType*>(voidVectorPtr));
			return vec.size();
		};

		GetContainerItem = [](BytePointer const voidVecPtr, size_t index) -> BytePointer const
		{
			auto& vec = *(reinterpret_cast<VectorType* const >(voidVecPtr));
			return reinterpret_cast<BytePointer const>(&vec[index]);
		};
	}

	virtual void DumpToOStream( BytePointer const obj, std::ostream& outStream, const size_t indentLevel = 0) const override;
};

END_NAMESPACE