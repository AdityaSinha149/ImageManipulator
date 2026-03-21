cmake_minimum_required(VERSION 3.31.6)

project(PixelManipulator)

add_executable(PixelManipulator driver.cpp greenScreen.cpp image.cpp)

add_compile_options(-O3  -std=c++14)

