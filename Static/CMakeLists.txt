add_library(Static Static.cpp
                   Helper.cpp)
target_include_directories(Static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})