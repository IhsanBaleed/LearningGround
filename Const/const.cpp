#include <iostream>

#include "const.hh"

void test_const(const int x) {
    std::cout << "x: " << x << std::endl;
    
    // x++; cant change it because it is const
    // const int y; value must be assigned 
    return;
}

const int& return_const() {
    static const int x = 5;
    return x;
    // This will cause an error since we are trying to change a const value
    // const int& y = return_const();
    // y++;
}

void const_ptr_test() {
    int x = 7;
    const int* ptr = &x;
    x++;
    // will cause an error, a const pointer means we cant change the value througt it
    // *ptr += 1;
    int y = 8;
    ptr = &y;
}

void ptr_to_const_test() {
    int x = 7;
    int* const x_ptr = &x;
    // will cause an error, a const pointer means we cant change the value througt it
    // x_ptr = nullptr;
    *x_ptr += 1;
}

void const_ptr_to_const_test() {
    int x = 7;
    const int* const x_ptr = &x;
    // will cause an error, a const pointer means we cant change the value througt it
    // *x_ptr += 1;
    // x_ptr = nullptr;
}

void non_const_param_test(int* x) {
    *x += 1;
    const int y = 8;
    const int* y_ptr = &y;
    // non_const_param_test(&y);
    // non_const_param_test(y_ptr);
    // this would cause an error since we are trying to change a const value
}

void non_const_ptr_test() {
    const int x = 99;
    // this will not work as we can change the value of x using the ptr
    // int* x_ptr = &x;
}

void passing_ptr_to_const_test(int* ptr) {
    *ptr += 1;
    int x = 3;
    int* const x_ptr = &x;
    passing_ptr_to_const_test(x_ptr);
    // this works as x_ptr is constant to the memory location, and not the value
}

void pass_non_const_to_const(const int x) {
    int z = 9;
    pass_non_const_to_const(z);
}

void const_var_ref_test() {
    int x = 7;
    const int& x_ref = x;
    x++;
    // x_ref++;
}

