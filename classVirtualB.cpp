#include "classVirtualB.h"

classVirtualB::classVirtualB()
{
}

// in the cpp we dont have to write again "virtual" or "override" for that function
void classVirtualB::virtual_method1(double number)
{
    std::cout << "virtual method num 1 of Derived Class (Class VirtualB) called" << std::endl;
}

void classVirtualB::virtual_method2(int number) const
{
    std::cout << "virtual method num 1 of Derived Class (Class VirtualB) called" << std::endl;
}

classVirtualB::~classVirtualB()
{
}
