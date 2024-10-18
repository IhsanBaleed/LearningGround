#pragma once

#include <iostream>

class TestSubject {
    
    public:
    TestSubject() = default;
    TestSubject(int x, int y, int z);

    TestSubject(const TestSubject& other); // copy  constructor
    TestSubject(const TestSubject&& other); // move constructor

    int x;
    int y;
    int z;
    
    int* ptr = &x;

};

class TestSubject2 {
    
    public:
    TestSubject2() = delete;

    int x;
    int y;
    int z;
};

struct Dummy {
    int x;
    int y;
    int z;
};


void test_classes();

void test_classes2();

void test_classes3();