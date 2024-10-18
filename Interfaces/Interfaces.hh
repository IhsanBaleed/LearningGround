#pragma once
#include <iostream>

class Interface {

public:

    Interface(){
        std::cout << "Interface constructor" << std::endl;
    }

    Interface(int x){
        std::cout << "Interface Parameterised constructor" << std::endl;
    }


    virtual void do_action() = 0;
    virtual void jump() = 0;

    void spin_around(); // we can have functions that are not pure virtual

protected:

    int num_of_actions;
    bool in_transit;

};

class Concrete : public Interface {

public:

    Concrete() : Interface(5){
        std::cout << "Concrete constructor" << std::endl;
    }

    Concrete(int x){
        std::cout << "Concrete Parameterised constructor" << std::endl;
    }

    void do_action() {
        std::cout << "Concrete doing action" << std::endl;
    }

// this counts as a definition, since it does not have the = 0
// but it will throw a linker error since it cant find the definition for this function if we use it.
    void jump(); 

    void dive() {
        std::cout << "Concrete diving" << std::endl;
    }

};




void test_interface();

void test_interface_1();

void test_interface_2();

void test_interface_3();



