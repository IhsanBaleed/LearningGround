#pragma once
#include <iostream>


// array, linked list, queue, map, set, tree, hash tables, iterators

template <typename T>
class Stack {

    /* You can use a vector to allow dynamic allocation of data
    *  Be careful when pushing or popping, always check for current size
    */

    int index = -1; // always points to the top of the list
    int size; // max size
    T* data;

public:

    Stack(int size = 100) : size(size) {
        data = new T[size];
    }

    ~Stack() {
        delete[] data;
    }

    void push(T item) {
        if (index >= size-1) {
            std::cout << "Stack overflown" << std::endl;
            return;
        }
        data[++index] = item;
    }

    T pop() {
        if (index < 0) {
            std::cout << "Stack underflow" << std::endl;
            return T();
        }
        return data[index--];
    }

    T peek() {
        if(index < 0) {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return data[index];
    }

    bool is_empty() {
        return (index < 0);
    }

};

template <typename T>
class SingleLinkedList {
    /* Update the head when inserting or deleting at the start
     * When inserting or deleting at an index, stop before the targeted item
     * Assign Null to head if list has no items
     * To make thinking easier, establish a base case, then use it for more advanced ones, much easier to reason about
    */

private:

    class Node {
        T val;
        Node* next = NULL;

        Node(T val) : val(val){}

        friend class SingleLinkedList;
    };

    Node* head;

public:

    SingleLinkedList(): head(NULL){}

    ~SingleLinkedList() {
        delete_list();
    }

    void print_items() {
        if (!head) {
            std::cout << "No Items in the SLS" << std::endl;
            return;
        }
        Node* current = head;
        while (current) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void insert_at_beginning(T item) {
        if (!head) {
            std::cout << "Head is empty, inserting at the start" << std::endl;
            head = new Node(item);
            return;
        }
        
        Node* new_item = new Node(item);
        new_item->next = head;
        head = new_item;
    }

    void insert_at_end(T item) {
        if (!head) {
            insert_at_beginning(item);
            return;
        }
        Node* new_item = new Node(item);

        Node* current_item = head;
        while (current_item->next) {
            current_item = current_item->next;
        }
        current_item->next = new_item;
    }

    void insert_at_index(int index, T item) {
        if (index == 1 || !head) {
            insert_at_beginning(item);
            return;
        }
        
        // we start at 1 as head is located there
        // we also want to stop just before we insert
        // we iterate until we get the index or we reach end of list.
        Node* current_item = head;
        for (int i=1; i < index -1 && current_item; i++) { 
            current_item = current_item->next;
        }
        if (current_item) {
            Node* new_item = new Node(item);
            new_item->next = current_item->next;
            current_item->next = new_item;
            return;
        }
        std::cout << "Index out of bounds, Inserting at the end" << std::endl;
        insert_at_end(item);
    }

    void delete_list() {

        if(!head) {
            return;
        }

        std::cout << "Deleting List" << std::endl;
        /*
        * to free up memory, try to delete from R to L
        * you already have a hold of head, so start from there
        * get a hold of next then delete current, until the end.
        */        
        Node* current_item = head;
        Node* next_item;
        
        while (current_item) {
            next_item = current_item->next;
            delete current_item;
            current_item = next_item;
        }
        head = NULL; // Very important, delete will give it a wild value, not same as null!!
    }

    void delete_at_start() {
        if (!head) {
            std::cout << "No items to delete" << std::endl;
            return;
        }
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
    }

    void delete_at_end() {
        if (!head) {
            std::cout << "No items to delete" << std::endl;
            return;
        }

        // if we have 1 item, you can be lazy and call delete_at_start
        if (head->next == nullptr) {
            delete head;
            head = NULL;
            return;
        }

        Node* current_item = head;
        while (current_item->next->next) { // before the last item
            current_item = current_item->next;
        }
        delete current_item->next;
        current_item->next = NULL;
    }

    void delete_at_index(int index) {
        if (!head || index < 1) {
            std::cout << "SLS is empty, cant delete" << std::endl;
        }
        if (index == 1) {
            delete_at_start();
            return;
        }

        Node* current_item = head;
        for (int i=1; i < index -1 && current_item; i++) { // stops 1 place before target
            current_item = current_item->next;
        }
        if (!current_item || !current_item->next) { // when we go out of bounds
            std::cout << "Index out of range" << std::endl;
            return;
        }
        Node* target_item = current_item->next; // get target item
        current_item->next = target_item->next; // link the chain
        delete target_item; // remove the item.
    }

    T get_first_item() {
        if(head){
            return head->val;
        }
        std::cout << "SLS is empty" << std::endl;
        return T();
    }

    T get_last_item() {
        if (!head) {
            std::cout << "SLS is empty" << std::endl;
            return T();
        }
        if (!head->next) {
            return head->val;
        }
        Node* current_item = head;
        while (current_item->next) {
            current_item = current_item->next;
        }
        return current_item->val;
    }

    T get_item(int index) {
        if (!head) {
            std::cout << "SLS is empty" << std::endl;
            return T();
        }
        if (index == 1) {
            return get_first_item();
        }
        if (!head->next) {
            std::cout << "Only one item in SLS, here it is: " << head->val << std::endl;
            return get_first_item();
        }

        Node* current_item = head;
        for (int i=1; i < index && current_item; i++) {
            current_item = current_item->next;
        }

        if (current_item) {
            return current_item->val;
        }
        std::cout << "Item out of bounds" << std::endl;
        return T();

    }
};




void test_stack_1();

void test_SLS_1();
void test_SLS_2();
void test_SLS_3();
