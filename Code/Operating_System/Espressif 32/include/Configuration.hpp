// Configuration File
#ifndef CONFIGURATION_HPP_INCLUDED
#define CONFIGURATION_HPP_INCLUDED

// USB serial speed
#define SERIAL_SPEED 115200

//
#define DEFAULT_DEVICE_NAME "ESP32"

// Software

#define MAXIMUM_SOFTWARE 20

// Pin configuration

#define DISPLAY_SWITCH_PIN 27
#define POWER_BUTTON_PIN GPIO_NUM_39
#define BATTERY_SENSING_PIN 36

// Software
#define TYPE_BUILTIN_SOFTWARE 0
#define TYPE_EXTERNAL_SOFTWARE 1
#define TYPE_EMULATED_SOFTWARE 2

// Json document
#define DEFAULT_REGISTRY_SIZE 256

// Versionning
#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION_REVISION 0

//  Drive retrocompatibility
#define DRIVE_VERSION_MAJOR 0
#define DRIVE_VERSION_MINOR 1
#define DRIVE_VERSION_REVISION 0

// Display retrocompatibility
#define DISPLAY_VERSION_MAJOR 0
#define DISPLAY_VERSION_MINOR 1
#define DISPLAY_VERSION_REVISION 0

// Battery 

#define BATTERY_CHECKING 0

// Core tasks repartition
#define SOFTWARE_CORE 0
#define SYSTEM_CORE 1



#define IDLE_TASK_PRIORITY 0
#define SOFTWARE_TASK_PRIOITY 1
#define SYSTEM_TASK_PRIORITY 2
#define DRIVER_TASK_PRIORITY 3

#define MAXIMUM_PASSWORD_LENGHT 24
#define MAXIMUM_USERNAME_LENGHT 8

#define WATCHDOG_INITAL_TIME 4000
#define WATCHDOG_MAXIMUM_TIME 6000

#define Memory_Chunk(x) (x * 1024)

// Debug

#define DEBUG_MODE 1 

#define WATCHDOG 0 //managed by core

#define STACK_OVERFLOW_DETECTION 0

#define SD_MODE 1 // 0 : SD_MMC / 1 : SD_SPI

#define DISPLAY_MODE 1 //

#define VERBOSE_MODE 1

#define SERIAL_SPEED 115200
#if VERBOSE_MODE == 0
#define Verbose_Print(t) NULL
#define Verbose_Print_Line(t) NULL 
#else
#define Verbose_Print(t) Serial.print(F(t))
#define Verbose_Print_Line(t) Serial.println(F(t))
#endif


// -- Default registry values --

#define DEFAULT_SOUND_REGISTRY_VOLUME 75

#endif