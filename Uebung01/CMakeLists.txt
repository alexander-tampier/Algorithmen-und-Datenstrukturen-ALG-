cmake_minimum_required(VERSION 3.9)
project(Uebung01)

set(CMAKE_CXX_STANDARD 11)

add_executable(Uebung01 main.cpp algo/HashMap.h algo/HashEntry.h algo/HashCode.h domain/StockEntry.h)