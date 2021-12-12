#include "classA.h"

// initialization of the static member of the class --> it doesnt depend on the objects created -> it is defined at the
// beginning of the header
int ClassA::num_objects_classA = 0;
/*
ClassA::ClassA()
{
    this->attribute_A1 = 1;
    this->attribute_A2 = 23.5;
    this->attribute_A3 = "asdsadas";

    std::cout << " an Object of the ClassA has been created" << std::endl;
};
*/
ClassA::ClassA(int attribute_A1,
    float attribute_A2) // Constructor als Initialization List. To initialize members as
                        // they are created. (more efficient)
    : attribute_A1{ attribute_A1 }
    , attribute_A2{ attribute_A2 }
{
    this->attribute_A3 = "asdsadas"; // this one is initialized in the default way
    ++num_objects_classA;
    std::cout << " an Object of the ClassA has been created" << std::endl;
};

ClassA::ClassA(int attribute_A1,
    float attribute_A2,
    std::string word) // Constructor als Initialization List. To initialize members as
                      // they are created. (more efficient)
    : attribute_A1{ attribute_A1 }
    , attribute_A2{ attribute_A2 }
    , attribute_A3{ word }
{
    ++num_objects_classA;
    std::cout << " an Object of the ClassA has been created" << std::endl;
};

ClassA::ClassA(int attribute_A1, float attribute_A2, std::string word, StructA& struct_param)
    : attribute_A1{ attribute_A1 }
    , attribute_A2{ attribute_A2 }
    , attribute_A3{ word }
    , attrib_Struct{ struct_param }
{
    ++num_objects_classA;
    std::cout << " an Object of the ClassA has been created" << std::endl;
};

void ClassA::method_protected_class_A(int num)
{
    std::cout << " You are using a protected method of the class A with input value " << num << std::endl;
}

void ClassA::set_attribute_A1(int v1)
{
    this->attribute_A1 = v1;
    return;
};

int ClassA::get_attribute_A1(void) const
{
    return this->attribute_A1;
}

void ClassA::set_attribute_A2(float v2)
{
    this->attribute_A2 = v2;
    return;
};

float ClassA::get_attribute_A2(void) const
{
    return this->attribute_A2;
}

void ClassA::set_attribute_A3(std::string& word)
{
    word[0] = 'Z'; // lets modify the string --> una particula de un strin es un char!! --> por consiguiente entre ' 'S
    this->attribute_A3 = word;
    return;
};

std::string ClassA::get_attribute_A3(void) const
{
    return this->attribute_A3;
}

int ClassA::get_numObjects_classA(void)
{
    return num_objects_classA;
}

void ClassA::set_attributes_struct(int int_value, float float_value, std::string string_value)
{
    this->attrib_Struct.memberStruct_A1 = int_value;
    this->attrib_Struct.memberStruct_A2 = float_value;
    this->attrib_Struct.memberStruct_A3 = string_value;

    return;
};

void ClassA::get_attributes_struct(int& int_value, float& float_value, std::string& string_value)
{
    int_value = this->attrib_Struct.memberStruct_A1;
    float_value = this->attrib_Struct.memberStruct_A2;
    string_value = this->attrib_Struct.memberStruct_A3;
    return;
};

ClassA::~ClassA()
{
    // we eliminate one of the objects, so the static member that counts number of objects is decremented as well
    --num_objects_classA;
    std::cout << " an Object of the ClassA has been destroyed" << std::endl;
}