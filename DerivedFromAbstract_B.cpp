#include "DerivedFromAbstract_B.h"

DerivedFromAbstract_B::DerivedFromAbstract_B()
{
}

// in the cpp we dont have to write again "virtual" or "override" for that function
void DerivedFromAbstract_B::pure_virtual_method1()
{
    std::cout << "This is a virtual pure function (method 1) implemented in DerivedFromAbstract_B " << std::endl;
}

void DerivedFromAbstract_B::pure_virtual_method2(float num)
{
    std::cout << "This is a virtual pure function (method 2) implemented in DerivedFromAbstract_B " << std::endl;
}

void DerivedFromAbstract_B::virtual_method3(int num)
{
    std::cout << "virtual method 3 from abstract class, but not pure virtual (not mandatory to implement). It was "
                 "called from DerivedFromAbstract_B class"
              << std::endl;
}

DerivedFromAbstract_B::~DerivedFromAbstract_B()
{
}
