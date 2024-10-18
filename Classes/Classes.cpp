#include "Classes.hh"

//since this is declared as default, we cannot define it.
// TestSubject::TestSubject() { 
//     std::cout << "TestSubject constructor called" << std::endl;
// }

TestSubject::TestSubject(int x, int y, int z) {
    std::cout << "TestSubject constructor called" << std::endl;
    this->x = x;
    this->y = y;
    this->z = z;
}

TestSubject::TestSubject(const TestSubject& other) {
    std::cout << "TestSubject copy constructor called" << std::endl;
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

TestSubject::TestSubject(const TestSubject&& other) {
    std::cout << "TestSubject move constructor called" << std::endl;
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

void test_classes() {
    TestSubject s1 = {}; // the curly brackes take the same arguments as the constructor
    TestSubject s2;
    TestSubject s3(1,2,3);
    TestSubject s4 = {1,2,3};

    Dummy d1 = {1,2,3}; // only structs can be initialized like this

    // TestSubject2 s4; wont work since we disabled the default constructor.
}

void test_classes2() {
    TestSubject s1(1,2,3);
    TestSubject s2(s1); // will use the copy consturctor
    TestSubject& s3(s1);
    s1.x++;
}

void test_classes3() {
    TestSubject s1(1,2,3);
    TestSubject s2(std::move(s1));
    *s1.ptr += 1; // dangrous to do, might cause undefined behaviour
}







