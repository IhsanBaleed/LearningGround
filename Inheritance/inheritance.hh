#pragma once
#include <iostream>


struct some_data {
    int x;
    int y;
};


class Parent {

    void say_hi();
    int speed = 0;

    friend class Derived_1; // allows Derived_1 to access private members of Parent

public:


    Parent() {
        std::cout << "Parent default constructor" << std::endl;
    }

    Parent(int age) : age(age), speed(2), weight(3) {
        std::cout << "Parent Paremeterised constructor" << std::endl;
    }

    int age = 0;
    void state_age();
    void state_all();
    static int public_static;

protected:
    int height = 0;
    void state_height();
    static int protected_static;

private:
    int weight = 0;
    void state_weight();
    some_data data;
    static int private_static;
};



class Derived : public Parent { // public here means all public and protected members of Parent keep their state in Derived

public:
    Derived() {
        Parent::age = 22;
        age = 1;
        height = 1;
        // speed = 3; // default access specifier is private
        //  weight = 1; //cant access it since it is private
    }

    double age; // age variable from Parent is encapsulated by Parent

    void state_all(); // overrides the state_all function in Parent
    int state_age(int x);
};


class Derived_1 : public Parent { 
    
    int weight = 9; // a firend class can see all private members of a class even if not derived from it

public:
    Derived_1() {
        weight = 1; // can access it since it is a friend
    }
};


class Derived_2 : private Parent { // Private here means all public and protected members of Parent are private in Derived_2

public:
    Derived_2() {
        age = 1;
        height = 1;
        // weight = 1; still cant access it, the private keyword above has no effect on it.
    }
};


class Derived_3 : public Parent { 

public:
    Derived_3()  : Parent(1) { // this implicity calls the default constructor of Parent
        std::cout << "Derived_3 default constructor" << std::endl;
    }

    Derived_3(int x) : Parent(1) { // this explicitly calls the parameterised constructor of Parent
        std::cout << "Derived_3 parameterised constructor" << std::endl;
        age = 4;
        state_all();
    }

};


class Human {

public:
    // Human() {
    //     std::cout << "Human default constructor" << std::endl; 
    // }
    Human(int iq, int health) : iq(iq), health(health) {
        std::cout << "Human parameterised constructor" << std::endl;
    }

protected:
    int iq = 5;
    int health;

};


class Derived_4 : public Parent, public Human { // Multiple inheritance

public:
    // this will not work since the default constructor of Human is not defined and they are implicitly called.
    // Derived_4() {
    //     std::cout << "Derived_4 default constructor" << std::endl;
    // }

    Derived_4(int iq, int health) : Human(iq, health), Parent() {
        std::cout << "Derived_4 parameterised constructor" << std::endl;
    }
};

class Derived_5 : Derived_4{ // multilevel inheritance

public: 
    Derived_5() : Derived_4(1, 2) {
        std::cout << "Derived_5 default constructor" << std::endl;
    }
};


void test_Inheritance();

void test_Inheritance_2();

void test_Inheritance_3(); 

void test_Inheritance_4();

void test_Inheritance_5();

void test_Inheritance_6();

void test_Inheritance_7();




