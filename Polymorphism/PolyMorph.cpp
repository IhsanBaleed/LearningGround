#include "PolyMorph.hh"

void test_polymorphism() {
    Leader l;
    Follower f;

    l.do_action();
    f.do_action(); // the ovverride in Follower is called
}

void test_polymorphism_1() {
    Leader l = Follower();

    l.do_action(); // the ovverride in Follower is not called
}

void test_polymorphism_2() {

    Leader polymorph = Follower();
    polymorph.step();  // does not call the override in Follower becuase slicing occurs

    Leader* ldr_ptr;
    Follower f;

    ldr_ptr = &f;
    ldr_ptr->step(); 
    // ldr_ptr->size++; will not work, the base pointer is not aware of the derived class members or methods
    // ldr_ptr->dance();
}

void take_object(Leader* ldr_ptr, Leader ldr_obj, Follower* flw_ptr, Follower flw_obj) {
    ldr_ptr->step();
    ldr_obj.step(); 
    flw_ptr->step();
    flw_obj.step();
}

void test_polymorphism_3() {
    Follower f;
    Second_Follower sf;
    take_object(&f,f, &f,f); // a base pointer or base object can take a derived object regardless of level of inheritance
    take_object(&sf,sf, &sf,sf);
}




