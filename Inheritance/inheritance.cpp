#include "inheritance.hh"

int Parent::public_static = 0;
int Parent::protected_static = 0;
int Parent::private_static = 0;

void Parent::state_age() {
    std::cout << "Age: " << age << std::endl;
}

void Parent::state_height() {
    std::cout << "Height: " << height << std::endl;
}

void Parent::state_weight() {
    std::cout << "Weight: " << weight << std::endl;
}

void Parent::state_all() {
    std::cout << "Parent All states" << std::endl;
    state_age();
    state_height();
    state_weight();
}

void Parent::say_hi() {
    std::cout << "Hi Parent" << std::endl;
}

void Derived::state_all() {
    std::cout << "Derived All states" << std::endl;
}

void test_Inheritance() {
    Parent p;
    p.state_age();
    // p.state_height(); only public functions can be called outside the class

    Derived d;
    d.state_all();

    Derived_2 d2;
    // d2.state_all();

    Derived_1 d1;
}


int Derived::state_age(int x){
    std::cout << "Derived Age" << std::endl; 
    return 3;
}

void test_Inheritance_2() {

    Parent p;
    p.state_all();

    Derived d;
    d.state_all();
}

void test_Inheritance_3() {
    Derived_3 d;
    Derived_3 d2(2);

    Derived_2 d2_1;

    Derived_3 d3;
    d3.age = 9;
    d3.public_static = 8; // this change is reflected in all instances that inherit from Parent
}

void test_Inheritance_4() {

    Derived_4 d4(1,2);
}

void test_Inheritance_5() {

    Derived_5 d5;
}

void test_Inheritance_6() {

    Derived d;
}

void test_Inheritance_7() {
    Derived d;
    d.state_age(3);
}

