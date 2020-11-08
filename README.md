# Xila

## Introduction

Xila is a graphical user interface made for microcontroler, it can be considered as a graphical operating system. But it relay on FreeRTOS API. It's a huge project for a beginner in C++ like me (pls be lenient with me when you read the code). Due fussy character, my has been multiple times fully re-written (I don't count anymore), in order to optimize it and not loose precious ressources. I hope you would like it !

### Inpired By

- [Skewworks](https://www.skewworks.com "Skewworks") : [GadgetOS (ex-PyxisOS)](https://www.skewworks.com/pyxis "GadgetOS (ex-PyxisOS)")

- [Benjamin Heckendorn](https://www.benheck.com/ "Benjamin Heckendorn") : [BASIC 80's Pocket Computer](https://www.youtube.com/watch?v=Hjdj14C_jAI "BASIC 80's Pocket Computer");

## Features

Here's features which are already implemented :

- File manager (explorer, create, move, delete ...)
- Account manager.
- Internet Browser (I know, it sound totaly silly, but it's for the fun!)
- Multimeter.
- Oscilloscope.
- Function generator.
- Manage IOs of ESP32.
- Basic pong game.
- Periodic Table.
- Picture viewer (currently only support bitmap).
- Ultrasonic meter.
- Clock (rely on NTP Time).
- Music Player (with ULP processor).
- Calculator
- Control Parameter (edit configuration registry, stored in json file ".GCF").
- PS2 Keyboard support.
- Multitasking (each opennend app can be minimized and reoppened in his last state).

## Roadmap

- Release a "stable" version
- Add external video support (bitluni's VGA ? / FabGL ?).
- Get rid of proprietary Nextion Display (Retro-ingenering ? Gamebuino 3 ?)
- Comment proprely the code

## Installation

Xila is portable, I you just want to make it run on your SD card, then you just have to copy the code here in the Arduino IDE and then the ESP32 will do the job for you. 

## Developpement

Xila main goal was to allow the cohabitation between to programs. If you want to add yours, you have to way to proceed :

### External Software

This way is more flexible, because you only generate an executable file, which will be loaded in the ESP32 flash.

I'm currently considering a way to implement code interpeter like Basic to run external programs. (Allow to not rewrite the flash each time we switch software).

### Internal Software

If you want to make your app faster to load and not ruin your ESP32 flash. You can implement your software like a "built-in" one. To understand how to proceed, read the documentation on how to create your own software.

## Hardware

Here's main hadware needed to run Xila :

- NodeMCU-32S (but all esp32 will work fine).
- Nextion 4.3" Resistive Touch Display (NX4827T043_11)
- SD Card Reader (4-bit MMC SD or SPI SD)

Additionnaly can be added for more features :

- Old school PS2 keyboard
- Ultrasonic sensor HC-SR04

## Credit

Here's credit of the sources where I borrow/use code :

- [PIP Internet Browser, Chris ANDERSON](https://github.com/zigwart/PIP-Arduino-Web-Browser "PIP Internet Browser, Chris ANDERSON") (Creative Commons Attribution 4.0 Licence :  http://creativecommons.org/licenses/by/4.0/).
- [ULP Sound, Bitluni](https://github.com/bitluni/ULPSoundESP32 "ULP Sound, Bitluni")
- [PS2KBDLIB, Michalhol](https://github.com/bitluni/ULPSoundESP32 "PS2KBDLIB, Michalhol") (M.I.T. Licence :  https://mit-license.org/)

## About

This software is under [M.I.T. licence](https://mit-license.org/ "M.I.T. licence").
Alix ANNERAUD - [alixfaitgrr.fr](https://alixfaitgrr.fr "alixfaitgrr.fr") - 2020