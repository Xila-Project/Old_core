// Configuration File

// For debbuging purpose

#define VERBOSE_MODE 1 //only serial output

#if VERBOSE_MODE == 0
#define Verbose_Print(t)
#define Verbose_Println(t) 
#else
#define Verbose_Print(t) Serial.println(F(t))
#define Verbose_Println(t) Serial.println(F(t))
#endif

#define DEBUG_MODE 0

#if DEBUG_MODE == 0
#define SD_MODE 0 // use by default (=0) the SD I/O mode, not suitable for debbug 
#else
#define SD_MODE 1
#endif