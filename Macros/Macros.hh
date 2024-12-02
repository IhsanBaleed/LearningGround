
#include <stdio.h>
#include <string>

struct dummy_data{
    int x=1;
    int y=4;
};

class dummy_class {

public:
    dummy_class(int x, int y) : x(x), y(y) {

    }

    int get_x() { return x; }
    int get_y() { return y; }

private:
    int x;
    int y;
};

template <typename T>
class tempalted_class {
    T val;

public:
    tempalted_class() {
        std::cout << "templated constructor called" << std::endl;
        val = 30;
        val++;
    }
};

#define CONSTANT_STRING "SPOODER"

#define SQUARE(x) (x*x)

#define MACRO_FUNC1(var1, var2)             \
    for (int i=0; i<var1; i++) {            \
        for (int j=0; j<var2; j++) {        \
            std::cout << "E" << std::endl;  \
        }                                   \
    }                                       \

#define CHAIN_MACRO_1 "CHAIN_1"
#define CHAIR_MACRO_2 CHAIN_MACRO_1

#define STRUCT_MACRO(obj)   \
    std::cout << obj.x << std::endl;

#define CLASS_MACRO                             \
    dummy_class* d = new dummy_class(5,6);      \
    std::cout << d->get_x() << std::endl;       \
    std::cout << d->get_y() << std::endl;       \

#define TEMPLATED_MACRO         \
    tempalted_class<int> t1;

#define RETURN_MACRO    \
    return 77

int macro_func_2() {
    RETURN_MACRO;
}

void macro_func_1() {

    std::cout << CONSTANT_STRING << std::endl;
    
    int val = SQUARE(4);

    // will nor work, as result is stored in a string
    // std::string txt = SQUARE(5);

    MACRO_FUNC1(3,4)

    std::cout << CHAIR_MACRO_2 << std::endl;

    // you can pass any type to the params, they dont inforce type safety
    STRUCT_MACRO(dummy_data())
    
    // Will not work, as once expanded it will not compile
    // STRUCT_MACRO(4)

    CLASS_MACRO

    // cant be called here, as this is expanded into return 77, which effectively changes 
    // the return type of the calling function from void to int
    // to use it, apply it on a function which retruns an int, and in that case, any code after will not be reached.
    // std::cout << RETURN_MACRO << std::endl;

    int result = macro_func_2();
    std::cout << result << std::endl;

    TEMPLATED_MACRO
}


