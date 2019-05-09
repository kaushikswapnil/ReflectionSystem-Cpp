#include "TypeResolverHelper.h"
#include "STLVectorDescriptor.h"

USING_NAMESPACE

unsigned int TypeResolverHelper::CalculateHashForTypeName(const std::string& typeName)
{
	return 0; //#TODO Implement the hash 
}

//template<>
//TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<std::string>()
//{
//	static STLVectorDescriptor vectorDescriptor((std::string*)nullptr);
//	return &vectorDescriptor;
//}


//template<>
//TypeDescriptor* TypeResolverHelper::GetSTDVectorTypeDescriptor<std::string>();
