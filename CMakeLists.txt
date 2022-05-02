cmake_minimum_required(VERSION 3.17)
project(hw1)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw1 main.cpp AVLnode.h Employee.h Company.h Employee.cpp helpers.cpp helpers.h Comapny.cpp Market.cpp Market.h exceptions.h CHANGES.cpp)
