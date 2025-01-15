#include "Exceptions.hh"
#include <stdexcept>
#include <iostream>

struct Exceptions
{

};

void func1 () {

    Exceptions e1;

    throw e1; // this will make the program throw an exception of the given type.
}

void func2()  noexcept(false) {

    // using noexcept(true) or noexcept means that it will never throw an error
    // if you use noexcept(false) it means that it may throw an error
    // throw(int) 

    throw 3;
}

void test_exception_1() {

    try {
        func1();
        std::cout << "This will never exceute";
    } catch(Exceptions e) { 
        // this will catch only the type thrown, you can use catch(...)
        // to catch all types
        std::cout << "Got EM" << std::endl;
    }
}

// you can nest them inside each other too
void test_exception_2() {
    try {
        try {
            func1();
        } catch (...) {
            
            try
            {
                func2();
            }
            catch(const int e)
            {
                std::cerr << "Got an INT" << std::endl;
            }
        }
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}




