# ESP32 (LOLIN32) + OV7670 Camera + Nokia 5110 LCD

This project used Arduino IDE for getting frames from OV7670 camera
module and display it on the monochrome LCD of Nokia 5110.

## Parts

  - LOLIN32 ESP32-based board
  
    ![LOLIN32 ESP32-based board](Parts/esp32-lolin32.png)

  - OV7670 camera module
  
    ![OV7670 camera module](Parts/ov7670-camera.jpg)

  - Nokia 5110 LCD module
  
    ![Nokia 5110 LCD module](Parts/nokia-5110-lcd.jpg)

## Instructions

Open `Main.ino` in Arduino IDE and upload it to your board.

## Drivers

  - Driver for OV7670 camera found at:
    
    <https://github.com/bitluni/ESP32CameraI2S>

  - Driver for Nokia 5110 LCD found at:
    
    <https://github.com/platisd/nokia-5110-lcd-library>

## Demo

![Demo](https://user-images.githubusercontent.com/1549028/212589497-31f69062-3a6b-4c8e-bcaa-ae69780f44c4.gif)
