#pragma once

#include <iostream>
#include <memory>

class DT {

public:

    DT () {
        std::cout << "DT Construct" << std::endl;
    }

    ~DT() {
        std::cout << "DT Destruct" << std::endl;
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

void test_sm();
