add_library(Templates Templates.cpp
                      Helper.cpp)
target_include_directories(Templates PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})