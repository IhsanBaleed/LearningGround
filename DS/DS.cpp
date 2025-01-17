#include <DS.hh>


void test_stack_1() {
    int stack_size = 5;
    Stack<double> my_stack(stack_size);

    my_stack.pop();
    my_stack.peek();
    std::cout <<  "Empty stats = " <<  my_stack.is_empty() << std::endl;

    my_stack.push(702);
    my_stack.push(12);
    my_stack.push(9);
    my_stack.push(22);
    my_stack.push(10);
    my_stack.push(122);
    my_stack.push(1444);

    for (int i=0; i < stack_size; i++)
        my_stack.pop();

    my_stack.pop();
    my_stack.pop();

}

void test_SLL_1() {

    SingleLinkedList<int> sll;
    
    sll.print_items();
    sll.insert_at_beginning(22);
    sll.insert_at_beginning(25);
    sll.print_items();

    sll.insert_at_end(13);
    sll.print_items();

    sll.insert_at_index(2, 9);
    sll.insert_at_index(1, 10);
    sll.insert_at_index(22, 8);
    sll.print_items();

}

void test_SLL_2() {
    SingleLinkedList<int> sll;

    sll.delete_at_start();
    sll.delete_at_end();

    sll.insert_at_end(99);
    sll.insert_at_end(12);
    sll.insert_at_end(123);
    sll.insert_at_end(155);
    sll.insert_at_end(98);
    sll.print_items();

    sll.delete_at_start();
    sll.print_items();

    sll.delete_at_end();
    sll.print_items();

    sll.delete_at_index(4);
    sll.print_items();
    sll.delete_at_index(2);
    sll.print_items();
    sll.delete_at_index(2);
    sll.print_items();
    sll.delete_at_index(1);
    sll.print_items();
}

void test_SLL_3() {
    SingleLinkedList<int> sll;

    std::cout << "val = " << sll.get_first_item() << std::endl;
    sll.get_last_item();
    sll.get_item(3);
    
    sll.insert_at_beginning(14);
    sll.insert_at_beginning(22);
    sll.insert_at_beginning(28);
    std::cout << "val = " << sll.get_first_item() << std::endl;
    std::cout << "val = " << sll.get_last_item() << std::endl;
    std::cout << "val = " << sll.get_item(3) << std::endl;
    std::cout << "val = " << sll.get_item(9) << std::endl;


}

void test_DLL_1(){
    DoubleLinkedList<int> dll;

    dll.insert_at_beginning(22);
    dll.insert_at_beginning(44);
    dll.insert_at_beginning(100);

    dll.insert_at_end(7);
}

void test_DLL_2() {
    DoubleLinkedList<int> dll;

    dll.insert_at_beginning(23);
    dll.insert_at_index(2,44);
    dll.insert_at_index(3, 99);
    dll.display_items();
    dll.insert_at_index(2, 88);
    dll.display_items();

    dll.insert_at_index(55, 88);
    dll.display_items();
}

void test_DLL_3() {
    DoubleLinkedList<int> dll;

    dll.delete_at_end();
    dll.insert_at_beginning(22);
    dll.insert_at_beginning(45);
    dll.insert_at_beginning(78);
    dll.display_items();

    dll.delete_at_end();
    dll.display_items();

    dll.delete_at_end();
    dll.display_items();

    dll.delete_at_end();
    dll.display_items();

    dll.delete_at_end();
}

void test_DLL_4() {
    DoubleLinkedList<int> dll;

    dll.delete_at_beginning();
    dll.insert_at_beginning(24);
    dll.display_items();
    dll.delete_at_beginning();

    dll.insert_at_beginning(23);
    dll.insert_at_beginning(55);
    dll.insert_at_beginning(77);
    dll.display_items();

    dll.delete_at_beginning();
    dll.display_items();

    dll.delete_at_beginning();
    dll.display_items();

    dll.delete_at_beginning();
    dll.display_items();

    dll.delete_at_beginning();
}

void test_DLL_5() {
    DoubleLinkedList<int> dll;

    dll.delete_at_index(3);

    dll.insert_at_beginning(4);
    dll.insert_at_beginning(8);
    dll.insert_at_beginning(55);
    dll.insert_at_beginning(33);
    dll.insert_at_index(2, 14);
    dll.display_items();

    dll.delete_at_index(3);
    dll.display_items();
    dll.delete_at_index(1);
    dll.display_items();
    dll.delete_at_index(1);
    dll.display_items();
    dll.delete_all();

    dll.insert_at_beginning(33);
    dll.insert_at_beginning(2);
    dll.insert_at_beginning(55);
    dll.insert_at_beginning(67);
    dll.display_items();
    dll.delete_all();
    dll.display_items();
}

void test_DLL_6() {
    DoubleLinkedList<int> dll;

    std::cout << dll.get_start() << std::endl;
    std::cout << dll.get_end() << std::endl;
    std::cout << dll.get_at_index(1) << std::endl;
    std::cout << dll.get_at_index(5) << std::endl;

    dll.insert_at_beginning(3);
    dll.insert_at_beginning(44);
    dll.insert_at_beginning(436);
    dll.insert_at_beginning(12);
    dll.insert_at_beginning(66);

    std::cout << dll.get_at_index(1) << std::endl;
    std::cout << dll.get_at_index(7) << std::endl;
    std::cout << dll.get_at_index(5) << std::endl;
    std::cout << dll.get_at_index(3) << std::endl;
}

void test_qu_1() {
    Queue<int> q1;

    q1.queue(4);
    q1.queue(2);
    q1.queue(6);
    q1.queue(77);

    std::cout << q1.front() << std::endl;
    std::cout << q1.rear() << std::endl;

    if(q1.is_empty()) {
        std::cout << "Empty" << std::endl;
    }
    q1.print_queue();
    std::cout << q1.size() << std::endl;

    q1.dequeue();       q1.print_queue();
    q1.dequeue();       q1.print_queue();
    q1.dequeue();       q1.print_queue();
    std::cout << q1.front() << std::endl;
    std::cout << q1.rear() << std::endl;

    q1.dequeue(); 
    std::cout << q1.size() << std::endl;

    if(q1.is_empty()) {
        std::cout << "Empty" << std::endl;
    }
}

void test_ht_1() {

    HashTable cars(4);
    
    cars.insert("BMW", 1960);
    cars.insert("Porche", 1982);
    cars.insert("Honda", 2007);
    cars.insert("Mini", 2013);

    cars.display();

    cars.insert("BMW", 1990);
    cars.display();

    cars.remove("Honda");
    cars.remove("Audi");
    cars.display();

    std::cout << "Searching for a mini: " << cars.search("Mini") << std::endl;


}

void test_b_tree1() {

    std::vector<int> data {1,2,3,4,5,6,7};

    BinaryTree tree(data);

    tree.traversal_dfs();
    tree.traversal_bfs();

    tree.insert(10);
    tree.insert(96);

    tree.traversal_bfs();
    tree.traversal_dfs();

    int val = 90;
    if (tree.search_dfs(val)) {
        std::cout << "Found Val " << val << std::endl;
    }

    tree.delete_item(7);
    tree.traversal_dfs();

}

void test_rb_tree_1() {

    RedBlackTree<int> rbt;

    rbt.insert(12);
    rbt.insert(7);
    rbt.insert(30);
    rbt.insert(1);

    std::cout << "Inorder traversal:" << std::endl;
    rbt.inorder(); // Output: 1, 7, 12, 30

    std::cout << rbt.search(1)->data << std::endl;

    std::cout << rbt.search(12)->data << std::endl;

}

