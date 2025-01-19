#include "SandBox.hh" 

void test_sm() {
    StateMachine sm;

    sm.operation_a();

    sm.operation_b();

    sm.operation_a();
}
