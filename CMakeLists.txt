cmake_minimum_required(VERSION 3.9.1)

project(joyterm)

add_library(libjoyterm style/MStyle/MStyle.cpp joyterm.cpp)