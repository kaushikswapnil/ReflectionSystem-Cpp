#include "TypeResolver.h"

USING_NAMESPACE

PrimitiveTypeResolver& DefaultResolver::GetPrimitiveTypeResolver()
{
	static PrimitiveTypeResolver primitiveTypeResolver;
	return primitiveTypeResolver;
}
