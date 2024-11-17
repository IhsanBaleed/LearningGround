#include "LR_vals.hh"

std::string helper_func_1() {
    return "Helper called";
}

int helper_func_2(int val) {
    static int num = 3;
    return num;
}

void helper_func_3(int& val) {

}

void helper_func_4(int&& val) {

}

void helper_func_5(const int& val) {

}

void LR_val_test1() {

    int y = 3;
    int x = 2; // works, lvalue assigned an rvalue

    // 4 = x; // will not work, value 4 is not accessible in memory (has no object)
    x = x + y; // works, "x+y" returns an R value
    x = y; // also work, an lvalue can be set to another lvalue

    std::string text = helper_func_1(); // works, lvalue is given an rvalue
    // helper_func_1() = "ABC"; // does compile, but it is a bad practice and uselss, unless the returned value is not released

    // 4 = 5; // rvalue cant be assigned to another rvalue
    const std::string &val = "val"; // to assign a reference to an rvalue, it must be const, so we cant modify the literal
}

void LR_val_test2() {

    // int& ref = helper_func_2(3);

    int x = 1;
    int y = 2;

    helper_func_2(x); // works as lvalue is given another lvalue
    helper_func_2(x+y); // also works, an lvalue is given an rvalue

    // helper_func_3(x+y); // wont work, the param is a reference and we cant reference literals, we can hold their values but not reference them

    // to capture an rvalue, use &&
    // helper_func_4(x); wont work, cant assign an lvalue to an rvalue
    helper_func_4(x+y); // this works, rvalue assigned an rvalue

    // to hold both type of values, make the varaible a const reference, this means that it will point to a literal that will not move.
    helper_func_5(x+y);
    helper_func_5(x);
}

    // an rvalue can be:
    // the return of a result from a function, a literal, a moved object using && or an object declared using &&
    // they are meant to be used on the RHS of an assignment, and must be assigned to an lvalue
    // you cant assign an rvalue to itself, nor you can assign rvalue to a reference (except if it is const)

    // an lvalue:
    // is a var that holds a place in memory
    // can assign an lvalue to another lvalue, and can hold an rvalue
    // a reference is considered an lvalue, but it cant be given an rvalue (unless the reference var is const)
    // if you have an rvalue variable (using &&) it must take an ravalue


