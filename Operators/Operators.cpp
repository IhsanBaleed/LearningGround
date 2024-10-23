#include "Operators.hh"


// this is defined outside the class, so it must take two params, the LHS and the RHS
void operator - (const dummy& d1, const dummy& d2) {
    std::cout << "operator - (const dummy& d1, const dummy& d2)" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const toy& t) {
    os << "toy size: " << t.size;
    return os;
}

// At least one of the params must be of the class type, and the other can be of any type
// void operator - (const int& d1, const int& d2) { 
//     std::cout << "operator - (const dummy& d1, const dummy& d2)" << std::endl;
// }

void test_case() {
    dummy d1("first");
    dummy d2("second");
    d1 + d2;

    dummy d3("third");
    // d3 + ; //would not work, since + is missing its params
    d3 + d1; // this would still call the operator + (const dummy& d) function, since the function takes a dummy

    toy t;
    d3 + t; // this would call the operator + (toy t) function, since the function takes a toy
}

void test_case_2() {
    
    dummy d1("first");
    dummy d2("second");
    d1 - d2;
    
    dummy d3 = +d1;
    +d1; // this would work, since the operator has params
}

void test_case_3() {
    toy t;
    t++;

    toy t2;
    // t++5; // would not work, as the ++ operator can only take zero or one argument
    ++t;
}

void test_case_4() {
    Fraction f(2, 5);
    float f2 = f;
    std::cout << "f2: " << f2 << std::endl;
}

void test_case_5(){
    Fraction f(2, 5);
    f.print();

    f = 20; // works due to implicit conversion, since the constructor can be called with at least one arguemnt
    f.print();

}

void test_case_6() {
    toy t;
    t.size = 5;

    std::cout << t << std::endl;
}

