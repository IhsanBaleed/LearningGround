#pragma once

#include <string>
#include <iostream>


class toy {

public:

    void operator ++(int value){ // postfix operator, x++;
        std::cout << "operator ++(int value)" << std::endl;
    }

    void operator ++(){ // prefix operator, ++x;
        std::cout << "operator ++()" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const toy& t);

    int size = 0;
};

class dummy {

public:
    std::string name;

    dummy(std::string name) : name(name) {}

    void operator + (const dummy& d) { // the LHS param is implicit, and it is passed as *this
        name += d.name;
        std::cout << "new name: " << name << std::endl;
    }

    dummy operator + () { 
        std::cout << "overloaded with int " << std::endl;
        return dummy("new");
    }

    void operator + (toy t) {
        name += " toy";
        std::cout << "new name: " << name << std::endl;
    }


// this would not work, since operator + can only take zero or one argument
// the + operator takes an implicit this pointer, when defined in this class context
    // void operator + (const dummy& d, const dummy& d2) { 
    //     name += " toy";
    //     std::cout << "new name: " << name << std::endl;
    // }

// this would work, since the operator + is defined outside the class context and is declared as a firend operatpr.
    friend dummy operator+(dummy const& c1,
                            dummy const& c2) {
        return dummy(c1.name + " " + c2.name + " toy");
    }

    // void operator - (const dummy& d1, const dummy& d2) {
    //     std::cout << "operator - (const dummy& d1, const dummy& d2)" << std::endl;
    // }



};

class Fraction {
private:
    int num, den;

public:
    Fraction(int n = 0, int d = 0)
    {
        num = n;
        den = d;
    }

    // this operator is implicitly called when a float is assigned to a var of type Fraction.
    operator float() const
    {
        return float(num) / float(den);
    }

    void print() const
    {
        std::cout << num << "/" << den << std::endl;
    }
};


class MyClass {

    std::string* data;

public:

    MyClass(std::string obj_name) {
        data = new std::string(obj_name);
    }

    ~MyClass() {
        if (data)
            delete data;
    }

    MyClass(const MyClass& src) {
        this->data = new std::string(*src.data);
        std::cout << "Copy constructor called" << std::endl;
    }

    // move constructor
    // if the source has other data, you should use std::move on them
    MyClass(MyClass&& src) {
        // "steal" the pointer address
        // then set the source to null, thus it wont be double deleted
        this->data = src.data;
        src.data = nullptr;
        std::cout << "Move constructor called" << std::endl;
    }

    // move operator returns a ref object
    // they take a mutable rvalue just like move constructor
    MyClass& operator= (MyClass&& src) {

        // always check for self assignment
        if (this == &src)
            return *this;
        
        this->data = src.data;
        src.data = nullptr;
        std::cout << "Move operator called" << std::endl;

        // always return the object
        return *this;
    }

};

void test_case();

void test_case_2();

void test_case_3();

void test_case_4();

void test_case_5();

void test_case_6();

void test_case_7();

void test_case_8();

