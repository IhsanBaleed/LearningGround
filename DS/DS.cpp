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

void test_SLS_1() {

    SingleLinkedList<int> sls;
    
    sls.print_items();
    sls.insert_at_beginning(22);
    sls.insert_at_beginning(25);
    sls.print_items();

    sls.insert_at_end(13);
    sls.print_items();

    sls.insert_at_index(2, 9);
    sls.insert_at_index(1, 10);
    sls.insert_at_index(22, 8);
    sls.print_items();

}

void test_SLS_2() {
    SingleLinkedList<int> sls;

    sls.delete_at_start();
    sls.delete_at_end();

    sls.insert_at_end(99);
    sls.insert_at_end(12);
    sls.insert_at_end(123);
    sls.insert_at_end(155);
    sls.insert_at_end(98);
    sls.print_items();

    sls.delete_at_start();
    sls.print_items();

    sls.delete_at_end();
    sls.print_items();

    sls.delete_at_index(4);
    sls.print_items();
    sls.delete_at_index(2);
    sls.print_items();
    sls.delete_at_index(2);
    sls.print_items();
    sls.delete_at_index(1);
    sls.print_items();
}

void test_SLS_3() {
    SingleLinkedList<int> sls;

    std::cout << "val = " << sls.get_first_item() << std::endl;
    sls.get_last_item();
    sls.get_item(3);
    
    sls.insert_at_beginning(14);
    sls.insert_at_beginning(22);
    sls.insert_at_beginning(28);
    std::cout << "val = " << sls.get_first_item() << std::endl;
    std::cout << "val = " << sls.get_last_item() << std::endl;
    std::cout << "val = " << sls.get_item(3) << std::endl;
    std::cout << "val = " << sls.get_item(9) << std::endl;


}



