#include "ExceptionClasses.h"
#include <iostream>
// declaration of the functions --> NOT possible to define the functions inside the main!! since the definitons
// are done in the compiling phase not in the run phase
void main_function(int km, int num1, float hours, float num2);
float function1(int km, float hours);

// function that calculates km/h
float function1(int km, float hours)
{
    try {
        if(hours == 0) {
            throw 0; // int
        }
        if(km < 0) {
            throw .1; // float
        }
        if(hours < 0) {
            throw std::string{ "time cant be negative" };
        }
    }
    // at least a cast() to be present in the function where we have a "try"
    catch(int& ex) {
        std::cerr << "Yout can not divide by 0!" << std::endl;
    }

    return static_cast<float>(km) / hours;
};

// main function
void main_function(int km, int num1, float hours, float num2)
{
    // Inside the "try" block we add what which code is suspicious to arise an exception
    try {
        float speed = num2;
        speed = function1(km, hours);
        std::cout << " Speed is " << speed << std::endl;
    }

    catch(int& ex) {
        std::cerr << "Yout can not divide by 0!" << std::endl;
    } catch(float& ex) {
        std::cerr << "Distance can not be negative!" << std::endl;
    } catch(std::string& ex) {
        std::cerr << ex << std::endl;
    }
}

float calculate_kmph(int km, int hours)
{
    if(hours == 0) {
        throw DevideByZeroException();
    }
    if(km < 0 || hours < 0) {
        throw NegativeValueException();
    }

    return static_cast<double>(km) / hours;
}