MagLev-Project

[中文版](https://github.com/xiaochutan123l/MagLev-Project/blob/main/docs/%E4%B8%8A%E6%8B%89%E5%BC%8F%E7%A3%81%E6%82%AC%E6%B5%AE.md)

Pull-up magnetic levitation based on Arduino board.

<img src="https://github.com/xiaochutan123l/MagLev-Project/blob/main/images/youtube.jpg" style="zoom:30%;" />(https://youtu.be/WY3Qidg5Ipc)

## Introduction

MagLev-Project is a magnetic levitation project like its name.  Magnet levitation with Arduino or some other MCU is actually an old stuff. There are many tutorial and demonstration on the internet. Here i will share my code and the experience of making it. It may help someone who also wants to make a magnetic levitation device. 

There two types of magnet levitation principle: `Pull-up` and `Push-down`. This project is the other type `Pull-up`. This project includes two versions, `basic version` (manual set parameters for each floater) and `weight adaptive` version.



## Principle

<img src="https://github.com/xiaochutan123l/MagLev-Project/blob/main/images/principle.gif" style="zoom:30%;" />

#### #TODO add description



## Hardware components

<img src="https://github.com/xiaochutan123l/MagLev-Project/blob/main/images/bottom-biew2.JPG" style="zoom:12%;" />

<img src="https://github.com/xiaochutan123l/MagLev-Project/blob/main/images/top-view2.jpg" style="zoom:12%;" />

#### 1. Arduino Uno (it can be any MCU)

#### 2. Hall sensor

I use `49E011BD`, other Linear Hall effect sensors with similar Supply Voltage (3 - 6.5V) are also suitable.

Hall sensor can detect and transfer the magnetic field to voltage signal. It's used to detect the position of the floater.

#### 3. Operational amplifier

Since the Hall sensor can only output a very small range of voltage, a OP amplifier is used to amplify the voltage signal, as the input signal for Arduino Uno.

### #TODO: Circuit

#### 4. Motor driver module

 `L298N` Motor driver module, it provides H-Bridge DC Motor Control, it's used to drive the copper coil as a electromagnet. Pull-up type requires only one copper coil, so only half of the H-Bridge is needed.

#### 5. Magnet

Two stack of magnets are used. One is the floater, another is the magnet on the copper coil, it can counteract the gravity of the floater, in this way only few energy needed for the levitation. 



## Algorithm

### 1. Basic version - PID

### 2. Advanced version - Floater detection and weight adaptive



## References

1. [Magnet Levitation with Arduino](https://create.arduino.cc/projecthub/jsirgado/magnet-levitation-with-arduino-eeeee4)
2. [盗梦陀螺](http://www.diy-robots.com/?page_id=685)
3. [改进磁悬浮装置](http://www.pengzhihui.xyz/2018/05/08/maglev/)
