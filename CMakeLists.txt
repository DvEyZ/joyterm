cmake_minimum_required(VERSION 3.9.1)

project(joyterm)

add_library(libjoyterm src/style/MStyle/MStyle.cpp src/joyterm.cpp)

add_executable(libjoyterm-test test/main.cpp)
target_link_libraries(libjoyterm-test libjoyterm)