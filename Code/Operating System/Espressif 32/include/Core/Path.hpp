#ifndef PATH_HPP_INCLUDED
#define PATH_HPP_INCLUDED

#define String_Concat(first, second) first second

#define Xila_Directory_Path "/XILA/"
#define Software_Directory_Path "/SOFTWARE/"
#define Users_DirectoryPath "/USERS/"

#define Registry_Directory_Path String_Concat(Xila_Directory_Path, "REGISTRY/")

#define System_Registry_Path = String_Concat(Registry_Directory_Path, "SYSTEM.XRF");
#define Display_Registry_Path = String_Concat(Registry_Directory_Path, "DISPLAY.XRF");
#define Network_Registry_Path = String_Concat(Registry_Directory_Path, "NETWORK.XRF");
#define Account_Registry_Path = String_Concat(Registry_Directory_Path, "ACCOUNT.XRF");
#define Regional_Registry_Path = String_Concat(Registry_Directory_Path, "REGIONAL.XRF");
#define Software_Registry_Path = String_Concat(Registry_Directory_Path, "SOFTWARE.XRF");
#define Event_Registry_Path = String_Concat(Registry_Directory_Path, "SOFTWARE.XRF");
#define Sound_Registry_Path = String_Concat(Registry_Directory_Path, "SOUND.XRF");
#define Extension_Registry_Path = String_Concat(Registry_Directory_Path, "EXTENSIO.XRF");

#define Software_Dump_Registry_Path = "/XILA/REGISTRY/DUMP/SOFTWARE.XRF";

#define System_Executable_Path = "/XILA/XILA.XEF";
#define Clipboard_Path = "/XILA/TEMPORARY/CLIPBOAR.XDF";
#define Startup_Sound_Path = "/XILA/SOUNDS/STARTUP.WAV";
#define Display_Executable_Path = "/XILA/EXECUTAB/XILA_D.XEF";
#define Microcontroller_Executable_Path = "/XILA/EXECUTAB/XILA_M.XEF";

#undef String_Concat

#endif