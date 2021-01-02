#ifndef PATH_HPP_INCLUDED
#define PATH_HPP_INCLUDED

#define String_Concat(first, second) first second

#define Xila_Directory_Path "/XILA/"
#define Software_Directory_Path "/SOFTWARE/"
#define Users_DirectoryPath "/USERS/"

#define Registry_File_Extension ".XRF"
#define Data_File_Extension ".XDF" // mainly used for undefined data type
#define Executable_File_Extension ".XEF"
#define Sound_File_Extension ".WAV"

#define Registry_Directory_Path Xila_Directory_Path "REGISTRY/"
#define Registry(name) Registry_Directory_Path name Registry_File_Extension //shortcut
#define Temporary_Directory_Path Xila_Directory_Path "TEMPORARY/"
#define Sounds_Directory_Path Xila_Directory_Path "SOUNDS/"
#define Executable_Directory_Path Xila_Directory_Path "EXECUTAB/"

#define System_Registry_Path Registry("SYSTEM")
#define Display_Registry_Path Registry("DISPLAY")
#define Network_Registry_Path Registry("NETWORK")
#define Account_Registry_Path Registry("ACCOUNT")
#define Regional_Registry_Path Registry("REGIONAL")
#define Software_Registry_Path Registry("SOFTWARE")
#define Event_Registry_Path Registry("SOFTWARE")
#define Sound_Registry_Path Registry("SOUND")
#define Extension_Registry_Path Registry("EXTENSIO")

#define Startup_Sound_Path Sounds_Directory_Path "STARTUP" Sound_File_Extension
#define Shutdown_Sound_Path Sounds_Directory_Path "SHUTDOWN" Sound_File_Extension
#define Login_Sound_Path Sounds_Directory_Path "LOGIN" Sound_File_Extension

#define Software_Dump_Registry_Path Temporary_Directory_Path "SOFTWARE" Data_File_Extension
#define Clipboard_Path Temporary_Directory_Path "CLIPBOAR" Data_File_Extension

#define Display_Executable_Path Execitable_Registry_Path "XILA_D" Executable_File_Extension
#define Microcontroller_Executable_Path Execitable_Registry_Path "XILA_M" Executable_File_Extension

#undef String_Concat

#endif