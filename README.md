# Galax OS Embedded Edition

## Introduction

GalaxOS cannot be consider as an operating system, it's more an user interface developped on ESP32 (before on Atmel Mega 2560) which has mutiple purposes. It's a huge project for a beginner in C++ like me (be lenient with me when you read the code).
The code has been multiple times fully re-written (I don't count anymore), in order to optimize it and not loose precious ressources. I hope you would like it !

### Inpired By

- [Skewworks](https://www.skewworks.com "Skewworks") : [GadgetOS (ex-PyxisOS)](https://www.skewworks.com/pyxis "GadgetOS (ex-PyxisOS)")

- [Benjamin Heckendorn](https://www.benheck.com/ "Benjamin Heckendorn") : [BASIC 80's Pocket Computer](https://www.youtube.com/watch?v=Hjdj14C_jAI "BASIC 80's Pocket Computer");

## Features

Here's features which are already implemented :

- File manager (explorer, create, move, delete ...)
- Account manager.
- Internet Browser (Only HTTP1.1, it sound silly, but it's a proof of concept !)
- Multimeter.
- Oscilloscope.
- Function generator.
- Manage IOs of ESP32.
- Basic pong game.
- Periodic Table.
- Picture viewer (currently only support bitmap).
- Ultrasonic meter.
- Clock (NTP Time).
- Music Player (with ULP processor).
- Calculator
- Control Parameter (edit configuration registry, stored in comma-separated value file ".GCF").
- PS2 Keyboard support.
- Multitasking (each opennend app can be minimized and reoppened in his last state).

## Roadmap

- Release a alpha version !
- Add SSL/TLS support to the Internet Browser.
- Add support for external app (Multi partitionning ?)
- Add external video support (bitluni's VGA ?).
- Get rid of proprietary Nextion Display (Retro-ingenering ? Gamebuino 3 ?)
- Comment proprely the code
- Implement TinyBasic or/and MicroPython intepreter.
- Use ULP to save time during sleep period.


## Hardware

Here's main hadware needed to run GalaxOS :

- NodeMCU-32S (but all esp32 will work fine).
- Nextion 4.3" Resistive Touch Display (NX4827T043_11)
- SD Card Reader (4-bit MMC SD)

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