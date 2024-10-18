#pragma once

class Child {

public:
    std::string child_name;
    int child_id;
    mutable int child_size;

    void child_method() {
        std::cout << "Child Name: " << child_name << std::endl;
        std::cout << "Child ID: " << child_id << std::endl;
    }

    void do_something () const {
        std::cout << "Doing something" << std::endl;
        int z = 999;
        z++;
    }

    void increment_vars() {
        child_id++;
    }
    // the method is marked as const, thus it cant modify the object's parameters 
    void try_increment_vars () const {
        // child_id++; this will cause an error since the method is const
        int val = 5;
        do_something(); // can call this one since it is const
        // increment_vars(); cant call this one since it is not const
        child_size++; // this works since it is mutable
    }
};

class Student {

public:
    std::string name;
    int id;
    Child child;

    Student(std::string name, int id) {
        this->name = name;
        this->id = id;
    }
};


class ConstTest {

public:
    ConstTest(int val) : z(val), child(Child()) {
        x = 0;
        // child.child_method(); // const objects can only call const methods
        child.do_something();
        child.try_increment_vars();

        Child child2;
        child2.do_something();
        child.try_increment_vars();
    }

    void print_vars(){
        std::cout << "t: " << t << std::endl;
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    }

    const int get_y() {
        return y;
    }

    const int get_x() {
        return x;
    }

    void increment_vars() {
        x++;
        t++;
    }

    void testing_const() const {
        child.do_something();
        // child.child_method();
    }

    int t = 0;
    int x = 0;
    const int y = 3;
    const double z;
    mutable int q = 0;

    const Child child; // since its const, we can intilise here using const Child child(); or using the initializer list
    Student student = Student("Mike", 22); // since it has no default constructor, it be initialized here or in the initializer list
};


void test_const(const int x);

const int& return_const();

void const_ptr_test();

void ptr_to_const_test();

void const_ptr_to_const_test();

void non_const_param_test(int* x);

void non_const_ptr_test();

void passing_ptr_to_const_test(int* ptr);

void pass_non_const_to_const(const int x);

void const_var_ref_test();

