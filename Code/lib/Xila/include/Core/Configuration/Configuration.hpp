///
/// @file Configuration.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila configuration header file.
/// @details Configure few parameters of Xila at compile time.
/// @version 0.1
/// @date 09-04-2021
///
/// @copyright Copyright (c) 2021
///

// Configuration File
#ifndef Configuration_Hpp_Included
#define Configuration_Hpp_Included

#include "Hardware.hpp"

// -- Default values -- //


// -- Registry
#define Default_Registry_Size 512

// -- USB serial speed
#define Default_USB_Serial_Speed 115200

// Partitions
#define Xila_Loader_Partition 0
#define Xila_Partition 1

// -- System
#define Default_Device_Name "Xila"
#define Xila_Version_Major 0
#define Xila_Version_Major_String "0"
#define Xila_Version_Minor 1
#define Xila_Version_Minor_String "2"
#define Xila_Version_Revision 0
#define Xila_Version_Revision_String "0"

#define Selected_Language English

// -- Account
#define Maximum_Password_Length 32
#define Maximum_Username_Length 8

// - Drive

#define Drive_Hardware  SD_SPI

#define SD_SPI_Clock_Pin 4
#define SD_SPI_Select_Pin 2
#define SD_SPI_Master_In 27
#define SD_SPI_Master_Out 5
#define SD_SPI_Frequency 4000000


// -- Software
#define Low_Memory_Threshold 2000
#define Maximum_Software 30
#define Default_Watchdog_Timeout 5000
#define Maximum_Watchdog_Timeout 30000
#define Default_Instruction_Queue_Size 16
#define Default_Software_Name_Length 24

// -- Power
#define Power_Button_Pin GPIO_NUM_35
#define Default_Battery_Conversion_Factor 2
#define Default_Battery_Minimum_Voltage 2500
#define Default_Battery_Maximum_Voltage 4200
#define Default_Battery_Sensing_Pin GPIO_NUM_34
#define Default_Button_Long_Press 4000

// -- Display



#define Display_Hardware WT32_SC01

#define Display_Horizontal_Definition 480
#define Display_Vertical_Definition 320
 
#define Default_Display_Switching_Pin GPIO_NUM_27
#define Default_Display_Receive_Pin GPIO_NUM_16
#define Default_Display_Transmit_Pin GPIO_NUM_17
#define Default_Display_Baud_Rate 921600
#define Default_Display_Brightness 100
#define Default_Display_Standby_Time 30

// -- Sound
#define Default_Volume_Level 255
#define Default_I2S_Clock_Pin GPIO_NUM_23
#define Default_I2S_Word_Select_Pin GPIO_NUM_26
#define Default_I2S_Data_Pin GPIO_NUM_25
#define Default_Sound_Output 0

// --  Keyboard
#define Default_Keyboard_Data_Pin GPIO_NUM_32
#define Default_Keyboard_Clock_Pin GPIO_NUM_22
#define Default_Keyboard_Layout American

// -- Time
#define Default_Daylight_Offset 0
#define Default_GMT_Offset 0
#define Default_NTP_Server "pool.ntp.org"

#define Log_Level   CORE_DEBUG_LEVEL

// -- Release configuration
#if CORE_DEBUG_LEVEL <= 1 // release mode

//#define ARDUINOTRACE_ENABLE 0 // Disable ArduinoTrace

#define Animations 1        // Enable animation
#define USB_Serial 1        // Disable USB Serial
#define Start_On_Power 1    // Start when Xila is powered up

// -- Debug configuration
#else

#define Animations 0        // Disable animation
#define USB_Serial 1        // Enable USB Serial
#define Start_On_Power 1    // 

#endif

#endif