#include <thread>
#include <iostream>


class MyClass {

public:
    void Do_something(int val);

    // a functor (which is simply an overwrite of the () operator)
    void operator() (int var);

    static void static_method();
};




void test_threads_1();

void test_threads_2();

void test_threads_3();

void test_threads_4();

void test_thread_5();

