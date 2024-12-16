#pragma once

#include <iostream>

void lambda_test_1();

void lambda_test_2();


class Functor {

private:
    int x;

public:
    Functor(int val) : x(val) {

    }

    int operator() (int num) {
        std::cout << "Operator called" << std::endl;
        x += num;
        return x + num;
    }

};

void test_functor_1();

