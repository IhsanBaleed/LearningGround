#include "FuncPtr.hh" 
#include <iostream>

int func_1() {
    return 7;
}

void func_2(int a, int b){
    std::cout << "func_2" << std::endl;
}

void func_2(int a, int b, int c){
    std::cout << "func_2 overloaded" << std::endl;
}

void func_3(int (*ptr)()) {
    std::cout << "return value is " << ptr() << std::endl;
}

void func_ptr_test_1() {
    int (*f_ptr) (); 
    f_ptr = func_1;

    std::cout << f_ptr() << std::endl; // to call the function pointer, you should use brackets

    // f_ptr = func_2; // wont work as parameters are different

    void (*f_ptr_2) (int, int);
    f_ptr_2 = func_2;

    f_ptr_2(1, 2);

    // f_ptr_2(1,2,3); this wont work, you must use a pointer that supports these params

    // *f_ptr_2(1, 2); // cant use * as it requiers a pointer

    func_3(f_ptr);
}

