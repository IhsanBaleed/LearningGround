#pragma once

#include <iostream>


template <typename T>
void template_func_1(T t) {
    std::cout << "Template Func 1" << std::endl;
}

template <typename T>
void template_func_2() {
    T t = 123;
    std::cout << "Template Func 2" << std::endl;
}

template <int x> // x here is a non-type param, best way to use it is in template specialization
void template_func_3() {
    std::cout << "Template Func 3 " << x << std::endl;
}

template <int x = 9>
void template_func_4() {
    std::cout << "Template Func 5 " << x << std::endl;
}

template <typename T>
void template_func_5() {
    static int x = 0; // each unique set of template params will have their own static var
    std::cout << "Template Func 5, x: " << x++ << std::endl;
}

template <typename T>
inline void template_func_6(T t) {
    std::cout << "Template Func 6" << std::endl;
}

template <> // full specialization
inline void template_func_6<int>(int t) {
    std::cout << "Template Func 6, int" << std::endl;
}

// would not work, the general function had the template params same as function's params
// template <>
// void template_func_6<int>(double t) {
//     std::cout << "Template Func 6, int" << std::endl;
// }


inline void template_func_6(float f) { // you can overload a function with templated functions
    std::cout << "Template Func 6, float" << std::endl;
}

template <typename T, typename V>
inline void template_func_7(T t, V v) {
    std::cout << "Template Func 7" << std::endl;
}

template <>
inline void template_func_7<int, double>(int t, double v) {
    std::cout << "Template Func 7, int, double" << std::endl;
}

// would not work, partial specialization is only allowed for class templates
// template <typename T>
// inline void template_func_7<T, double>(T t, double v) {
//     std::cout << "Template Func 7, T, double" << std::endl;
// }

// template <typename T>
// inline void template_func_7<T, T>(T t, T v) {
//     std::cout << "Template Func 7, T, double" << std::endl;
// }


// Helper function to print a single argument
// will execute for every argument in the parameter pack
template <typename T>
void print_arg(const T& arg) {
    std::cout << arg << ' '; 
}

inline void display(int x) {
    std::cout << "Value of x = " << x << std::endl;
}

template <typename... Types>
inline void template_func_8(Types... args) {
    (display(args), ...); // Fold expression to expand the parameter pack
}

inline void template_func_9() {
    std::cout << "template_func_9 called" << std::endl;
}

template <typename T, typename... Types>
inline void template_func_9(T t, Types... args) {
    std::cout << "Param t = " << t << std::endl;
    template_func_9(args...); // using recurssion to expand the parameter pack
}

template <int> // same as template <int x>
void template_func_10() {
    std::cout << "Template Func 10" << std::endl;
}


void tempalte_func_test();

void tempalte_func_test_1();

void template_func_test_2();

void template_func_test_3();

void template_func_test_4();

void template_func_test_5();


