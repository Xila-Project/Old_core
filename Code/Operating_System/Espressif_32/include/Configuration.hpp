// Configuration File
#ifndef CONFIGURATION_HPP_INCLUDED
#define CONFIGURATION_HPP_INCLUDED

#include "SD_MMC.h"

#include  "esp_log.h"

// -- Default value

// USB serial speed
#define USB_SERIAL_SPEED 115200


#define Default_Device_Name "Xila"

#define Maximum_GPIO 40

// Account

#define Default_Autologin_Account ""

// Software

#define Low_Memory_Threshold 2000

#define Maximum_Software 30

#define POWER_BUTTON_PIN GPIO_NUM_39

// Battery

#define Default_Battery_Conversion_Factor 2
#define Default_Battery_Minimum_Voltage 2500
#define Default_Battery_Maximum_Voltage 4200
#define Default_Battery_Sensing_Pin GPIO_NUM_34 // to do : change to 35

//

#define Default_Display_Receive_Pin GPIO_NUM_16
#define Default_Display_Transmit_Pin GPIO_NUM_17
#define Default_Display_Baud_Rate 921600
#define Default_Display_Brightness 100
#define Default_Display_Standby_Time 30

// Sounds
#define Default_Volume_Level 255
#define Default_I2S_Clock_Pin
#define Default_I2S_Word_Select_Pin
#define Default_I2S_Data_Pin
#define Default_Sound_Mode



#define Default_Registry_Size 512

// Keyboard
#define Default_Keyboard_Data_Pin 32
#define Default_Keyboard_Clock_Pin 33
#define Default_Keyboard_Layout American

// Versionning
#define Version_Major 0
#define Version_Minor 1
#define Version_Revision 0



//  Drive retrocompatibility
#define DRIVE_Version_Major 0
#define DRIVE_Version_Minor 1
#define DRIVE_Version_Revision 0

// Display retrocompatibility
#define DISPLAY_Version_Major 0
#define DISPLAY_Version_Minor 1
#define DISPLAY_Version_Revision 0

// Core tasks repartition
#define SOFTWARE_CORE 0
#define SYSTEM_CORE 1

// -- 
#define MAXIMUM_PASSWORD_LENGHT 24
#define MAXIMUM_USERNAME_LENGHT 8


//
#define Default_Instruction_Queue_Size 16

// Task memory allocation
#define Memory_Chunk(x) (x * 1024)

// Watchdog 

#define Default_Watchdog_Timeout 5000  // ms
#define Maximum_Watchdog_Timeout 30000

// -- Default registry values --

#define DEFAULT_SOUND_REGISTRY_VOLUME 75

// -- Debug / Release specific configurations

#if CORE_DEBUG_LEVEL <= 1 // release mode

#define BATTERY_CHECKING 0  // enable battery checking
#define ANIMATION 1         // enable animation
#define LOGIN 1             // used to bypass login form during debugging session
#define SD_MODE 0           // SD mmc mode
#define STACK_OVERFLOW_DETECTION 0

#define Verbose_Print(t) NULL
#define Verbose_Print_Line(t) NULL

#define DEBUG_MODE 0
#define USB_SERIAL 0

#else // debug mode

#define BATTERY_CHECKING 0          // disable battery checking
#define ANIMATION 0                 // disable animation
#define LOGIN 0                     // used to bypass login form during debugging session

#define SD_MODE 1                   // SD spi mode
#define STACK_OVERFLOW_DETECTION 0  // 

#define Verbose_Print(t) Serial.print(F(t))
#define Verbose_Print_Line(t) Serial.println(F(t))

#define DEBUG_MODE 1

#define USB_SERIAL 1

#endif

#endif