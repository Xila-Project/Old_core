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




// -- Main system directory
#define Temporary_Directory_Path Xila_Directory_Path "/Temporary"
#define Sounds_Directory_Path Xila_Directory_Path "/Sounds"
#define Executable_Directory_Path Xila_Directory_Path "/Executab"
#define Variable_Directory_Path Xila_Directory_Path "/Variable"
#define Registry_Directory_Path Xila_Directory_Path "/Registry"

#define Registry(name) Registry_Directory_Path "/" name Registry_File_Extension //shortcut
#define Variable(name) Variable_Directory_Path "/" name
#define Sounds(name) Sounds_Directory_Path "/" name
#define Executable(name) Executable_Directory_Path "/" name
#define Temporary(name) Temporary_Directory_Path "/" name

#define Dump_Registry_Path Temporary_Directory_Path "/Dump" Data_File_Extension

#define Clipboard_Path Temporary_Directory_Path "/Clipboar" Data_File_Extension
#define Test_Path Temporary_Directory_Path "/Test" Data_File_Extension

#define Display_Executable_Path Executable_Directory_Path "/Xila_D" Executable_File_Extension
#define Microcontroller_Executable_Path Executable_Directory_Path "/Xila_M" Executable_File_Extension

#undef String_Concat

#endif