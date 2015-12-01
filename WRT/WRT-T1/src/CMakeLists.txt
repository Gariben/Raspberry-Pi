cmake_minimum_required(VERSION 2.8)
project(Drive)
include_directories( /home/pi/projects/WRT-T1/WiiC/src/wiicpp)
include_directories( /home/pi/projects/WRT-T1/WiiC/src/wiic)
include_directories( /home/pi/projects/WRT-T1/WiiC/src/log)

link_directories( /home/pi/projects/WRT-T1/WiiC/build/wiicpp)

link_directories( /home/pi/projects/WRT-T1/WiiC/build/wiic)

add_executable(Drive main.cpp)
target_link_libraries(Drive wiicpp)
target_link_libraries(Drive wiic)
target_link_libraries(Drive wiringPi)
