cmake_minimum_required(VERSION 3.20)
project(hw1)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw1 main.cpp AVLnode.h Worker.h Company.h Worker.cpp helpers.cpp helpers.h Employee.cpp Employee.h Comapny.cpp Market.cpp Market.h)
