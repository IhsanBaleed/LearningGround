cmake_minimum_required(VERSION 3.0)

project(TestField)

add_subdirectory(Pointers)
add_subdirectory(Const)
add_subdirectory(Classes)
add_subdirectory(Chars)
add_subdirectory(Inheritance)
add_subdirectory(Polymorphism)
add_subdirectory(Interfaces)
add_subdirectory(Lambda)
add_subdirectory(Templates)
add_subdirectory(Operators)
add_subdirectory(Static)
add_subdirectory(Threads)

add_executable(TestField TestField.cpp)

target_link_libraries(TestField PUBLIC Pointers 
                                       Const
                                       Classes
                                       Chars
                                       Inheritance
                                       Polymorphism
                                       Interfaces
                                       Lambda
                                       Templates
                                       Operators
                                       Static
                                       Threads)

