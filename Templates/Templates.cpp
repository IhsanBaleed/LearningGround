#include "Templates.hh"
#include "Helper.hh"

void tempalte_func_test() {
    std::cout << "Templates Imp" << std::endl;
    helper_function();
    // helper_template_function(7); will not work, the source file must have visibility over the function's definition
}

void tempalte_func_test_1() {
    template_func_1(7); // type deduction kicks in 
    template_func_1<int>(2); // explicit type deduction
    // template_func_2(); // will not work, since type deduction will not work and we did not provide tempalte params.
    
    // will not work, when expanding the template 
    //the compiler performs type safety and makes sure the calls done on the types are legal.
    // template_func_2<std::string>(); 

    template_func_3<7>(); // the compiler will generate a function with x = 7
    int z = 8;
    // template_func_3<z>();  //will not work, we need to have a constant expression ie: value.
    template_func_4(); // predefined value
}

void template_func_test_2() {
    template_func_5<int>();
    template_func_5<int>();
    template_func_5<double>();    
}

void template_func_test_3() {
    
    template_func_6(5);
    template_func_6(5.0);
    template_func_6(5.0f);

    template_func_7(5, 5);
    template_func_7(5, 5.9);

}

void template_func_test_4() {

    std::cout << "Template Func 8" << std::endl;
    template_func_8(1,2,3,4);
    
    std::cout << "Template Func 9" << std::endl;
    template_func_9(1,2,3,4);

    template_func_9(); // you can also supply no arguemnts at all 

    template_func_10<5>();
}

// same rule applies here, where the definition of the template class must be in the header file
// template <typename T, typename T2>
// template_class<T, T2>::template_class() {
//     std::cout << "Template Class Constructor" << std::endl;
// } 

void template_class_test() {
    
    template_class<double, double> t;
    t.print();

    template_class<int, double> t2;
    t2.print();

    template_class<int, float> t3;
    t3.print();
}

void template_class_test_2() {

}

