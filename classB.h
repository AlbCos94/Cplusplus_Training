#pragma once
#include "classA.h"
#include <iostream>

// derived class from A
// an object of class B is also an object of class A ( not the opposite )
// if class B is inherited from class A means (private iheritance as default),
//  that ClassB will inherit the public and protected attributes and operators of ClassA ( never the PRIVATES!! )
// with Inheritance you never have access to the private elements of the class from which you derive!!!!

class ClassB : private ClassA // "private" would be not needed, since it is the default inheritance mode"
{

private:
    int param_ClassB;

public:
    // constructors
    // default constructor for elements of Class A and B
    ClassB();
    // Complete Constructor for elements of Class A and B
    ClassB(int attribute_A1, float attribute_A2, std::string word, StructA& struct_param, int paramB);

    void display_all_from_ClassB(void);
    // redefinition of a base class method (classA)
    float get_attribute_A2(void) const;

    // generic method of class B that uses a protected method from class A
    void method_public_class_B(int num = 2);

    // destructor
    ~ClassB();
};

// Class B will have access to protected and public elements of Class A
// The protected and publiuc elements of A will be private in Class B. So if we inherit again from Class B, we will not
// have access to that elements.