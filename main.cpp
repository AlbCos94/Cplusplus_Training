#include "AbstractClass.h"
#include "DerivedFromAbstract_A.h"
#include "DerivedFromAbstract_B.h"
#include "FriendClass.h"
#include "classA.h" // -> " header_file  " --> header that is local to this project
#include "classB.h"
#include "classVirtualA.h" // -> " header_file  " --> header that is local to this project
#include "classVirtualB.h"
#include "functions_exception_handling.h"
#include "utils.h"

#include <iostream> // -> < header file> --> the compìler knows where this header is located (usually standard libs)
#include <list>
#include <map>
#include <memory> // header file to define smart pointer classes and functions --> from the std lib
#include <set>
#include <vector>

// this main to train cpp concepts has to be read from the bottom to the top

/*
 * reamining to do...
 *  - std::move
 *  - copy constructor for classes and in general
 *  - google tests
 */

int main()
{
    // test selector
    int Test;
    Test = 25;

    // EXCEPTION HANDLING - using classes to define exceptions;
    // to make the type of the exception thrown very explicit and also very specific- We will throw objects!
    if(Test == 25) {

        float km_per_hour = 0;
        float km = -23;
        float hours = 34;

        try {
            calculate_kmph(km, hours);
            std::cout << km_per_hour << std::endl;
        }

        // always pass as a constant reference
        catch(const DevideByZeroException(&ex)) {
            std::cerr << "You can not devide by zero " << std::endl;
        }

        catch(const NegativeValueException(&ex)) {
            std::cerr << "Negative values are not allowed " << std::endl;
        }
    }

    // EXCEPTION HANDLING - using functions and different kind of exceptions;
    if(Test == 24) {

        // declaration of the functions in "functions_exception_handlilng.h"

        // use of the function
        main_function(1, 2, -3, 2);
    }

    // EXCEPTION HANDLING -simple case
    if(Test == 23) {
        // Exeption Handling
        // - Use for synchronous code --> " bunch of statements in a sequence", so each statement in your code is
        // executed one after the other
        // - Exceptions are used to deal with extraordinary situations
        // - insuffient resources ( we have run out of memory or no-external storage is left
        // - missing resources ( open a file that doesnt exist, invalid operations ( divide between 0)  and range
        // violations )

        // - Exception: object (it can contain info of what happened) or primitive (e.g. int, float...) type that
        // signals that an error has occured.
        // - Sometimes the exception occurs in a part of the program that doesnt know how to handle it. So it throws
        // an exception and hopes that some other part upper in the "stack hierarchy" will be able to hanndle with
        // is

        // example
        float dividend = 1212; // dividendo
        float divider = 0;     // divisor
        float result = 0;

        // inside the "try" block we add the code that could arise an exception
        try {
            if(divider == 0) {
                throw 0; // int // "throw" throws an exception object or a primitive type followed by an argument
                         // which is the exception we are throwing
            }
            result = dividend / divider;
            std::cout << " Result is " << result << std::endl;
        }
        // "catch" is the function that handles the exception and deals with it. It has to be of the same type as
        // the object that has been thrown
        catch(int& ex) {
            std::cerr << " Division by 0 not possible, please change the divider "
                      << std::endl; // "cerr" is the standard output stream for errors
        }

        // it is always a good practise to "throw" by value and "catch" by reference
    }
    // WEAK POINTERS
    if(Test == 22) {
        // WEAK POINTERS weak_ptr<T>
        // - provides a non-owning "weak" reference
        // - points to an object of type T on the heap
        // - does not participate in owning relationship
        // - !!! alway created from a shared pointer !!! -
        // - does not increment or decrement reference
        // - used to prevent strong reference cycles which could prevent objects from being deleted
        // - common use: to temporarily reference another object, like "an iterator" that traverses a list of nodes
        // ( it does not own them, it just visits them"

        // example of use -> "circular or cyclic reference"
        class Bwp; // wp -> weak pointer
        class Awp
        {
            std::shared_ptr<Bwp> b_ptr; // pointer that is gonna point to the class Bwp, Awp is gonna own Bwp

        public:
            void set_B(std::shared_ptr<Bwp>& b)
            {
                b_ptr = b;
            }
            // constructor and destructor of Awp
            Awp()
            {
                std::cout << " A Contstructor " << std::endl;
            }
            ~Awp()
            {
                std::cout << " A Destructor " << std::endl;
            }
        };

        class Bwp
        {
            std::weak_ptr<Awp> a_ptr; // for B we use a weak pointer!!!! --> so B doesnt own A

        public:
            void set_A(std::shared_ptr<Awp>& a)
            {
                a_ptr = a;
            }

            Bwp()
            {
                std::cout << " B Contstructor " << std::endl;
            }
            ~Bwp()
            {
                std::cout << " B Destructor " << std::endl;
            }
        };

        Awp ObjectA; // will own B
        Bwp ObjectB;

        std::shared_ptr<Bwp> pB = std::make_shared<Bwp>(ObjectB);
        std::shared_ptr<Awp> pA = std::make_shared<Awp>(ObjectA);

        ObjectA.set_B(pB); // will set a shared pointer for A to B
        ObjectB.set_A(pA); // will set a weak pointer for B to A
    }

    // SHARED POINTERS
    if(Test == 21) {
        // SHARED POINTERS
        // - provide share ownership of heap objects
        // - points to an object on the heap, that could also be pointed by other shared pointers
        // - establishes shared ownership relationships
        // - it can be assigend and copied
        // - can be moved
        // - doenst support management of arrays by default
        // - when the use count is zero, the managed object on the heap is destroyed ( rerefence counting -->
        //--> every time we instantiate a shared pointer object, and it is pointing or reference to the heap object,
        // we
        //-->
        // --> increment a counter. -->
        // --> This counter counts the numbers of shared pointers that are referenceing that heap object -->
        // --> When the count becomes 0, then we know nothing is refereing to that object anymore, so this object on
        // the
        // -->heap can be safetely destroyed

        std::shared_ptr<int> p1{ new int{ 100 } };
        std::cout << "Valule can be changes " << std::endl;
        std::cout << "Valule right now is: " << *p1 << std::endl;
        *p1 = 200;
        std::cout << "Valule is changed to: " << *p1 << std::endl;
        std::cout << "Address of the pointer p1 is: " << p1.get() << std::endl; // i.e 0x831690
        // we assign another pointer to that int value of the heap
        std::shared_ptr<int> p2{ p1 };
        std::cout << "Address of the pointer p2 is: " << p2.get() << std::endl; // i.e. 0x831690
        std::cout << "Valule of the pointer p2 is: " << *p2 << std::endl;
        // get the numbers of shared pointers that are pointing to that object on the heap
        std::cout << "Number of shared pointers to the same object on the heap: " << p1.use_count() << std::endl;
        // if we create a new one
        std::shared_ptr<int> p3{ p2 };
        std::cout << "Number of shared pointers to the same object on the heap: " << p1.use_count() << std::endl;
        // remove one of the pointers that is pointing to tha object on the heap
        p1.reset(); // now only p2 and p3 are pointing to that object
        std::cout << "Number of shared pointers to the same object on the heap: " << p2.use_count() << std::endl;

        // use of "make_shared" ( since C++11)
        {
            std::shared_ptr<int> p11 = std::make_shared<int>(100);
            std::cout << "Address of the pointer p11 is: " << p11.get() << std::endl; // i.e. 0x831690
            std::shared_ptr<int> p22{ p11 };
            std::cout << "Address of the pointer p22 is: " << p22.get() << std::endl; // i.e. 0x831690
            std::shared_ptr<int> p33;
            p33 = p11;
            std::cout << "Address of the pointer p33 is: " << p33.get() << std::endl; // i.e. 0x831690
        } // all three pointers (p11, p22, p33) are destroyed. NOt need to use delete before the scope end
    }

    // UNIQUE POINTER
    if(Test == 20) {
        // UNIQUE POINTER
        // - points to an object of type T of the heap
        // - it is unique, can be only one "unqie_ptr" pointing to that object of the heap
        // - owns what it points to
        // - can´t be assiged or copied ( just in its creation is assigned)
        // - can be moved
        // - when the pointer is destroyed, what it is pointing to, it is also automatically destroyed

        std::unique_ptr<int> p1_int{ new int{ 100 } };
        std::cout << *p1_int << std::endl;
        *p1_int = 200;
        std::cout << *p1_int << std::endl;

        // vectors and move example
        // vector full of unique_pointers to objects
        std::vector<std::unique_ptr<int>> vec_ptrs;
        // unique pointer pointing to a int
        std::unique_ptr<int> p2_int{ new int{ 555 } };
        // vec_ptrs.push_back(p2_int); // ERROR -> we cant not push back beacause that means a copy of the
        // unique_pointer!!!!
        vec_ptrs.push_back(std::move(p2_int)); // we can use move semantics to move the pointer --> now the vector owns
                                               // the pointers (it is only there!!)
        // std::move is used to indicate that an object "t" may be "moved from", i.e. allowing the efficient
        // transfer of resources from t to another object ( the value of a variable that has been copied to another
        // place, is deleted. ) make unique_function - another type of inizialization for unique pointers
        std::unique_ptr<int> p3_int = std::make_unique<int>(777);
        std::cout << *p3_int << std::endl;

        // move operator for unique pointers
        std::unique_ptr<ClassB> ptr_CB1{ new ClassB{} };
        std::unique_ptr<ClassB> ptr_CB2;
        // ptr_CB2 = ptr_CB1; // ERROR, we cannt assig another pointer ( pointers cant have same direction pointing
        // to
        // )
        std::cout << " \nAddress unique Pointer ptrCB1:  " << ptr_CB1.get() << std::endl; //  0xd52ab8

        std::cout << " \nAddress unique Pointer ptrCB2:  " << ptr_CB2.get() << std::endl; // 0
        std::cout << " \nUse of move to change ownershiopt among pointers  " << std::endl;
        ptr_CB2 = std::move(ptr_CB1); // moves the ownership on the heap from ptr_CB1 to ptr_CB2;
        // ptr_CB2 will be refering to the content of the ptr_CB1 owning it
        // therefore now ptr_CB1 is pointing to nothing
        std::cout << " \nAddress unique Pointer ptrCB1:  " << ptr_CB1.get() << std::endl; // 0
        // and ptr_CB2 is pointing to where ptr_CB1 was pointing before
        std::cout << " \nAddress unique Pointer ptrCB2:  " << ptr_CB2.get() << std::endl; //  0xd52ab8

        // "unique_ptr.get()" --> in order to get the address of that pointer
    }

    // Smart Pointers Introduction- new in C++11
    // objects, implented as C++ template classes which we can instantiate
    // they can only point to heap allocated memory
    // they automatically call delete when they are not longer needed
    // " they are wrapper classes that contain and manage a raw pointer"
    // <memory> needs to be included
    if(Test == 19) {
        // example of unique pointer creation, pointing to an object of ClassA
        std::unique_ptr<ClassB> ptrUniqueClassB{ new ClassB() };
        ptrUniqueClassB->display_all_from_ClassB();
        std::cout << ptrUniqueClassB->get_attribute_A2() << std::endl;
    } // when the unique ptr goes out out of sccope , the heap storage that was using is deallocated automatically

    // Enumeration declaration
    if(Test == 18) {
        // An enumeration is a distinct type whose value is restricted to a range of values (see below for details),
        // which may include several explicitly named constants ("enumerators").  The values of the constants are
        // values of an integral type (siempre un entero o char??) known as the "underlying type"  of the
        // enumeration.
        enum TestEnumeration { a, b, c = 10, d, e = 'w', f };
        std::cout << " \nTest Enumeration values for TestEnumeration: " << std::endl;
        std::cout << " \n a: " << a << std::endl;
        std::cout << " \n b: " << b << std::endl;
        std::cout << " \n c: " << c << std::endl;
        std::cout << " \n d: " << d << std::endl;
        std::cout << " \n e: " << e << std::endl;
        std::cout << " \n f: " << f << std::endl;
        std::cout << " \n " << std::endl;

        // Unscoped enumeration is a class memeber (struct or class )
        struct StructA {
            enum direction { left = 'l', right = 'r' };
        };

        StructA TestStructA;
        StructA* ptrStructA = &TestStructA;
        std::cout << "\nTest Enumeration values for StructA " << std::endl;
        std::cout << "\n left: " << StructA::direction::left << std::endl;
        std::cout << "\n left: " << StructA::left << std::endl; // direct access
        std::cout << "\n left: " << TestStructA.left << std::endl;
        std::cout << "\n left: " << ptrStructA->left << std::endl; // direct access

        // Enum can be used to work just with the name constants of the enumeration without needing the number that
        // indentifies each one the number associated to each enumerator it is impricit to compare each element in a
        // numerical way example:
        enum class Color {
            red,
            green,
            blue,
            yellow,
            pink
        }; // each enumerator has associated a number ( 0, 1, 2, 3, 4) but, we may not need to know it
        Color result = Color::red;

        std::cout << "\n COLOUR SELECTOR" << std::endl;
        switch(result) {
        case Color::red:
            std::cout << "red chosen\n" << std::endl;
            break;
        case Color::green:
            std::cout << "green chosen\n" << std::endl;
            break;
        case Color::blue:
            std::cout << "blue chosen\n" << std::endl;
            break;
        case Color::yellow:
            std::cout << "yellow chosen\n" << std::endl;
            break;
        case Color::pink:
            std::cout << "pink chosen\n" << std::endl;
            break;
        }

        // in any case we had to deal with the inter that is behind each member of the enumeration
        // we have used the enumeration as a case selector using named constants

        // specification of the type, for example to display a 'char'
        enum class Altitude : char { high = 'h', low = 'l' };
        // Altitude altitudTest;
        Altitude altitudeTest = Altitude::high;
        // std::cout << altitudeTest << std::endl; -> ERROR no se puede hacer display directamente por pantalla!

        if(altitudeTest == Altitude::high) {
            std::cout << "We are in a high altitude" << std::endl;
        } else {
            std::cout << "We in a low altitude" << std::endl;
        }
    }

    // Abstract Classes
    if(Test == 17) {

        // class that didnt implement the virtual method that was not pure (the one that was not mandatory)
        std::cout << "\nClass that didnt implement the not pure method" << std::endl;
        DerivedFromAbstract_A Derived_from_Abstract1;
        Derived_from_Abstract1.pure_virtual_method1();
        Derived_from_Abstract1.pure_virtual_method2(123);
        Derived_from_Abstract1.virtual_method3(32323);

        // that implemented also the virtual method that was not pure
        std::cout << " \nClass that implemented the not pure method" << std::endl;
        DerivedFromAbstract_B Derived_from_Abstract2;
        Derived_from_Abstract2.pure_virtual_method1();
        Derived_from_Abstract2.pure_virtual_method2(123);
        Derived_from_Abstract2.virtual_method3(32323);
    }

    // Polymorphism / inheritance and virtual functions with Pointers and references
    if(Test == 16) {

        std::cout << "Polymorphism using Pointers" << std::endl;

        classVirtualA* ptr_1 = new classVirtualA();
        ptr_1->virtual_method1(55); // call method from classVirtualA

        classVirtualA* ptr_2 = new classVirtualB();
        ptr_2->virtual_method1(66); // call method from classVirtualB

        classVirtualB* ptr_3 = new classVirtualB();
        ptr_3->virtual_method1(77); // call method from classVirtualB

        // next expression gives error!!
        // object classVirtualA is not an object of classVirtualB (opposite yes)
        // classVirtualB* ptr_4 = new classVirtualA(); // error invalid conversion from classVirtualA to
        // classVirtualB ptr_4->virtual_method1(77); // call method from classVirtualB

        // try the final virtual_method of the classVirtualA
        ptr_1->virtual_method3(2);
        ptr_2->virtual_method3(234);
        ptr_3->virtual_method3(2);

        std::cout << "\nPolymorphism using References" << std::endl;
        // For references the idea is the same...
        classVirtualA ObjectA;
        classVirtualA& RefToA =
            ObjectA; // RefToA is an alias of ObjectA which is an classVritualA object and it will act like this one
        RefToA.virtual_method1(223); // call method from classVirtualA

        classVirtualB ObjectB;
        classVirtualA& RefToB =
            ObjectB; // it is gonna act like classVirtualB since classVirtualB is always also a classVirtualA Object
        ObjectB.virtual_method1(23234); // it calls method from classVirtualB. If we were not using virtual function we
                                        // would use the virtual_method from "classVirtualA"
    }

    // Pointers and the const property
    if(Test == 15) {
        int low_score{ 5 };
        int high_score{ 555 };

        // POINTER TO CONSTANTS (variables)
        // "const" in front of the pointer´s type ( in front of the type of the variable the pointer is pointing to)
        // we point to variables whose values cannot be changed
        const int* score_ptr{ &high_score };
        // we cant not change the value of the variable through that pointer:
        // *score_ptr = 32; // --> ERROR
        // but we can change that the pointer points somewhere else
        score_ptr = &low_score;

        // CONSTANT POINTERS
        // "const" goes in front of the variable's name that represents the pointer
        // we set a pointer that will be always pointing to the same address
        int* const score_ptr_cte{ &high_score };
        std::cout << "Value variable before change: " << high_score << std::endl;         // address like 0x7bfc0c
        std::cout << "Deferenced pointer before change: " << *score_ptr_cte << std::endl; // address like 0x7bfc0c
        *score_ptr_cte = 23;
        std::cout << "Value variable after change: " << high_score << std::endl;               // address like 0x7bfc0c
        std::cout << "Value deference pointer after changed: " << *score_ptr_cte << std::endl; // address like 0x7bfc0c
        // not able to change the address where this pointer is pointing to..
        // score_ptr_cte = &low_score; //--> ERROR

        // POINTER CONSTANT TO POINTERS
        // "const" in front of pointer´s type and variable´s name
        // we can´t neither change the value of the varible we are pointing of the address of that pointer
        const int* const score_ptr_cte_cte{ &high_score };
        // *score_ptr_cte_cte = 342; // --> ERROR
        // score_ptr_cte_cte = &low_score; // --> ERROR
    }

    // Arrays and pointers
    if(Test == 14) {
        // the variable that defines an array is actually a pointer to the first element of the array
        int scores[]{ 100, 95, 89 };
        std::cout << "Value variable array (address first member): " << scores << std::endl; // address like 0x7bfc0c
        // if we deference the variable of the array, since it is a pointer o the first element, we will get the
        // value of the first element
        std::cout << "Deference value variable array (value first member): " << *scores << std::endl; // 100
        // lets get the second element value of the array
        std::cout << "Deference second element pointer-variable array " << scores[1] << std::endl; // 95
        // lets now use a pointer to point to that cuck of memory
        int* ptr_to_array = scores;
        std::cout << "Deference pointer to array (value first member): " << *ptr_to_array << std::endl; // 100
        // lets get the second value by using the pinter
        ptr_to_array++;
        std::cout << "Deference pointer to array (value second member): " << *ptr_to_array << std::endl; // 100
    }

    // Pointer -- allocating memory ont the heap at runtime ( no on the stack) ->
    // THE HEAP IS ONLY ACCESSIBLE THROUGH POINTERS!!!
    if(Test == 13) {
        int* int_ptr{ nullptr };
        // allocate an integer of value 10 on the heap --> we are creating a slot of memory on the heap to store
        // there the value 10
        int_ptr = new int{ 10 }; // this value stored on the heap is only accessible by the pointer!!! ( get value, set
                                 // value and delete); --> no variable, only we have the pointer!!
        std::cout << "Address of the memory slot of the heap where we are pointing through our pointer: " << int_ptr
                  << std::endl;                                                                    // 0x21690
        std::cout << "Value stored on the slot of memory of the heap : " << *int_ptr << std::endl; // 10
        delete int_ptr; // not forget to delete the pointer after using it!! otherwise that slot of memory on the
                        // heap will be always there..

        // allocation of an array on the heap
        int* array_ptr{ nullptr }; // declaration like for a normal pointer!
        array_ptr = new int[77]; // Different from the normal point. Here we are indicating how many cells of this type
                                 // in memory of the heap is gonna be needed. In this example we are saying that we are
                                 // gonna need enough space for 77 integers on the heap
        *array_ptr = 11;
        std::cout << "Get value of first element array: " << *array_ptr << std::endl; // 11
        array_ptr++;
        *array_ptr = 22;
        std::cout << "Get value of second element array: " << *array_ptr << std::endl; // 22
        array_ptr--;
        std::cout << "Get again value of first element array: " << *array_ptr << std::endl; // 11
        array_ptr++;
        array_ptr++;
        std::cout << "Get value of third element array (which was not set): " << *array_ptr
                  << std::endl; // random value
        delete[] array_ptr;     // always not foreget to erase the pointer, otherwise we will have a memory leak of all
                                // this heap storage
    }

    // Pointer - generic stuff
    if(Test == 12) {
        std::cout << "T R A I N I N G    O F    P O I N T E R S" << std::endl;
        // best way to initialize a pointer --> pointing it to a null pointer
        int* int_ptr{ nullptr };
        std::cout << "Value adress of a null pointer: " << int_ptr << std::endl; // int_ptr = 0
        int* int_ptr2;
        std::cout << "Value adress of a pointer neiteher assigned or initialized: " << int_ptr2
                  << std::endl; // random address ( "0x96feca58" )
        // check the address of a variable
        int num1{ 10 };
        std::cout << "Address where a variable is stored: " << &num1 << std::endl; //  address like ( "0x96feca58" )
        // we assign the pointer created to this variable.
        // This pointer is gonna have as a value the address where this ( "0x96feca58" )
        int_ptr = &num1;
        std::cout << "The address that contains the pointer is now the address of that variable int_ptr = &num1"
                  << std::endl;
        std::cout << "Check: &num1 = " << &num1 << std::endl;     //  ( e.g "0x96feca58" )
        std::cout << "Check: int_ptr = " << int_ptr << std::endl; //  ( e.g "0x96feca58" )
        // Deference a pointer --> get the data this pointer is pointing to
        std::cout << "Deference of a pointer --> *int_ptr --> " << *int_ptr << std::endl; //  10
    }

    // test2 of inheritance for Classes
    if(Test == 11) {
        ClassB ObjectClassB;
        // use of a public method from class A through class B ( since he inherits from A)
        ObjectClassB.method_public_class_B(23);
        float value;
        value = ObjectClassB.get_attribute_A2();
    }

    // Containers of the Standard Template Library (STL) ("std::")
    // Maps = key + value --> a set of "std::pairs" with values "key and value" that are without any order
    if(Test == 10) {
        std::map<std::string, int> money{
            { "Euros", 2324 },
            { "Francos", 233 },
            { "Marcos", 43234 },
        }; // elements of the map are stored randomly!! --> it looks like a dictionary in python!

        // it->first/second are used to access the attributes of the iterator respectively
        for(auto it = money.begin(); it != money.end(); it++) {
            std::cout << "the key is: " << it->first << " ,  and the vallue is " << it->second << std::endl;
        }
    };

    // Containers of the Standard Template Library (STL) ("std::")
    // container types --> vector, list, map and set --> includes needed!!!
    // Iterators and Vectors
    if(Test == 9) {

        // example of iterators --> used to iterate allong an specific container
        std::vector<int>::iterator it1; // this iterator can iterate over a vector of integers
        std::list<std::string>::iterator it2;
        std::map<std::string, std::string>::iterator it3;
        std::set<char>::iterator it4;

        // get first item iterator --> .begin()
        std::vector<int> vec{ 88, 2, 3, 4, 5, 6 };
        it1 = vec.begin();
        // operations with iterators are pretty simmilar compared to operations with pointers!! (example with
        // dereference)
        std::cout << *it1 << std::endl;
        // to short the declaration of an iterator it is usually used "auto name_iterator", and the assignation to
        // the container. The compiler will interpret which type of iterator is that one.
        std::vector<std::string> vec2{ "asda", "2d", "3df", "4sdfsdf", "5fsd", "dd6gg" };
        auto it5 = vec2.begin();
        std::cout << *it5 << std::endl;

        // for loop through a container
        for(auto it = vec2.begin(); it != vec2.end(); it++) {
            std::cout << *it << std::endl;
        }

        // Member functions for a vector
        //  "size()" --> return the number of components of  a vector
        std::cout << vec2.size() << std::endl;
        // "empty()" --> return true if the vector is empty
        std::cout << vec2.empty() << std::endl; // this case returns 0 (False)
        // "at()" --> returns the element in an specific position of a container // starts with 0
        std::cout << vec2.at(2) << std::endl;
        std::cout << vec2[2] << std::endl; // --> with the claudators is also possible to access one of the members
        vec2[2] = "666";                   // and possible to change elements
        std::cout << vec2[2] << std::endl;
        // "front()" -> get first element of the vector
        std::cout << vec2.front() << std::endl;
        // "back()" --> get the last element of the vector
        std::cout << vec2.back() << std::endl;
        // "push_back()" --> at an element at the end of the vector
        vec2.push_back("caracola");
        std::cout << vec2.back() << std::endl;
        // "pop_back()" --> delete the last element of the vector
        vec2.pop_back();
        std::cout << vec2.back() << std::endl;
        // "insert()" --> to insert elements in a given position
        auto it10 = vec2.begin();
        it10++;
        vec2.insert(it10, 3, "h"); // position where to insert, how many times to insert, what to insert
        for(auto it = vec2.begin(); it != vec2.end(); it++) {
            std::cout << *it << std::endl;
        }
        // "clear()" --> clean the content of the vector
        vec2.clear();
        std::cout << vec2.size() << std::endl;
    }

    // test of inheritance for Classes
    if(Test == 8) {
        ClassB ObjectClassB;

        // cretion of Object B with set up of all the attributes
        StructA TestStruct;
        TestStruct.memberStruct_A1 = 6;
        TestStruct.memberStruct_A2 = 66.66;
        TestStruct.memberStruct_A3 = "ab6raca6dab6ra";

        ClassB ObjectClassBFull(66, 4.666, "wih66fdsa", TestStruct, 55);
        ObjectClassBFull.display_all_from_ClassB();
    }

    // test of friendship for Classes
    if(Test == 7) {
        StructA TestStruct;
        TestStruct.memberStruct_A1 = 6;
        TestStruct.memberStruct_A2 = 66.66;
        TestStruct.memberStruct_A3 = "ab6raca6dab6ra";

        // Creation of the object with that struct
        ClassA ObjectA3(66, 4.666, "wih66fdsa", TestStruct);

        // Class that cann access members of the private class "A" ( Class friend of A)
        FriendClass ClassFriendOfA;
        // call of one of the functions of that class, which access private members of an Object ClassA ( which with
        // he is friend)
        ClassFriendOfA.display_all_from_ClassA_V2(ObjectA3);
    }

    // test of friendship for functions
    if(Test == 6) {
        StructA TestStruct;
        TestStruct.memberStruct_A1 = 5;
        TestStruct.memberStruct_A2 = 71.71;
        TestStruct.memberStruct_A3 = "abracadabra";

        // creation of the object with that struct
        ClassA ObjectA2(89, 4.587, "wihfdsa", TestStruct);

        // friend function that is accessing members of the private class "A"
        display_all_from_ClassA(ObjectA2);
    }

    // test of the struct
    if(Test == 5) {
        ClassA ObjectA(1, 4.5, "wiiii");
        // initialization of the struct members with random values
        int struct_int = 1;
        float struct_float = 4.5;
        std::string struct_string = "dsaldkjaslk";

        // get the members of the struct that the object has as a attribut
        ObjectA.get_attributes_struct(struct_int, struct_float, struct_string);
        // display of the values:
        std::cout << struct_int << std::endl;    // 0
        std::cout << struct_float << std::endl;  // 0
        std::cout << struct_string << std::endl; // hola

        // Trying the constructor with struct parameter
        // initialization of the struct members
        StructA TestStruct;
        TestStruct.memberStruct_A1 = 5;
        TestStruct.memberStruct_A2 = 71.71;
        TestStruct.memberStruct_A3 = "abracadabra";
        // creation of the object with that struct
        ClassA ObjectA2(1, 4.5, "wihfdsa", TestStruct);

        // initialization of the struct members with random values
        int struct_int2 = 1;
        float struct_float2 = 4.5;
        std::string struct_string2 = "dsaldkjaslk";

        // get the members of the struct that the object has as a attribut
        ObjectA2.get_attributes_struct(struct_int2, struct_float2, struct_string2);
        // display of the values:
        std::cout << struct_int2 << std::endl;    // 5
        std::cout << struct_float2 << std::endl;  // 71.71
        std::cout << struct_string2 << std::endl; // "abracadabra"
    }

    // Playing with Static Class members
    if(Test == 4) {
        // get_numObjects_classA counts the number of objects alive of this class using the static variable
        // "num_objects_classA"
        ClassA ObjetoA(2, 3.4, "weer");
        std::cout << ObjetoA.get_numObjects_classA() << std::endl; // 1
        ClassA ObjetoB(2, 3.4, "weer");
        ClassA ObjetoC(2, 3.4, "weer");
        std::cout << ObjetoA.get_numObjects_classA() << std::endl; // 3
        {
            ClassA ObjetoD(45, 5.6, "wiii");
            ClassA ObjetoE(2, 3.4, "weer");
            std::cout << ObjetoA.get_numObjects_classA() << std::endl; // 5
        }
        // the two previous objectes created inside the brackets (the scope) have been removed from the static
        // member of the class
        std::cout << ObjetoA.get_numObjects_classA() << std::endl; // 3
    }

    // Creating a constant object // the getting members have been defined as "const"
    if(Test == 3) {
        // creation of a constant object
        const ClassA ObjectAconst(1, 3.4, "wer");
        // std::string palabra2 = ObjectAconst.get_attribute_A3();
        std::cout << ObjectAconst.get_attribute_A1() << std::endl;
        std::cout << ObjectAconst.get_attribute_A2() << std::endl;
        std::cout << ObjectAconst.get_attribute_A3() << std::endl;
    }

    // Pointers with the address of an object
    if(Test == 2) {
        // we allocate memory for an Object in the heap and this one is accessible through a pointer
        ClassA* ptrClassA = new ClassA();
        // ways to access to the components of the class of this pointer:
        // Way 1 --> taking the value where the pointer is addressin with *
        float float1 = (*ptrClassA).get_attribute_A2();
        std::cout << float1 << std::endl;
        // Way 2 --> using the arrow
        int int1 = ptrClassA->get_attribute_A1();
        std::cout << int1 << std::endl;
        std::string palabra = ptrClassA->get_attribute_A3();
        std::cout << palabra << std::endl;
        // DONT FORGET TO FREE THE ALLOCATED MEMORY OF THE HEAP when we are not longer to use this pointer -->
        // destroy de pointer!
        delete ptrClassA;
    }

    // Easy training of classes --> declaration and construnction
    if(Test == 1) {
        // easy training of classes --> declaration and construnction
        std::cout << "Hello World" << std::endl;
        ClassA ObjectDeClassA;
        ClassA ObjectDeClassA1{ 2, 69.69 };

        std::cout << ObjectDeClassA1.get_attribute_A2() << std::endl;
        std::cout << ObjectDeClassA1.get_attribute_A1() << std::endl;

        std::string s;
        s = "ahora esto se entiende";
        std::cout << s << std::endl;
        ObjectDeClassA1.set_attribute_A3(s);

        std::cout << ObjectDeClassA.get_attribute_A3() << std::endl;
        // se ha pasado por referencia, se ha variado el valor!!
        std::cout << s << std::endl;

        {
            ClassA ObjectDeClasA4; // this object is created and destroyed inside this scope --> scopes define
            std::cout << "hola" << std::endl;
        }
        std::cout << "hola2" << std::endl;
    }
    return 0;
}