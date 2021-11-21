#include "classB.h"

ClassB::ClassB()
{
    // before this constructor, the default constructor of class A will be called
    std::cout << " an Object of the ClassB has been created" << std::endl;
}

ClassB::ClassB(int attribute_A1, float attribute_A2, std::string word, StructA& struct_param, int paramB)
    : ClassA{ attribute_A1, attribute_A2, word, struct_param }
    , param_ClassB{ paramB }
{
    // before this constructor, the default constructor of class A will be called
    std::cout << " an Object of the ClassB has been created" << std::endl;
}

void ClassB::display_all_from_ClassB(void)
{
    // std::cout << this->attribute_A2 << std::endl; --> CANNOT ACCESS to PRIVATE ELEMENTS OF CLASS A (class we derived
    // from)
    std::cout << this->protected_attrib_A
              << std::endl; // we will be able to access the PROTECTED elements of the class from where we inherit
    std::cout << this->param_ClassB << std::endl; // of course we can access of the own class
}

void ClassB::method_public_class_B(int num)
{
    ClassA::method_protected_class_A(num);
    // this->method_protected_class_A(num);
    //->method_protected_class_A(num);
    std::cout << "We have just used a protected method from A through B, which displays the num: " << num << std::endl;
}

float ClassB::get_attribute_A2(void) const
{
    float value;
    value = ClassA::get_attribute_A2();
    std::cout << "We redefined a method from class A in class B" << std::endl;
    std::cout << " This method is used to get the value of one of the attributes of Class A, in this case the value: "
              << value << std::endl;
    return value;
}

ClassB::~ClassB()
{
    std::cout << " an Object of the ClassB has been destroyed" << std::endl;
    // after this destructor, the destructor of the class A will be called
}
