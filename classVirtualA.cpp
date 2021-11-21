#include "classVirtualA.h"

classVirtualA::classVirtualA()
{
}

void classVirtualA::virtual_method1(double number)
{
    std::cout << "virtual method num 1 of Base Class (Class VirtualA) called" << std::endl;
}

void classVirtualA::virtual_method2(int number) const
{
    std::cout << "virtual method num 2 of Base Class (Class VirtualA) called" << std::endl;
}

void classVirtualA::virtual_method3(int number) const
{
    std::cout << "virtual method num 3 of Base Class (Class VirtualA) called. Cant be implemented in derived classes"
              << std::endl;
}

classVirtualA::~classVirtualA()
{
}

// classVirtualA::~classVirtualA()
//{
//}