#pragma once
#include "AbstractClass.h"
#include <iostream> // -> < header file> --> the compìler knows where this header is located (usually standard libs)

class DerivedFromAbstract_A : public AbstractClass
{
public:
    DerivedFromAbstract_A();

    // we have to implement the pure virtual functions of the abstract class from which class derives
    // we write override to make sure that we dont make mistakes in the signature
    virtual void pure_virtual_method1() override;
    virtual void pure_virtual_method2(float num) override;

    ~DerivedFromAbstract_A();
};
