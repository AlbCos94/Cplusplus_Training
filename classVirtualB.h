#pragma once
#include "classVirtualA.h"

// with the "final" specifier after "classVirtualB" we prevent that this class is derived again by another class
// we will no be able to create a class such as --> class classVirtualC : public classVirtualB
class classVirtualB final : public classVirtualA
{
public:
    classVirtualB();

    virtual void virtual_method1(double number) override; // we add overrride to make sure that we intend to override a
                                                          // function from the Base Class. If the signature doesnt match
                                                          // the compiler will send us an error.
    virtual void virtual_method2(int number)
        const override; // we add overrride to make sure that we intend to override a function from the Base Class

    /*
    virtual void virtual_method3(
        int number) const final; // that is gonna be error, since it was a final method for the previous class
    */

    virtual ~classVirtualB();
};
