#pragma once
#include <iostream>


struct parent {

    int x = 99;

    int id;

    void increment_x() {
        x++;
    }

    parent(int id = 0) : id(id) {
        std::cout << "parent constructor" << std::endl;
    }

    ~parent() {
        std::cout << "parent destructor" << std::endl;
    }

    void print() {
        std::cout << "My id: " << id << std::endl;
    }

    void increment_id() {
        id++;
    }

};

struct child : parent {

    child () {
        std::cout << "child constructor" << std::endl;
    }
};



void ptr_test();

void reference_test();

void reference_test_2();

parent reference_test_3();

parent& reference_test_4();

void ptr_operator_test();

void smart_ptr_test();

int& ref_bug();

void assign_shared_ptr_val(parent& p);

void uniqe_ptr_test();

void unique_ptr_test_2();
