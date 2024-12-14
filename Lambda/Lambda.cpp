#include "Lambda.hh"

#include <vector>
#include <iostream>
#include <algorithm>

void lambda_test_1() {

    std::vector<int> v1 {1,2,3,4,5};
    std::vector<int> v2{-1,-2,-3,-4};


    // use = to access all external vars by copy, cant see changes to it later
    auto display_vec = [=] () {
        for (auto val : v1)
            std::cout << val;
        std::cout << std::endl;
    };


    // use & to access all external vars by ref
    auto change_vec = [&] () {
        for (auto& val : v1)
            val++;
    };


    // you can be explicit about return type, but the compiler can deduce it too.
    auto display_vec_ref = [&] () -> int {
        for (auto val : v1)
            std::cout << val;
        std::cout << std::endl;
        return 5;
    };


    // add brackets to call the lambda
    display_vec();
    change_vec();
    std::cout << display_vec_ref() << std::endl;


    // use () to capture local vars, ususally passed in by functions like std::sort etc..
    std::sort(v1.begin(), v1.end(), [](const int& a, const int& b) -> bool
    {
        return a > b;
    });

    display_vec_ref();


    // empty lambda wont work in this fashion
    [](){
        std::cout << "Empty Lambda" << std::endl;
    };


    // take v1 by ref and v2 by copy
    auto another_display = [&v1, v2](){
        for (auto val : v1)
            std::cout << val;
        std::cout << std::endl;
        for (auto val : v2)
            std::cout << val;
        std::cout << std::endl;
    };
    another_display();


    // to access external vars, you must select by ref or copy, cant leave [] blank
    auto append = [&](int val){
        v1.push_back(val);
    };
    append(5);

}


// this works, but might as well make a normal function
auto dummy_lambda = []() {
    std::cout << "Dummy lambda" << std::endl;
};

void lambda_test_2() {
    
    // cant be called, since they are local to their own functions.
    // another_display(); 
    dummy_lambda();
}

