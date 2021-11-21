#pragma once
#include <iostream>
#include <string>
// ABSTRACT CLASS
// class that cannot be instantiated ( we cant create objects from it)
// general class that is the parent of all classes
// it is os generic that we will never create objects from it
// serves as parent of derived objects
// all its methods will be virtual
// contain at least ONE PURE VIRTUAL FUNCTION ---> function to make a class abstract --> virtual void function () = 0;
// --> which makes this class not instantiatable when we derive a class from a an abstract class we MUST ( no optinal
// like a normal virtual function ) override the pure virtual function to make the derived class an concrete one
// Otherwise the derived class will be also an abstract class.

class AbstractClass
{
public:
    AbstractClass();

    // the next two methods will have to be implemented when we derive classes from this one
    virtual void pure_virtual_method1() = 0;
    virtual void pure_virtual_method2(float num) = 0;

    // the next method we CAN also implement it in the derived function but is not a MUSS
    virtual void virtual_method3(int num);

    // the destructor has to be also virtual
    virtual ~AbstractClass();
};
