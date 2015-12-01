cmake_minimum_required(VERSION 2.8)
project(Drive)
include_directories( /home/pi/projects/TinyTank/WiiC/src/wiicpp)
include_directories( /home/pi/projects/TinyTank/WiiC/src/wiic)
include_directories( /home/pi/projects/TinyTank/WiiC/src/log)

link_directories( /home/pi/projects/TinyTank/WiiC/build/wiicpp)

link_directories( /home/pi/projects/TinyTank/WiiC/build/wiic)

add_executable(Drive main.cpp)
target_link_libraries(Drive wiicpp)
target_link_libraries(Drive wiic)
target_link_libraries(Drive wiringPi)
