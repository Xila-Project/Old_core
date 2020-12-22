// Configuration File

// For debbuging purpose

#ifndef CONFIGURATION_HPP_INCLUDED
#define CONFIGURATION_HPP_INCLUDED

// 921600 / 115200
#define SERIAL_SPEED 115200

#define VERSION "0.1.0"
#define DRIVE_RETROCOMPATIBILITY_VERSION "0.1.0"

#define SOFTWARE_CORE 0
#define SYSTEM_CORE 1

#define IDLE_TASK_PRIORITY 0
#define SOFTWARE_TASK_PRIOITY 1
#define SYSTEM_TASK_PRIORITY 2
#define DRIVER_TASK_PRIORITY 3

#define DEBUG_MODE 1

#if DEBUG_MODE == 0
#define SD_MODE 0 // use by default (=0) the SD I/O mode, not suitable for debbug 
#define STACK_OVERFLOW_DETECTION 1
#define VERBOSE_MODE 0
#else
#define SD_MODE 1
#define STACK_OVERFLOW_DETECTION 0
#define VERBOSE_MODE 1
#endif

#if VERBOSE_MODE == 0
#define Verbose_Print(t)
#define Verbose_Println(t) 
#else
#define Verbose_Print(t) Serial.print(F(t))
#define Verbose_Print_Line(t) Xila.Print_Line(F(t))
#endif

#endif