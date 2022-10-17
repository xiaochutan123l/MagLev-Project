MagLev-Project

[中文版Chinese](https://github.com/xiaochutan123l/MagLev-Project/blob/main/docs/%E4%B8%8A%E6%8B%89%E5%BC%8F%E7%A3%81%E6%82%AC%E6%B5%AE.md)

Pull-up magnetic levitation based on Arduino board.

<img src="https://github.com/xiaochutan123l/MagLev-Project/blob/main/images/youtube.jpg" width="445" height="250" />(https://youtu.be/WY3Qidg5Ipc)

## Introduction

MagLev-Project is a magnetic levitation project like its name.  Magnet levitation with Arduino or some other MCU is actually an old stuff. There are many tutorial and demonstration on the internet. Here i will share my code and the experience of making it. It may help someone who also wants to make a magnetic levitation device. 

There two types of magnet levitation principle: `Pull-up` and `Push-down`. This project is the other type `Pull-up`. This project includes two versions, `basic version` (manual set parameters for each floater) and `weight adaptive` version.



## Principle

<img src="https://github.com/xiaochutan123l/MagLev-Project/blob/main/images/principle.gif" width="500" height="450" />

The principle of the levitation is illustrated as in the Gif. The above magnet provides a pull force which can counteract the gravity of the bottom magnet(floater), this critical position is the `AdjustValue` which we want the floater to float. With the help of the above magnet, the electromagnet(copper coil) needs relatively small force to keep the floater at the critical position. 

We can see in this Gif, the levitation process is dynamic. If the floater goes down or up, we can control the coil to produce a pull or push force, by changing the electrodes. The Hall-effect sensor is very sensitive, thus a slight movement of the floater will be detected, and a corresponding controlling for the coil will then be taken. The floater can float stably at a fixed position.

## Hardware components

<img src="https://github.com/xiaochutan123l/MagLev-Project/blob/main/images/bottom-biew2.JPG" width="560" height="420" />

<img src="https://github.com/xiaochutan123l/MagLev-Project/blob/main/images/top-view2.jpg" width="560" height="420" />

#### 1. Arduino Uno (it can be any MCU)

#### 2. Hall sensor

I use `49E011BD`, other Linear Hall effect sensors with similar Supply Voltage (3 - 6.5V) are also suitable.

Hall sensor can detect and transfer the magnetic field to voltage signal. It's used to detect the position of the floater.

#### 3. Operational amplifier

Since the Hall sensor can only output a very small range of voltage, a OP amplifier is used to amplify the voltage signal, as the input signal for Arduino Uno. (`LM358N` is used).

#### 4. Motor driver module

 `L298N` Motor driver module, it provides H-Bridge DC Motor Control, it's used to drive the copper coil as a electromagnet. Pull-up type requires only one copper coil, so only half of the H-Bridge is needed.

#### 5. Magnet

Two stack of magnets are used. One is the floater, another is the magnet on the copper coil, it can counteract the gravity of the floater, in this way only few energy needed for the levitation. 

### Schematic diagram

<img src="https://github.com/xiaochutan123l/MagLev-Project/blob/main/images/Schematic_MagLev2.png" width="610" height="470" />

## Algorithm

The source code is not complicated, so here are just some tips and necessary explanation.

### 1. Basic version - PID

##### Find the `AdjustValue`: 

Just grab the floater below the coil, move the floater. You can feel in some position the floater is weightless, if you move up the floater a little bit, it will be caught by the above magnet. A position slight above this banlance point is the `AdjustValue`, at here coil only need to provide repulsive force, the gravity on floater will be compensated by the magnet above.

The value can be observed by *Serial Monitor* or a digit display like i used.

#### Tune the PID parameter:

Only `P` and `D` are used. Try different `P` first by size, then you can feel the repulsive force on the floater from coil if you move the floater near to the above magnet, keep increase the `P` size, once you see the floater waggles for one or twice becouse of the force from coil and the gravity, that means the `P` value is now a suitable value, the coil can privide enough force to compensate the attractive force from above magnet.

Then try different `D` value by size, but exponentially, 0.001-0.01, 0.01-0.1, 0.1-1 an so on. Until floater floats stable, this combination of `P` and `D` is the final parameter. 

Tip: try with increasing parameter with large step to roughly find a interval, then determine the prise one.  

#### Filter:

Due to the sensitivity of the Hall sensor and the impact from the environment, a filter is necessary. I used the mean value of multiple reading, it works well for me.

### 2. Advanced version - Floater detection and weight adaptive

In order to avoid the boring parameter determination process, in the advanced version, the floater detection function is introduced. (the PID parameter should be determined first)

#### Floater detection:

At the very beginning, the initial read value from sensor will be recorded. If the floater comes in, the magnet field will cause a huge change of the read value. The difference of the current read value to the initial value is used to determined if there is a floater comes in or out.

#### Weight adaptive:

The `AdjustValue` is not set at the initial phase any more. Each time after a floater came in, the `AdjustValue` will be set (again). Just grab the floater at the weightless point for a several seconds, the program will find the `AdjustValue`. 

## References

1. [Magnet Levitation with Arduino](https://create.arduino.cc/projecthub/jsirgado/magnet-levitation-with-arduino-eeeee4)
2. [盗梦陀螺](http://www.diy-robots.com/?page_id=685)
3. [改进磁悬浮装置](http://www.pengzhihui.xyz/2018/05/08/maglev/)
