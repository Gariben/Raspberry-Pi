# WRT
## Wireless Raspberry-Pi Tank


[![Video Demonstration](http://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg)](https://www.youtube.com/watch?v=sLEG0MJwF-w)

The WRT is a basic tank platform powered by the Raspberry Pi. It was intended as an introduction in developing my own robotics platform, with the intention of expanding the platform to include sensors, a camera, and autonomous control systems.

The tank chassis was purchased from AliExpress, which has two motors, one for each set of treads.
The motor is controlled through a custom motor driver circuit, [pictured here](http://1.bp.blogspot.com/-NZxt9j16m9E/VkvywD5PT9I/AAAAAAAACtc/_JrPu5mCfXw/s640/Motor_Driver_Tested_bb.png). The Pi provides the logic, and a nine volt battery drives the motors.
The Pi is externally powered by a USB charger.

This code here is from WRT-T1, the first in the teleoperated series of WRT projects. It is controlled by a wii remote using [WiiC](https://github.com/grandelli/WiiC) via a bluetooth USB dongle. The [WiringPi library](http://wiringpi.com/) allows read/write to the GPIO.

Also included is a motor test for testing the motor driver circuit, and a PWM test for testing WiringPi's software Pulse Width Modulation.

Future expansions will include networking controls, camera controls, and some kind of armament. 

Everything is compiled in CMake, but you can compile it in whatever you like.

Read more about WRT and my other projects here:

http://leibeckj.blogspot.com/2015/11/wrt-t1-wireless-raspberry-pi-tank.html
