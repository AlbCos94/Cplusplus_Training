#ifndef __CLASSA_H__
#define __CLASSA_H__

#include <iostream>
#include <string> // libs que son standars se ponen entre < >

// Struct
// definition of a struct that will be use as an attribute of the class
// a struct is like a class but by default all its memebers are private --> apart from that IT IS THE SAME
struct StructA {
    int memberStruct_A1{ 0 };
    float memberStruct_A2{ 0.0 };
    std::string memberStruct_A3{ "hola" };
};

// Class
class ClassA
{

public:
    // Constructors
    // constructor delegation
    ClassA()
        : ClassA{ 1, 34.3,
            "hola caracola" } {}; // This constructor call the third constructor (where all parameters shall be given
    ClassA(int attribute_A1, float attribute_A2);
    ClassA(int attribute_A1, float attribute_A2, std::string word);
    ClassA(int attribute_A1, float attribute_A2, std::string word, StructA& struct_param);

private: // only accessible from other members of the class!
    // atributos de la clase
    int attribute_A1;
    float attribute_A2;
    std::string attribute_A3;
    // attribute that has as a type a Struct that we defined beforehand
    StructA attrib_Struct;

    // static --> data member that belongs to a class, not to any specific object
    static int num_objects_classA;
    friend class FriendClass;

    // elements derived as protected can be access by derived classes
protected:
    int protected_attrib_A{ 77 };
    // generic protected method of A
    void method_protected_class_A(int num = 2);

public:
    // metodos de la clase
    int get_attribute_A1(void) const; // we add this "const" to say to the compiler that this method never will vary the
                                      // object. // in case of creating a constant object it is necessary to access at
                                      // least to its members
    void set_attribute_A1(int);
    float get_attribute_A2(void) const;
    void set_attribute_A2(float);
    std::string get_attribute_A3(void) const;
    void set_attribute_A3(std::string& word);

    // set and get functions for the struct member
    void set_attributes_struct(int, float, std::string);
    void get_attributes_struct(int&, float&, std::string&); // we will pass void elements by reference to obtain their
                                                            // real values once passed throught this member function

    // class function that has access to the static member
    static int get_numObjects_classA(void);

    // Friendship (for functions or classes)
    // declaration of functions (single funtion or from another class) or entire Class that can use all the private
    // members of this class
    // Example of a single function being a friend of Class A
    friend void display_all_from_ClassA(ClassA& Object);

    // Example of a friend Class
    // all the methods of Class A will be accessed by the declared friend Class --> "FriendClass"

    // Destructor
    ~ClassA();
};

#endif