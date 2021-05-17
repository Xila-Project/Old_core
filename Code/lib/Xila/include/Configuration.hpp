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
#ifndef CONFIGURATION_HPP_INCLUDED
#define CONFIGURATION_HPP_INCLUDED

// -- Default values -- //

// -- Registry
#define Default_Registry_Size 512

// -- USB serial speed
#define Default_USB_Serial_Speed 115200

// -- System
#define Default_Device_Name "Xila"
#define Xila_Version_Major 0
#define Xila_Version_Major_String "0"
#define Xila_Version_Minor 1
#define Xila_Version_Minor_String "1"
#define Xila_Version_Revision 0      
#define Xila_Version_Revision_String "0"

// -- Account
#define Maximum_Password_Lenght 32
#define Maximum_Username_Lenght 8

// -- Software
#define Low_Memory_Threshold 2000
#define Maximum_Software 30
#define Default_Watchdog_Timeout 5000
#define Maximum_Watchdog_Timeout 30000
#define Default_Instruction_Queue_Size 16
#define Memory_Chunk(x) (x * 1024)
#define Default_Software_Name_Length 24

// -- Power
#define Power_Button_Pin GPIO_NUM_35
#define Default_Battery_Conversion_Factor 2
#define Default_Battery_Minimum_Voltage 2500
#define Default_Battery_Maximum_Voltage 4200
#define Default_Battery_Sensing_Pin GPIO_NUM_34
#define Default_Button_Long_Press 4000

// -- Display

#define Default_Display_Switching_Pin GPIO_NUM_27
#define Default_Display_Receive_Pin GPIO_NUM_16
#define Default_Display_Transmit_Pin GPIO_NUM_17
#define Default_Display_Baud_Rate 921600
#define Default_Display_Brightness 100
#define Default_Display_Standby_Time 30

// -- Sound
#define Default_Volume_Level 255
#define Default_I2S_Clock_Pin
#define Default_I2S_Word_Select_Pin
#define Default_I2S_Data_Pin
#define Default_Sound_Mode

// --  Keyboard
#define Default_Keyboard_Data_Pin GPIO_NUM_32
#define Default_Keyboard_Clock_Pin GPIO_NUM_22
#define Default_Keyboard_Layout American

// -- Time
#define Default_Daylight_Offset 0
#define Default_GMT_Offset 0
#define Default_NTP_Server "pool.ntp.org"

// -- Release configuration
#if CORE_DEBUG_LEVEL <= 1 // release mode

#ifndef ARDUINOTRACE_ENABLE
#define ARDUINOTRACE_ENABLE     0       // Disable ArduinoTrace
#endif

#define Animations              1       // Enable animation
#define Drive_Mode              0       // SD mmc mode
#define USB_Serial              0       // Disable USB Serial

// -- Debug configuration
#else

#warning Debug mode.


#ifndef ARDUINOTRACE_ENABLE
#define ARDUINOTRACE_ENABLE     1       // Enable ArduinoTrace
#endif

#define Animations              1       // Disable animation
#define Drive_Mode              1       // SD spi mode
#define USB_Serial              1       // Enable USB Serial

#endif

#endif