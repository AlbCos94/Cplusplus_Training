#pragma once
#include "AbstractClass.h"

class DerivedFromAbstract_B : public AbstractClass
{
public:
    DerivedFromAbstract_B();

    // we have to implement the pure virtual functions of the abstract class from which class derives
    // we write override to make sure that we dont make mistakes in the signature
    virtual void pure_virtual_method1() override;
    virtual void pure_virtual_method2(float num) override;

    // for this class we are gonna implement the virtual function that is not pure as well
    virtual void virtual_method3(int num) override;

    ~DerivedFromAbstract_B();
};
