cmake_minimum_required(VERSION 2.8)
project(Drive)
add_executable(Drive main.cpp)
target_link_libraries(Drive wiringPi)
