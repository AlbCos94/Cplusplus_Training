#pragma once
#include <classA.h>
// pragma once --> better alternative in comparison to what it was used in classA.h

// this class is a friend Class of Class A.
// all the private function methods and attributes of the ClassA are accessible by this FriendClass
class FriendClass
{
public:
    FriendClass();
    ~FriendClass();

public:
    void display_all_from_ClassA_V2(ClassA& Object);
};
