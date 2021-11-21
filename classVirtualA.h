#pragma once

#include <iostream>
#include <string>

// POLYMORPHISM
// this class is an abstract class
// no  objects are gonna be created directly from that class. We are gonna used that class to inherit other classes from
// it and allow that those classes implement (override) some of the same methods which are gonna be dynamically
// bound ( at run-time )

class classVirtualA
{
public:
    classVirtualA();

    // virtual_method1 is a virtual function, which means that CAN (not muss) be overrriden in the derived classes, and
    // those are gonna be dynamically bounded at runtime when we use a pointer of "ClassVirtualA" or a reference of
    // "classVirtualA". --> so we will use the methods of the derived class
    virtual void virtual_method1(double number);
    virtual void virtual_method2(int number) const;

    // "final" specifier prevents virtual method from being overriden in derived classes
    // the following method can be ONLY implemented in this class ( base Class) and not have a new version in derived
    // class
    virtual void virtual_method3(int number) const final;

    // Deleting a polymorphic object that does not have a virtual destructor could lead to unexpected behaviour.
    // we need to provide a virtual destructor for the class
    virtual ~classVirtualA();

    //~classVirtualA();
};
