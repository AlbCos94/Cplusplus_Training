#include "utils.h"

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