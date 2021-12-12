#include "utils.h"
#include <iostream>

void display_all_from_ClassA(ClassA& Object)
{
    std::cout << "The  parameters of the class are:  " << std::endl;
    std::cout << "Single parameters:  " << std::endl;

    std::cout
        << Object.attribute_A1
        << std::endl; // it is a private member of ClassA, but since we are friend of that  class, we have access ;)
    std::cout << Object.attribute_A2 << std::endl;
    std::cout << Object.attribute_A3 << std::endl;

    std::cout << "Elements of the structure:  " << std::endl;
    std::cout << Object.attrib_Struct.memberStruct_A1 << std::endl;
    std::cout << Object.attrib_Struct.memberStruct_A2 << std::endl;
    std::cout << Object.attrib_Struct.memberStruct_A3 << std::endl;
}

// print elements
void showList(std::list <int> g)
{
	std::cout << "List elements: ";
	std::list<int>::iterator it;
	for(it = g.begin(); it != g.end(); ++it)
		std::cout << '\t' << *it;
	std::cout << '\n';
};

// print elements deque
void showDeque(std::deque <int> de)
{
	std::cout << "Deque elements: ";
	std::deque<int>::iterator it;
	for(it = de.begin(); it != de.end(); ++it)
		std::cout << '\t' << *it;
	std::cout << '\n';
};