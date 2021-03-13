// Configuration File
#ifndef CONFIGURATION_HPP_INCLUDED
#define CONFIGURATION_HPP_INCLUDED

#include  "esp_log.h"

// -- Default value

// USB serial speed
#define USB_SERIAL_SPEED 115200


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

// Core tasks repartition
#define SOFTWARE_CORE 0
#define SYSTEM_CORE 1

// -- 
#define MAXIMUM_PASSWORD_LENGHT 24
#define MAXIMUM_USERNAME_LENGHT 8

// 
#define IDLE_TASK_PRIORITY 0
#define SOFTWARE_TASK_PRIOITY 1
#define SYSTEM_TASK_PRIORITY 2
#define DRIVER_TASK_PRIORITY 3

//
#define DEFAULT_QUEUE_SIZE 16

// Task memory allocation
#define Memory_Chunk(x) (x * 1024)

// Watchdog 

#define WATCHDOG_INITAL_TIME 4000   // ms
#define WATCHDOG_MAXIMUM_TIME 6000  // ms

// -- Default registry values --

#define DEFAULT_SOUND_REGISTRY_VOLUME 75

// -- Debug / Release specific configurations

#if CORE_DEBUG_LEVEL <= 1 // release mode

#define BATTERY_CHECKING 1  // enable battery checking
#define ANIMATION 1         // enable animation
#define LOGIN 1             // used to bypass login form during debugging session
#define WATCHDOG 0          // Disable esp32 watchdog - managed by core
#define SD_MODE 0           // SD mmc mode
#define STACK_OVERFLOW_DETECTION 0

#define Verbose_Print(t) NULL
#define Verbose_Print_Line(t) NULL

#define DEBUG_MODE 0
#define USB_SERIAL 0

#else // debug mode

#define BATTERY_CHECKING 0      // disable battery checking
#define ANIMATION 0             // disable animation
#define LOGIN 0                 // used to bypass login form during debugging session
#define WATCHDOG 0              // Disable esp32 watchdog - managed by core
#define SD_MODE 1               // 0 : SD_MMC / 1 : SD_SPI
#define STACK_OVERFLOW_DETECTION 0

#define Verbose_Print(t) Serial.print(F(t))
#define Verbose_Print_Line(t) Serial.println(F(t))

#define DEBUG_MODE 1
#define USB_SERIAL 1

#endif

#endif