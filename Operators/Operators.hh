#pragma once

#include <string>
#include <iostream>


class toy {

    int size = 0;

public:

    void operator ++(int value){ // postfix operator, x++;
        std::cout << "operator ++(int value)" << std::endl;
    }

    void operator ++(){ // prefix operator, ++x;
        std::cout << "operator ++()" << std::endl;
    }

    

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


void test_case();

void test_case_2();

void test_case_3();

void test_case_4();

void test_case_5();
