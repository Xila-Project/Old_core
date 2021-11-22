
#include "Configuration.hpp"

#ifndef Log_Level   // Set default log level
#define Log_Level = 0
#endif

// -- Loging disabled
#if Log_Level == 0

#define Log_Raw(...)
#define Log_Error(...)
#define Log_Warning(...)
#define Log_Information(...)
#define Log_Debug(...)
#define Log_Verbose(...)


// -- Loging enabled

// -- Only errors enabled
#elif Log_Level == 1

#define Log_Raw(Format, ...)        Serial.printf(Format, ##__VA_ARGS__)
#define Log_Raw_Line(Format, ...)   Serial.printf(Format "\n", ##__VA_ARGS__)
#define Log_Error(Format, ...)      Serial.printf(" > Error | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Warning(...)
#define Log_Information(...)
#define Log_Debug(...)
#define Log_Verbose(...)


// -- Errors and warning enabled.
#elif Log_Level == 2

#define Log_Raw(Format, ...)       Serial.print(Format, ##__VA_ARGS__)
#define Log_Raw_Line(Format, ...)   Serial.printf(Format "\n", ##__VA_ARGS__)
#define Log_Error(Format, ...)     Serial.printf(" > Error | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Warning(Format, ...)   Serial.printf(" > Warning | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Information(...)
#define Log_Debug(...)
#define Log_Verbose(...)

// -- Errors, warning and informations enabled.
#elif Log_Level == 3

#define Log_Raw(Format, ...)       Serial.print(Format, ##__VA_ARGS__)
#define Log_Raw_Line(Format, ...)  Serial.printf(Format "\n", ##__VA_ARGS__)
#define Log_Error(Format, ...)     Serial.printf(" > Error | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Warning(Format, ...)   Serial.printf(" > Warning | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Information(Format, ...)     Serial.printf(" > Information | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Debug(...)
#define Log_Verbose(...)

// -- Errors, warning, informations and extra debug informations enabled.
#elif Log_Level == 4

#define Log_Raw(Format, ...)       Serial.print(Format, ##__VA_ARGS__)
#define Log_Raw_Line(Format, ...)  Serial.printf(Format "\n", ##__VA_ARGS__)
#define Log_Error(Format, ...)     Serial.printf(" > Error | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Warning(Format, ...)   Serial.printf(" > Warning | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Information(Format, ...)     Serial.printf(" > Information | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Debug(Format, ...)   Serial.printf(" > Debug | %s / %d : ", __FUNCTION__, __LINE__, Format, ##__VA_ARGS__)
#define Log_Verbose(...)

// -- Verbose mode (everything is logged).
#elif Log_Level == 5

#define Log_Raw(Format, ...)            Serial.print(Format, ##__VA_ARGS__)
#define Log_Raw_Line(Format, ...)       Serial.printf(Format "\n", ##__VA_ARGS__)
#define Log_Error(Format, ...)          Serial.printf(" > E - %s:%d | " Format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define Log_Warning(Format, ...)        Serial.printf(" > W - %s:%d | " Format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define Log_Information(Format, ...)    Serial.printf(" > I - %s:%d | " Format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define Log_Debug(Format, ...)          Serial.printf(" > D - %s:%d | " Format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define Log_Verbose(Format, ...)        Serial.printf(" > V - %s:%d | " Format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define Log_Error_Header()   Serial.printf(' > Error | %s / %d', __FUNCTION__ __LINE__, __LINE__)

#endif