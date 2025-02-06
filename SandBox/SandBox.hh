#pragma once

#include <iostream>
#include <memory>
#include <exception>

class DataType {

public:

    DataType () {
        std::cout << "DataType Construct" << std::endl;
    }

    ~DataType() {
        std::cout << "DataType Destruct" << std::endl;
    }

};

template <typename T>
class Stack {

    int top = -1;
    int max_size;
    T* stack;

public:
    Stack(int size) : max_size(size) {
        stack = new T[max_size];
    }

    ~Stack() {
        delete[] stack;
    }

    void push(T item) {
        if (top < max_size-1) {
            stack[++top] = item;
        } else
            std::cout << "Stack Overflow" << std::endl;
    }

    T pop() {
        if (top > -1) {
            return stack[top--];
        } else 
            std::cout << "Stack Underflow" << std::endl;
        return T();
    }

    int size() {
        return (top + 1);
    }

    bool empty() {
        return (top == -1);
    }

    T peek() {
        if (top > -1)
            return stack[top];
        else 
            std::cout << "Empty Stack" << std::endl;
        return T();
    }

    void exapnd(int factor) {
        int new_size = max_size * factor;
        T* new_stack = new T[new_size];
        for (int i=0; i<=top; i++) {
            new_stack[i] = stack[i];
        }
        delete[] stack;
        max_size = new_size;
        stack = new_stack;
    }
};

template <typename T>
class Queue {

    struct Node {
        Node* next = nullptr;
        T data;
        Node(T item) {
            data = item;
        }
        ~Node() {
            std::cout << "Node Destroyed " << data << std::endl;
        }
    };

    int size_ = 0;

    Node* front = nullptr;
    Node* rear = nullptr;

public:

    ~Queue() {
        
        while (!empty())
            dequeue();
    }
    
    void queue(T item) {

        if (front == nullptr) {
            front = new Node(item);
            rear = front;
        } else {
            Node* node = new Node(item);
            rear->next = node;
            rear = node;
        }
        size_ ++;
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is Empty!" << std::endl;
            return;
        }

        Node* tmp = front;
        front = front->next;

        if (front == nullptr)
            rear = front;

        delete tmp;
        size_--;
    }

    void display() {
        Node* curr = front;

        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    T peek() {
        if (front != nullptr)
            return front->data;
        return T();
    }

    bool empty() {
        return front == nullptr;
    }

    int size() {
        return size_;
    }

};

template <typename T>
class DoubleLinkedList {

    struct Node {
        Node* next;
        Node* prev;
        T data;

        Node(T item) {
            data = item;
            next = nullptr;
            prev = nullptr;
        }

        ~Node() {
            std::cout << "Node Destroyed " << data << std::endl;
        }
    };
    
    Node* start = nullptr;
    Node* end = nullptr;
    std::size_t size_ = 0;

public:

    ~DoubleLinkedList() {
        clear();
    }

    void prepend(T item) {
        if (start == nullptr) {
            start = new Node(item);
            end = start;
        } else {
            Node* new_node = new Node(item);

            start->prev = new_node;
            new_node->next = start;
            start = new_node;
        }
        size_++;
    }

    void append(T item) {
        if (end == nullptr) {
            start = new Node(item);
            end = start;
        } else {
            Node* new_node = new Node(item);

            end->next = new_node;
            new_node->prev = end;
            end = new_node;
        }
        size_++;
    }

    void insert_at_index(int index, T item) {
        if (index < 0 || index > size_)
            return;
        
        if (index == 0) {
            prepend(item);
            return;
        }
        
        if (index == size_) {
            append(item);
            return;
        }

        Node* before = start;
        for (int i=1; i<index; i++) {
            before = before->next;
        }
        Node* new_node = new Node(item);
        Node* after = before->next;

        new_node->next = after;
        after->prev = new_node;

        new_node->prev = before;
        before->next = new_node;
        size_++;      
    }

    void pop_front() {
        if (start != nullptr) {
            if (start == end) {
                delete start;
                end = nullptr;
                start = nullptr;
            } else {
                Node* new_start = start->next;
                delete start;
                start = new_start;
                if (start == end) {
                    start->next = nullptr;
                    start->prev = nullptr;
                }
            }
            size_--;
        }
    }

    void pop_back() {
        if (end != nullptr) {
            if (start == end) {
                delete start;
                end = nullptr;
                start = nullptr;
            } else {
                Node* new_end = end->prev;
                delete end;
                end = new_end;
                if (start == end) {
                    start->next = nullptr;
                    start->prev = nullptr;
                }
            }
            size_--;
        }
    }

    void delete_at_index(int index) {
        if (start != nullptr) {

            if (index == 0)
                pop_front();
            else if (index == size_-1)
                pop_back();
            else if (index < size_ && index > 0) {
                Node* before = start;

                for (int i=1; i<index; i++)
                    before = before->next;
                
                Node* target = before->next;
                Node* after = target->next;
                
                before->next = after;
                after->prev = before;

                delete target;
                size_--;
            }
        }
    }

    void traves_from_start() {
        Node* curr = start;
        while(curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    void traves_from_end() {
        Node* curr = end;
        while(curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->prev;
        }
        std::cout << std::endl;
    }

    T get_item(std::size_t index) {
        if (start != nullptr && index < size_) {
            Node* curr = start;

            for (int i=0; i<index; i++)
                curr = curr->next;

            return curr->data;
        } else 
            throw std::out_of_range("Out of Range");
    }

    T get_front() {
        if (start != nullptr)
            return start->data;
        throw std::out_of_range("Empty List");
    }

    T get_end() {
        if (end != nullptr)
            return end->data;
        throw std::out_of_range("Empty List");
    }

    void assign(std::size_t index, T val) {
        if (start != nullptr && index < size_) {
            Node* curr = start;

            for (int i=0; i<index; i++)
                curr = curr->next;

            curr->data = val;
        } else 
            throw std::out_of_range("Out of Range");
    }

    bool is_empty() {
        return start == nullptr;
    }

    int get_size() {
        return size_;
    }

    void clear() {
        Node* curr = start;
        while (curr != nullptr) {
            Node* target = curr;
            curr = curr->next;
            delete target;
            size_--;
        }
        start = nullptr;
        end = nullptr;
    }
};



class StateMachine {

    class Context {

    protected:

        StateMachine* sm_;

    public:

        virtual void operation_a() = 0;

        virtual void operation_b() = 0;

        Context(StateMachine* sm) : sm_(sm) {}

        virtual ~Context() {
            // when you declare it as virtual, you allow
            // base classes to use their destructors in turn.
            // if not, then only this destructor is called.
            std::cout << "Base State Destructor" << std::endl;
        };
    };

    class StateA : public Context {

    public:

        StateA(StateMachine* sm) : Context(sm) {}

        ~StateA() {
            std::cout << "State A Destroyed" << std::endl;
        }

        void operation_a() override {
            std::cout << "StateA -> OP_A" << std::endl;
        }

        void operation_b() override {
            std::cout << "StateA -> OP_B" << std::endl;
            sm_->change_state(new StateB(sm_));
        }
    };

    class StateB : public Context {

    public:

        StateB(StateMachine* sm) : Context(sm) {}

        ~StateB() {
            std::cout << "State B Destroyed" << std::endl;
        }

        void operation_a() override {
            std::cout << "StateB -> OP_A" << std::endl;
            sm_->change_state(new StateA(sm_));

        }

        void operation_b() override {
            std::cout << "StateB -> OP_B" << std::endl;
        }
    };

    Context* state;

    void change_state(Context* new_state) {
        delete state; // will free the memory up, well done!
        state = new_state;
    }

public:

    StateMachine() {
        state = new StateA(this);
    }

    void operation_a() {
        state->operation_a();
    }

    void operation_b() {
        state->operation_b();
    }

};

class InterfaceA {

    int val;

public:

    InterfaceA(int dummy_val) : val(dummy_val) {}

    virtual void method_a() = 0;

};

class InterfaceB {

    std::string val;

public:

    InterfaceB(std::string dummy_str) : val(dummy_str) {}

    virtual void method_b() = 0;

};

class Concrete : public InterfaceA, public InterfaceB {

public:

    Concrete(int val1, std::string val2) : InterfaceB(val2) , InterfaceA(val1) {}

    void method_a() override {
        std::cout << "Method A" << std::endl;
    }

    void method_b() override {
        std::cout << "Method B" << std::endl;
    }

};


void test_sm();

void test_queue();

void test_dll();

void test_multi_interface_imp();
