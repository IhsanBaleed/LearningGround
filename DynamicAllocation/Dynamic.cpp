#include "Dynamic.hh"

void dynamic_test_1() {

    // will not work, as new returns a pointer
    // MyClass c1 = new MyClass;

    // will construct the object, but not destroy it
    // must have a default construcr, or supply params for available constructor
    MyClass* ptr = new MyClass;

    // will call the destructor
    delete ptr;

    // makes an array of 10 dynamic objects
    // the constructor will be called on all of them
    // will only work with default constructor 
    MyClass* arr_ptr = new MyClass[10];

    // will call the destructor on all objects within the array.
    delete[] arr_ptr;
}

void dynamic_test_2() {

    // there is a leak, since the first object made was not destroyed
    MyClass* ptr = new MyClass(1);

    ptr = new MyClass(2);

    delete ptr;
}

void shared_ptr_test_1() {

    MyClass* raw_ptr = new MyClass(77);

    MyClass c1(22);

    // will call the destructor once the shared_ptr goes out of scope
    // allows us to dynamically allocate, without the worry of destroying the object
    // the parameters for a shared_ptr must be a reference to a var
    // ie: a ptr, using new or passing a ref
    std::shared_ptr<MyClass> ptr1(raw_ptr);
    std::shared_ptr<MyClass> ptr2(new MyClass(4));
    std::shared_ptr<MyClass> ptr3(&c1);


    // this will cause a segfault 
    // ptr4 will delete the object, while ptr5 will try to delete again
    // to make shared_ptr point to the same object, make one equal the other
    MyClass* raw_ptr_2 = new MyClass(12);
    std::shared_ptr<MyClass> ptr4(raw_ptr_2);
    std::shared_ptr<MyClass> ptr5(raw_ptr_2);
}

void shared_ptr_test_2() {

    MyClass* raw_ptr = new MyClass(1);
    MyClass obj(13);

    // this will construct a new object, using normal constructor
    std::shared_ptr<MyClass> shrd_1 = std::make_shared<MyClass>(88); 

    // these will make a new object, using copy constructor
    std::shared_ptr<MyClass> shrd_2 = std::make_shared<MyClass>(*raw_ptr);
    std::shared_ptr<MyClass> shrd_3 = std::make_shared<MyClass>(obj);

    // make_shared will always use the constructor's of the type
}

void shared_ptr_test_3() {
    std::shared_ptr<MyClass> sh1(new MyClass(33));
    
    // this allows multiple hared_ptrs to poin to one object
    std::shared_ptr<MyClass> sh2 = sh1;

}

void unique_ptr_test_1() {
    
    std::unique_ptr<MyClass> uniq_ptr (new MyClass(7));

    MyClass c1(27);
    std::unique_ptr<MyClass> u0(&c1);

    // causes a double deletion and a segfault, similar to shared_ptr situation
    MyClass* ptr = new MyClass(22);
    std::unique_ptr<MyClass> u2 (ptr); 
    std::unique_ptr<MyClass> u3 (ptr); 
}

void unique_ptr_test_2() {

    std::unique_ptr<MyClass> u1 = std::make_unique<MyClass>(12);
    std::unique_ptr<MyClass> u2 = std::make_unique<MyClass>();

    MyClass obj1(123);
    std::unique_ptr<MyClass> u3 = std::make_unique<MyClass>(obj1);
}

void unique_ptr_test_3() {

    std::unique_ptr<MyClass> u1 (new MyClass(123));

    // the new unique_ptr cant be assigned to another one, this insuring uniqueness.
    // std::unique_ptr<MyClass> u2 = u1;

}

void shared_ptr_obj_test() {
    // will apply destruction only to the parent object
    // if the object has other dynamically allocated members, they will not be freed
    // each dynamic object must be assigned through a smart pointer
    std::shared_ptr<MyClass> sh1 (new MyClass(123)); 

    std::cout << "Doing something" << std::endl;
}

void test_sll_1() {

    // once the sll is out of scope it is destroyed
    // thus the nodes are out of scope
    // this will trigger the shared_ptrs to destroy themselves and free the nodes
    SmartLinkedList<int> sll;

    sll.insert_at_end(1);
    sll.insert_at_end(2);
    sll.insert_at_end(3);
    sll.insert_at_end(4);

    sll.print_all();
}

void test_sll_2() {

    SmartLinkedList<int>* sll_ptr = new SmartLinkedList<int>;

    sll_ptr->insert_at_end(4);
    sll_ptr->insert_at_end(5);
    sll_ptr->insert_at_end(77);
    sll_ptr->insert_at_end(48);

    sll_ptr->print_all();

}

