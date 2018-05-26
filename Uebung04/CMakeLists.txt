cmake_minimum_required(VERSION 3.9)
project(Uebung04)

set(CMAKE_CXX_STANDARD 11)

add_executable(Uebung04 main.cpp commons/FileReader.h domain/Point.h algo/NearestNeighbour.h algo/Enumeration.h algo/TSP.h)