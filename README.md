# Xila

## Introduction

Xila is a lightweight operating system (like [Contiki](https://github.com/contiki-os/contiki "Contiki") or [TinyOS](https://github.com/tinyos/tinyos-main "TinyOS")) for embedded devices (currently only the ESP32 is supported). Its goal is to offer a simple standardized API. In this way, that allow the integration of different software in one unique ecosystem and also easy porting (only the HAL of Xila needs to be rewrite). I hope you would like it !

Inspired by :
- [BASIC 80's Pocket Computer](https://www.youtube.com/watch?v=Hjdj14C_jAI "BASIC 80's Pocket Computer") - [Benjamin HECKENDORN](https://www.benheck.com/ "Benjamin HECKENDORN")
- [MultiApp Advanced](https://github.com/botofancalin/M5Stack-MultiApp-Advanced "MultiApp Advanced") - [botofancalin](https://github.com/botofancalin "botofancalin")
- [GadgetOS (ex-PyxisOS)](https://www.skewworks.com/pyxis "GadgetOS (ex-PyxisOS)") - [Skewworks](https://www.skewworks.com "Skewworks")


## Table of contents

- [Introduction](#introduction)
- [Table of contents](#table-of-contents)
- [Status](#status)
- [Quick Start](#quick-start)
- [Features](#features)
- [About](#about)

## Status

[![Build Status](https://travis-ci.com/AlixANNERAUD/Xila.svg?branch=master)](https://travis-ci.com/AlixANNERAUD/Xila.svg?branch=master)     [![Documentation Status](https://readthedocs.org/projects/xila/badge/?version=latest)](https://xila.readthedocs.io/en/latest/?badge=latest)

## Quick start

### Using

Check [here the documentation](https://xila.alixfaitgrr.fr/en/latest/Get%20Started.html#start-to-use "Start to use") to start using Xila.

### Develop

Check [here the documentation](https://xila.alixfaitgrr.fr/en/latest/Get%20Started.html#start-to-developp "Start to develop") to start to develop software for Xila.

### Contribute

This project is openned to contributions of any kinds.

## Support

Check here the whole documenation of Xila : [xila.alixfaitgrr.fr](https://xila.alixfaitgrr.fr/).

If you have any question or proposition, you can join me :
- 📫 by mail : [alix.anneraud@outlook.fr](mailto:alix.anneraud@outlook.fr) 

## Features

### Core

Here are the feature that are implemented in the core :

- Simple **account manager**.
- **Multitasking** (background execution, protections against freezing and memory overflow).
- Safe **shutdown**, **restart**, **lock** and **hibernation** (deep sleep).
- **Display**, **drive**, **GPIO**, **keyboard**, **network**, **power**, **sounds** and **time** abstraction layers.
- A simple **dialog box** API (keyboards, events, file, color picker ...).

### Software

Here is a list of included software :

- A file manager (create, cut, remove ...).
- A preferences pannel.
- A scientific calculator.
- A clock (clock, alarms, chronometer and timer).
- A text viewer.
- A paint software.
- An internet browser.
- A music player (wav, mp3, m4a and web radio).
- An oscilloscope.
- A periodic table.
- A simple piano.
- A pong game.
- A simon game.
- A tinybasic emulator.

It's [up to you](#develop) to make this list longer 😉.

### Roadmap

- Finish the documentation.
- Comment proprely the code.
- Support LVGL graphics which would allow more flexibility, animations etc. But maybe require a more powerfull board with more memory/flash and ram (ESP32-WROVER or Teensy ?).
- Port to ESP8266, ESP32-S3, Teensy ...
- Change how registries works (JSON is handy but inappropriate for this project).
- Allow software to be removed or added on the fly without any recompilation.

## About

### Dependencies :

Here are dependencies of the project :

- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32 "ESP32 Arduino Core") - [Espressif](https://github.com/espressif/)
- [Audio I2S](https://github.com/schreibfaul1/ESP32-audioI2S "ESP32 Audio I2S") - [schreibfaul1](https://github.com/schreibfaul1)
- [PS2Keyboard](https://github.com/PaulStoffregen/PS2Keyboard "PS2Keyboard") - [Paul STOFFREGEN](https://github.com/PaulStoffregen/ "Paul STOFFREGEN")
- [ArduinoJson](https://github.com/bblanchon/ArduinoJson "ArduinoJson") - [Benoît BLANCHON](https://github.com/bblanchon/)
- [StreamUtils](https://github.com/bblanchon/ArduinoStreamUtils/ "StreamUtils") - [Benoît BLANCHON](https://github.com/bblanchon/)
- [Periodic Table JSON](https://github.com/Bowserinator/Periodic-Table-JSON "Periodic Table JSON") - [Bowserinator](https://github.com/Bowserinator/ "Bowserinator")
- [Nextion library](https://github.com/AlixANNERAUD/Nextion-Library "Nextion library") - [Alix ANNERAUD](https://github.com/AlixANNERAUD/ "Alix ANNERAUD")
- [Battery library](https://github.com/AlixANNERAUD/Battery-Library "Battery library") - [Alix ANNERAUD](https://github.com/AlixANNERAUD/ "Alix ANNERAUD")

### Reused Code :

Here are credits to sources where I borrow code :

- [PIP Internet Browser](https://github.com/zigwart/PIP-Arduino-Web-Browser "PIP Internet Browser") - [Chris ANDERSON](https://github.com/zigwart/ "Chris ANDERSON") - CC 4.0
- [ESP32 Oscilloscope](https://github.com/botofancalin/M5Stack-ESP32-Oscilloscope) - [Botofancalin](https://github.com/botofancalin/) - MIT Licence
- [TinyBasic Plus](https://github.com/BleuLlama/TinyBasicPlus "TinyBasic Plus") - [Scott Lawrence](https://github.com/BleuLlama "Scott Lawrence") / Michael FIELD / Gordon BRANDLY / Jurg WULLSCHLEGER - MIT Licence

### Licence

This software is under [M.I.T. licence](https://alix-anneraud.mit-license.org/ "M.I.T. licence").

Alix ANNERAUD - [alixfaitgrr.fr](https://alixfaitgrr.fr "alixfaitgrr.fr")
