#include "classA.h"
#include <iostream>
#include <list>
#include <deque>
using namespace std;

void display_all_from_ClassA(ClassA& Object);

// print elements of a list 
void showList(std::list <int> g);


// print elements of a deque 
void showDeque(std::deque <int> de);

template<typename type>
struct MyAlloc: allocator<type>{
	type * allocate(int size) {
		std::cout << "Allocator Size => " << size << std::endl;
		return new type[size];
	}
};	