cmake_minimum_required(VERSION 3.24)
project(MyP)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyP main.cpp train.cpp train.h station.cpp station.h schedule.cpp schedule.h)
