#include "Interfaces.hh"

void Interface::spin_around() {
    std::cout << "Interface Spinning around" << std::endl;
}

void Interface::do_action() { // we can define the functions too
    std::cout << "Doing action" << std::endl;
}

void Concrete::jump() {
    std::cout << "Concrete Jumping" << std::endl;
}



void test_interface(){
    // Interface i; // we cant do this since the class is abstract
}

void test_interface_1() {

    Concrete c;
    c.do_action();
    c.jump();
}

void test_interface_2() { 

    Interface* i = new Concrete();
    i->do_action();
    i->jump();
    i->spin_around();

    delete i;

    Concrete c;
    i = &c;

    i = new Concrete(4);
    // i->dive(); // we still cant call child class functions, since the interface cant see them.
    delete i;
}

void acquire_interface_ptr(Interface* i) {
    i->do_action();
    i->jump();
    i->spin_around();
}

void test_interface_3() {
    Concrete c;
    acquire_interface_ptr(&c);

    Concrete* c2 = new Concrete();
    acquire_interface_ptr(c2);
}

// void acquire_interface_obj(Interface i) { // this will not work since the object is abstract
//     i.do_action();
//     i.jump();
//     i.spin_around();
// }



