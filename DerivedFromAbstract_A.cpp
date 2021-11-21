#include "DerivedFromAbstract_A.h"

DerivedFromAbstract_A::DerivedFromAbstract_A()
{
}

// in the cpp we dont have to write again "virtual" or "override" for that function
void DerivedFromAbstract_A::pure_virtual_method1()
{
    std::cout << "This is a virtual pure function (method 1) implemented in DerivedFromAbstract_A " << std::endl;
}

void DerivedFromAbstract_A::pure_virtual_method2(float num)
{
    std::cout << "This is a virtual pure function (method 2) implemented in DerivedFromAbstract_A " << std::endl;
}

DerivedFromAbstract_A::~DerivedFromAbstract_A()
{
}
