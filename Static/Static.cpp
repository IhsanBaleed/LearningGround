#include "Static.hpp"

int q = 0;

// for these variables to be used, they must be defined outside the class in a .cpp file.
inline int dummy::i = 0;
inline member dummy::m = member(0);

void dummy::static_func() {
    dance; // can call statuc functions with no issues
    // spin;

    dummy d;
    d.spin(); 
}


void test_static_1() {
    for (int i = 0; i < 4; i++)
        increment();
}

void test_static_2() {

    std::cout << dummy::i << std::endl;

    std::cout << dummy::m.x << std::endl;

    std::cout << dummy::s << std::endl;
}

void test_static_3() {
    static dummy d; // the object will be destroyed after main ends (end of program)
}

void test_static_4() {
    dummy::do_action(); // it is better to call the static function using the class name
    dummy d;
    d.do_action(); // you can also use an object of the class to call the static function
}

void test_static_5() {

    dummy::static_func();
    dummy::static_func_2();

}

void test_static_6() {
    dummy d;
    test_static_7();
}

