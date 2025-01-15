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
add_subdirectory(DS)
add_subdirectory(LR_Vals)
add_subdirectory(Macros)
add_subdirectory(DynamicAllocation)
add_subdirectory(STL)
add_subdirectory(FuncPtr)
add_subdirectory(Exceptions)

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
                                       Threads
                                       DS
                                       LR_Vals
                                       Macros
                                       Dynamic
                                       STL
                                       FuncPtr
                                       Exceptions)

