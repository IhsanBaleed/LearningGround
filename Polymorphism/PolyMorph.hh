#pragma once
#include <iostream>

class Leader {

public:
    Leader() {
        std::cout << "Leader Construcotr" << std::endl;
    }

    ~Leader() {
        std::cout << "Leader Destructor" << std::endl;
    }

    void do_action() {
        std::cout << "Leader Action" << std::endl;
    }

    virtual void step() {
        std::cout << "Leader Step" << std::endl;
    }

    int power = 0;
};

class Follower : public Leader {

public: 
    Follower() {
        std::cout << "Follower Constructor" << std::endl;
    }

    ~Follower() {
        std::cout << "Follower Destructor" << std::endl;
    }

    void do_action() {
        std::cout << "Follower Action" << std::endl;
    }

    void step() {
        std::cout << "Follower Step" << std::endl;
    }

    void dance() {
        std::cout << "Follower Dance" << std::endl;
    }

    int size = 2;

};

class Second_Follower : public Follower {
    void step() {
        std::cout << "Second Follower Step" << std::endl; // will override the step in Follower
    }
};

void test_polymorphism();

void test_polymorphism_1();

void test_polymorphism_2();

void test_polymorphism_3();





