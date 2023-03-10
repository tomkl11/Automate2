cmake_minimum_required(VERSION 3.21)
project(FizzBuzz)

set(CMAKE_CXX_STANDARD 14)

add_executable(FizzBuzz main.cpp cmake-build-debug/fizzBuzz.c cmake-build-debug/fizzBuzz.h fizzBuzz.c fizzBuzz.h)
