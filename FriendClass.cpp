#include "FriendClass.h"

FriendClass::FriendClass()
{
}

FriendClass::~FriendClass()
{
}

void FriendClass::display_all_from_ClassA_V2(ClassA& Object)
{
    std::cout << "Using the display method of a friend Class from classA  " << std::endl;
    std::cout << "The  parameters of the class are:  " << std::endl;
    std::cout << "Single parameters:  " << std::endl;

    std::cout << Object.attribute_A1 << std::endl;
    std::cout << Object.attribute_A2 << std::endl;
    std::cout << Object.attribute_A3 << std::endl;

    std::cout << "Elements of the structure:  " << std::endl;
    std::cout << Object.attrib_Struct.memberStruct_A1 << std::endl;
    std::cout << Object.attrib_Struct.memberStruct_A2 << std::endl;
    std::cout << Object.attrib_Struct.memberStruct_A3 << std::endl;
};