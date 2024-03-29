// ReflectionSystem-Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
#include "Reflect.h"
#include <windows.h>

struct Node
{
	int key{};
	double value{};
	std::string name{};
	std::vector<int> children{};

	REFLECT() // Enable reflection
};

struct NodeDerived : public Node
{
	int derivedValue{};

	REFLECT_INHERITED(Node) // Enable reflection
};

REFLECT_BEGIN(Node)
REFLECT_MEMBER(key)
REFLECT_MEMBER(value)
REFLECT_MEMBER(name)
REFLECT_MEMBER(children)
REFLECT_END()

REFLECT_BEGIN(NodeDerived)
REFLECT_MEMBER(derivedValue)
REFLECT_END()

int main()
{
	using namespace ReflectionSystem;

	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
	{
		return 0;
	}
	double PC_FREQ = double(li.QuadPart)/1000;


	NodeDerived derived;
	//Node derived;
	derived.key = 1;
	derived.value = 3;
	derived.name = "Hello World";
	derived.children = {5, 6, 7};
	derived.derivedValue = 4;
	Node* node = &derived;

	QueryPerformanceCounter(&li);
	unsigned int StartCounter = li.QuadPart;

	TypeDescriptor* nodeTypeDesc = node->GetClassDescriptor();

	QueryPerformanceCounter(&li);
	unsigned int EndCounter = li.QuadPart;
	nodeTypeDesc->DumpToOStream(reinterpret_cast<BytePointer>(node), std::cout);

	std::cout << std::endl << "Execution Time : " << double((EndCounter - StartCounter)/PC_FREQ);

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
