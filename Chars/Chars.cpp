#include "Chars.hh"
#include <iostream>

void char_test() {

    const char* char_ptr_str = "char pointer string"; // bad idea to not use const
    // char_ptr_str[3] = 'a'; will cause a segmentation fault

    char char_array[] = "char array string"; // bad idea to not use const
    char char_array2[4] = {'a', 'b', 'c', 'd'};

    std::string value("value");
    std::string value2 = {"something"};

    // can use any of the following to convert to string
    std::string str2 = char_ptr_str;
    std::string str3 = char_array;
    std::string str4(char_ptr_str);
    std::string str5(char_array);

    std::string source_string = "source_string";
    // this wont work, the pointer cant be initialized with a string
    // const char* source_char_ptr2 = source_string;
    const char* source_char_ptr = source_string.c_str();
    // will not work, the array cant be initialized with a pointer
    // char source_char_array[] = source_string.c_str();
    char value_arr[] = "value_arr";
    const char* value_ptr = value_arr;

    // will not work, the array cant be initialized with a pointer
    const char* value_ptr2 = "value_ptr2";
    // char value_arr2[] = value_ptr2;    
}

void char_test_1() {
    std::string str = "string";
    char char_arr[] = "char array";
    const char* char_ptr = "char pointer";


    char_test_2(char_arr, char_arr, char_arr); // the char array can be passed to all types and it works
    
    //would not work for char array, as array needs a proper initlization
    // char_test_2(char_ptr, char_ptr, char_ptr);
    
    // would not work for the latter 2
    // char_test_2(str, str, str);
}

void char_test_2(std::string str, char char_arr[], const char* char_ptr) {
    std::cout << str << std::endl;
    std::cout << char_arr << std::endl;
    std::cout << char_ptr << std::endl;
}






