#include "ptr_tests.h"
#include <memory>


void ptr_test() {

    int x = 5;
    int* x_ptr = &x;

    int y = 10;
    int* y_ptr = &y;

    int diff = y_ptr - x_ptr;

    std::cout << "Difference: " << diff << std::endl;

    parent* p_ptr = new parent();
    std::cout << p_ptr->x << std::endl;

    void* void_ptr = &x;

    y = *(int*)void_ptr;

    std::cout << "Y: " << y << std::endl;
}

void reference_test(){
    parent p;
    parent &ref = p;
    std::cout << "p.X: " << p.x << std::endl;
    std::cout << "ref.X: " << ref.x << std::endl;

    parent p2;
    p2.x = 10;
    ref = p2;
    std::cout << "p.X: " << p.x << std::endl;
    std::cout << "p2.X: " << p2.x << std::endl;
    std::cout << "ref.X: " << ref.x << std::endl;

    ref.increment_x();
    std::cout << "p.X: " << p.x << std::endl;
    std::cout << "p2.X: " << p2.x << std::endl;
    std::cout << "ref.X: " << ref.x << std::endl;
}

void reference_test_2() {
    int x = 5;

    int* x_ptr = &x;

    int x_ref = *x_ptr;

    x_ref++;
}

parent reference_test_3() {
    parent p;

    p.x = 77;
    return p;
}

void smart_ptr_test() {
    parent* p_ptr = new parent(7);

    int *int_ptr = new int(8);

    parent p(8);

    std::shared_ptr<parent> p_shared(&p); 

    int z = 73;

    std::shared_ptr<int> int_shared0 = std::make_shared<int>(8); //constructor takes a value
    std::shared_ptr<int> int_shared1 = std::make_shared<int>(*int_ptr); //constructor takes a value
    std::shared_ptr<int> int_shared2 = std::make_shared<int>(z); //constructor takes a value
    
    std::shared_ptr<int> int_shared3(new int(32)); //constructor takes a reference
    std::shared_ptr<int> int_shared4(int_ptr); //constructor takes a reference
    std::shared_ptr<int> int_shared5(&z); //constructor takes a reference
}

parent& reference_test_4() {
    parent p;

    p.x = 77;
    return p;
}

void ptr_operator_test(){

    parent p;
    parent* p_ptr = &p;
    std::cout << "p.X: " << p.x << std::endl;
    std::cout << "p_ptr->X: " << p_ptr->x << std::endl;


    p_ptr->increment_x();
    std::cout << "p.X: " << p.x << std::endl;
    std::cout << "p_ptr->X: " << p_ptr->x << std::endl;
}

int& ref_bug()
{
    int x = 10;
    return x;
}

void assign_shared_ptr_val(parent& p) {
    std::shared_ptr<parent> p_shared = std::make_shared<parent>(p);
    p.increment_id();
    p.print();
}

void uniqe_ptr_test() {

    parent* p = new parent(7);
    std::unique_ptr<parent> p_unique(p);

    std::unique_ptr<parent> p_unique2(p);
    
    
    p_unique->print();
    p_unique2->print(); // will segfault because p_unique2 is pointing to the same memory as p_unique

}

void unique_ptr_test_2() {
    std::unique_ptr<parent> p_unique;

    parent* p = new parent(7);
    p_unique = std::unique_ptr<parent>(p);

    std::unique_ptr<parent> p_unique2(p); // will cause a double deletion and a segfault

    std::unique_ptr<parent> p_unique3 = std::make_unique<child>();
}

