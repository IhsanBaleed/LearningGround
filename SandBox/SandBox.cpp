#include "SandBox.hh" 

void test_sm() {
    StateMachine sm;

    sm.operation_a();

    sm.operation_b();

    sm.operation_a();
}

void test_queue() {
    
    Queue<int> q1;

    q1.dequeue();

    q1.queue(4);
    q1.queue(5);
    q1.queue(6);
    q1.queue(7);

    if (q1.empty())
        std::cout << "Got item" << std::endl;

    q1.display();

    std::cout << q1.size() << std::endl;

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    if (q1.empty())
        std::cout << "Empty" << std::endl;

    q1.display();

    q1.queue(10);

    std::cout << q1.peek() << std::endl;

}

void test_dll() {
    
    DoubleLinkedList<int> dll;

    dll.insert_at_index(4, 12);
    dll.insert_at_index(-1, 12);

    dll.insert_at_index(0, 12);
    dll.insert_at_index(1, 88);
    dll.insert_at_index(2, 73);
    dll.traves_from_start();
    dll.traves_from_end();
    dll.insert_at_index(2, 42);
    dll.traves_from_start();
    dll.traves_from_end();

    dll.pop_front();
    dll.pop_front();
    dll.traves_from_start();
    dll.pop_front();
    dll.insert_at_index(1, 13);
    dll.pop_front();
    dll.traves_from_start();
    dll.pop_front();
    dll.pop_front();
    dll.traves_from_start();

    std::cout << "Round 2" << std::endl;

    dll.delete_at_index(0);
    dll.delete_at_index(1);
    dll.append(12);
    dll.append(34);
    dll.append(67);
    dll.append(52);
    dll.append(22);
    dll.append(55);
    dll.append(60);

    dll.traves_from_end();

    std::cout << dll.get_end() << std::endl;
    std::cout << dll.get_front() << std::endl;

    std::cout << dll.get_item(4) << std::endl;

    dll.delete_at_index(3);
    dll.delete_at_index(2);
    dll.delete_at_index(0);
    dll.delete_at_index(1);

    dll.assign(1, 777);
    dll.traves_from_start();
    dll.clear();

}

void test_multi_interface_imp() {

    // the concrete class can be used in place
    // of either interfaces
    // each interface has access only to its own methods
    // you cant use the interfaces in a class fashion, duh!

    Concrete c1(1, "abc");

    InterfaceA* i_a = &c1;
    i_a->method_a();

    InterfaceB* i_b = &c1;
    i_b->method_b();

    c1.method_a();
    c1.method_b();
}


