#ifndef GALAXOS_H_INCLUDED
#define GALAXOS_H_INCLUDED

#include "Arduino.h"
#include "Core.hpp"                                 

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||               __________   __   __  _____   _                              ||
||              |      |   |  \ \ / / |_   _| | |          /\                 ||
||              |______|   |   \ V /    | |   | |         /  \                ||
||              |   |__|___|    | |     | |   | |        / /\ \               ||
||              |   |      |   / . \   _| |_  | |____   / ____ \              ||
||              |___|______|  /_/ \_\ |_____| |______| /_/    \_\             ||
||                                                                            ||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|| For ESP-32                                                                 ||
|| Version : 0.1.0 - Alix ANNERAUD - MIT Licence - 2020                       ||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||                                    Wiring :                                ||
||  - Power button :                                                          ||
|| Side 1 : GND                                                               ||
|| Side 2 : 39                                                                ||
||  - Battery :                                                               ||
|| 5V -> Vin                                                                  ||
|| GND -> GND                                                                 ||
|| VBat -> P36                                                                ||
||  - Display (Nextion) :                                                     ||
|| NPN Transistor Base -> 27                                                  ||
|| Red -> 5v                                                                  ||
|| Blue -> P16                                                                ||
|| Yellow -> P17                                                              ||
|| Black -> GND                                                               ||
||  - SD Card (SDIO Mode) :                                                   ||
|| Clock -> 14                                                                ||
|| Command -> 15                                                              ||
|| Data 0 -> 2                                                                ||
|| Data 1 -> 4                                                                ||
|| Data 2 -> 12                                                               ||
|| Data 3 -> 13                                                               ||
|| VCC -> 3.3v                                                                ||
|| GND -> GND                                                                 ||
||  - SD Card (SPI Mode) :                                                    ||
|| MISO -> 19                                                                 ||
|| MOSI -> 23                                                                 ||
|| SCK -> 18                                                                  ||
|| CS -> 5                                                                    ||
|| VCC -> 3.3v                                                                ||
|| GND -> GND                                                                 ||
||  - Debbugger (ESP-Prog)                                                    ||
|| MTCK -> 13                                                                 ||
|| MTMS -> 14                                                                 ||
|| MTDI -> 12                                                                 ||
|| MTDO -> 15                                                                 ||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||                                  Project Files :                           ||
||  - GalaxOS.hpp/cpp : "hub" files                                           ||
||  - Core :                                                                  ||
||      - Core.hpp/cpp : core features (driver, user, virtual mem, APIs etc.) ||
||      - Software.hpp/cpp : Definition of external's software API            ||
||  - Drivers :                                                               ||
||      - Display.hpp/cpp : Display hardware abstraction layer                ||
||      - Keyboard.hpp/cpp : Keyboard hardawre abstraction layer              ||
||      - Sound.hpp/cpp : Sound hardware abstraction layer (use ULP proc)     ||
||  - Software :                                                              ||
||      - Shell.hpp/cpp : Main UI Software (with high priviliege)             ||
||      - TinyBasic.hpp/cpp : Basic emulator, used by core to run Basic script||
||      - Internet_Browser.hpp/cpp : Primitive internet browser               ||
||      - Oscilloscope.hpp/cpp : Primitive oscilloscope application           ||
||      - Signal_Generator.hpp/cpp : Primitive signal generator               ||
||      - Calculator.hpp/cpp : Basic scientific calculator                    ||
||      - Music_Player : Basic musiplayer                                     ||
||      - Paint.hpp/cpp : Basic paint software                                ||
||      - Ultrasonic.hpp/cpp : An ultrasonic meter                            ||
||      - Periodic.hpp/cpp :  The periodic table                              ||
||                                                                            ||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||                               Credit to :                                  ||
|| Sound : Benjamin Mastripolito (https://benpm.github.io - https://freesound.org/people/Lemoncreme/sounds/231578)||
|| Michalhol : Keyboard Library (https://github.com/michalhol/ps2kbdlib)      ||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

extern Xila_Class Xila;

#endif