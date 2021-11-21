#include "AbstractClass.h"

AbstractClass::AbstractClass()
{
}

void AbstractClass::virtual_method3(int num)
{
    std::cout << "virtual method 3 from abstract class, but not pure virtual. It was called from abstract class. Not "
                 "compulsory to implement in the derived classes"
              << std::endl;
}

AbstractClass::~AbstractClass()
{
}
