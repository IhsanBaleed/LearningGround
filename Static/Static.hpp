#pragma once

#include <iostream>


static int z = 0; 
extern int q;
inline int y = 0;

inline void increment() {
    static int i = 0; // the variable is initialized once
    std::cout << i << std::endl;
    i++;
}


struct member{
    member(int x): x(x) {
        std::cout << "member constructor" << std::endl;
        z++;
        q++;
        y++;
    }

    ~member() {
        std::cout << "member destructor" << std::endl;
    }

    int x;
};

class dummy {

public:
    // the static vars will be initialized before the main function
    static int i; 
    static member m;
    static std::string s;

    dummy(){
        i++;
    }

    int x = 0;

    // we can define the static function in the class
    static void do_action() { 
        std::cout << "do_action" << std::endl;
    }

    static void dance();

    static void static_func();

    static void static_func_2() {
        dance();
        
        // cant call the function or var because it is not static
        // spin(); 
        // x++;
    }

    // non-static functions can call static functions
    void spin() {
        std::cout << "spin" << std::endl;
        do_action(); 
    }
};

// this is allowed in c++17 to set the value within a header file, must use inline though.
inline std::string dummy::s = "dummy";

inline void dummy::dance() {
    std::cout << "dance" << std::endl;
}



void test_static_1();

void test_static_2();

void test_static_3();

void test_static_4();

void test_static_5();

void test_static_6();

void test_static_7();

