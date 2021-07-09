ESP32 (LOLIN32) + OV7670 Camera + Nokia 5110 LCD
=================================================

This project used Arduino IDE for getting frames from OV7670 camera module and
display it on the monochrome LCD of Nokia 5110.

Parts
-------------

- LOLIN32 ESP32-based board

  .. figure:: https://github.com/m3y54m/esp32-ov7670-nokia5110/blob/main/Parts/esp32-lolin32.png?raw=true
    :alt: LOLIN32 ESP32-based board
  
- OV7670 camera module

  .. figure:: https://github.com/m3y54m/esp32-ov7670-nokia5110/blob/main/Parts/ov7670-camera.jpg?raw=true
    :alt: OV7670 camera module
    :width: 400px

- Nokia 5110 LCD module
  
  .. figure:: https://github.com/m3y54m/esp32-ov7670-nokia5110/blob/main/Parts/nokia-5110-lcd.jpg?raw=true
    :alt: Nokia 5110 LCD module
	:width: 400px

Instructions
-------------

Open Main.ino in Arduino IDE and upload it to your board.

Drivers
---------

- Driver for OV7670 camera found at:
  
  https://github.com/bitluni/ESP32CameraI2S

- Driver for Nokia 5110 LCD found at:
  
  https://github.com/platisd/nokia-5110-lcd-library

Demo
------

A demo video is provided as "Demo.mp4" in the root of this repository

