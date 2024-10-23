#include "Static.hpp"


void test_static_7() {

    // the variable will stay zero, since every translation unit will have its own copy
    std::cout << "value of global static z = " << z << std::endl;

    // static class variables retain their value, since they are shared between all translation units
    std::cout << "value of global static dummy::i = " << dummy::i << std::endl;

    // one way to make this work is to use extern
    std::cout << "value of global static q = " << q << std::endl;
    // you can also make a normal variable, which can act as a global variable
    std::cout << "value of global static y = " << y << std::endl;
}