#ifndef PATH_HPP_INCLUDED
#define PATH_HPP_INCLUDED

#define String_Concat(first, second) first second

#define Xila_Directory_Path "/Xila"
#define Software_Directory_Path "/Software"
#define Users_Directory_Path "/Users"

#define Registry_File_Extension ".xrf"
#define Data_File_Extension ".xdf" // mainly used for undefined data type
#define Executable_File_Extension ".xef"
#define Sound_File_Extension ".wav"
#define Basic_File_Extension ".bas"

#define Registry_Directory_Path Xila_Directory_Path "/Registry"
#define Registry(name) Registry_Directory_Path "/" name Registry_File_Extension //shortcut

#define Temporary_Directory_Path Xila_Directory_Path "/Temporary"
#define Sounds_Directory_Path Xila_Directory_Path "/Sounds"
#define Executable_Directory_Path Xila_Directory_Path "/Executab"

#define System_Registry_Path Registry("System")
#define Display_Registry_Path Registry("Display")
#define Network_Registry_Path Registry("Network")
#define Account_Registry_Path Registry("Account")
#define Time_Registry_Path Registry("Time")
#define Keyboard_Registry_Path Registry("Keyboard")
#define Software_Registry_Path Registry("Software")
#define Sound_Registry_Path Registry("Sound")

#define Startup_Sound_Path Sounds_Directory_Path "/Startup" Sound_File_Extension
#define Shutdown_Sound_Path Sounds_Directory_Path "/Shutdown" Sound_File_Extension
#define Login_Sound_Path Sounds_Directory_Path "/Login" Sound_File_Extension

#define Dump_Registry_Path Temporary_Directory_Path "/Dump" Data_File_Extension
#define Clipboard_Path Temporary_Directory_Path "/Clipboar" Data_File_Extension
#define Test_Path Temporary_Directory_Path "/Test" Data_File_Extension

#define Display_Executable_Path Executable_Directory_Path "/Xila_D" Executable_File_Extension
#define Microcontroller_Executable_Path Executable_Directory_Path "/Xila_M" Executable_File_Extension

#undef String_Concat

#endif