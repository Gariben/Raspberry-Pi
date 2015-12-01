cmake_minimum_required(VERSION 2.8)
project(Drive)

add_executable(pwm main.cpp)
target_link_libraries(pwm wiringPi)
#target_link_libraries(pwm softPwm)
