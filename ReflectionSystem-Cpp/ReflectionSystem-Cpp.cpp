// ReflectionSystem-Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Reflect.h"

struct Node
{
	std::string key;
	double value;
	std::vector<Node> children;

	REFLECT() // Enable reflection
};

REFLECT_STRUCT_BEGIN(Node)
REFLECT_STRUCT_MEMBER(key)
REFLECT_STRUCT_MEMBER(value)
REFLECT_STRUCT_MEMBER(children)
REFLECT_STRUCT_END()

int main()
{
	Node node = { "apple", 3, {{"banana", 7, {}}, {"cherry", 11, {}}} };

	TypeDescriptor* nodeTypeDesc = TypeResolver<Node>::GetTypeDescriptor();

	nodeTypeDesc->Dump(&node);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
