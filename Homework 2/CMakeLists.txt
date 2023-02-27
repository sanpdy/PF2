cmake_minimum_required(VERSION 3.24)
project(Homework_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Homework_2
        main.cpp
        RestaurantList.cpp
        RestaurantList.h
        RestaurantNode.cpp
        RestaurantNode.h)
