#include <iostream>
#include <memory>
#include <string>

class MyClass {

private:

class Data {
public:

    std::string txt = "ABC";

    Data() {
        std::cout << "Data Constructor called" << std::endl;
    }

    ~Data() {
        std::cout << "Data Destructor called" << std::endl;
    }
};

int id=0;

public:

    // To best a shared_ptr within a class, directly use the pointer
    // dont make a raw pointer and have the smart pointer holding it, it will destroy it once out of scoop
    // best approach is to initialize the smart pointer right away
    std::shared_ptr<Data> data_ = nullptr;

    MyClass() {
        std::cout << "Constructor called" << std::endl;
        data_ = std::make_shared<Data>();
    }

    MyClass(int id) {
        std::cout << "Param Constructor called" << std::endl;
        this->id = id;
        data_ = std::make_shared<Data>();
    }

    MyClass(MyClass& source) {
        std::cout << "Copy Constructor called" << std::endl;
        this->id = source.id;
        this->data_ = std::make_shared<Data>();
    }

    ~MyClass() {
        std::cout << "Destructor called ID = " << id << std::endl;
        // no need to destroy the shared pointer, as once it goes out of scope it self destructs
    }
};

static int ID_COUNT = 0;

template<typename T>
class SmartLinkedList {

    class Node; // forward declare
    typedef std::shared_ptr<Node> NODE_SHRD_PTR;
    
    class Node {
    public:
        T id;
        NODE_SHRD_PTR next = nullptr;
        Node(T item) {
            ID_COUNT++;
            id = ID_COUNT;
            std::cout << "Node " << id << " Made" << std::endl;
        }
        ~Node() {
            std::cout << "Node " << id << " Destroyed" << std::endl;
        }
    };

    NODE_SHRD_PTR head = nullptr;

public:

    void insert_at_end(T item) {
        if (head == nullptr) {
            head = std::make_shared<Node>(item);
        }
        else {
            NODE_SHRD_PTR curr = head; 
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = std::make_shared<Node>(item);
        }
    }

    void print_all() {
        NODE_SHRD_PTR curr = head;
        while(curr != nullptr) {
            std::cout << curr->id << " " << std::endl;
            curr = curr->next;
        }
    }

};


// testing code -------------------------------------------------
void dynamic_test_1();

void dynamic_test_2();

void shared_ptr_test_1();

void shared_ptr_test_2();

void shared_ptr_test_3();

void unique_ptr_test_1();

void unique_ptr_test_2();

void unique_ptr_test_3();

void shared_ptr_obj_test();

void test_sll_1();

void test_sll_2();



