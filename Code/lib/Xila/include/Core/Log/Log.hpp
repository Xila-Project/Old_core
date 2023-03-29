///
/// @file Log.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 13-03-2023
///
/// @copyright Copyright (c) 2023
///

#ifndef Xila_Log_Hpp
#define Xila_Log_Hpp

#include "../Module/Module.hpp"

#include "esp_log.h"

namespace Xila_Namespace
{
    typedef class Log_Class
    {
    public:
        Log_Class();

        void Print(const char *Format, ...)
        {
           // if (!Semaphore.Is_Valid())
           // {
           //     Print_Static("Semaphore is not valid !\r\n");
           //     return;
           // }
           // Print_Static("Wait semaphore...\r\n");

           //xSemaphoreTake(Semaphore_Handle, portMAX_DELAY);
           //Semaphore.Take();
            va_list Arguments;
            va_start(Arguments, Format);
            log_printf(Format, Arguments);
            va_end(Arguments);
            //Semaphore.Give();
            //xSemaphoreGive(Semaphore_Handle);
        };

        static inline void Print_Static(const char *Format, ...)
        {
            va_list Arguments;
            va_start(Arguments, Format);
            log_printf(Format, Arguments);
            va_end(Arguments);
        };


    private:
        xSemaphoreHandle Semaphore_Handle;
        StaticSemaphore_t Semaphore_Buffer;

    } Log_Type;

    extern Log_Type Log;

}

#ifndef Log_Level
#define Log_Level 1
#endif

#if Log_Level >= 6
#warning "Log level is set to an invalid value, logging is disabled."
#define Log_Level 0
#endif

#if Log_Level > 0

#define Log_Raw(Format, ...)        log_printf(Format, ##__VA_ARGS__);
#define Log_Raw_Line(Format, ...)   Log_Raw(Format "\r\n", ##__VA_ARGS__)
#define Log_Format(Module_Name, Type, Format) "| %6u ms | %s.%s() | (%s:%u) |  %s | " Format "\r\n", (unsigned long)(esp_timer_get_time() / 1000ULL), Module_Name, __FUNCTION__, pathToFileName(__FILE__), __LINE__, Type
#define Log_All(Module_Name, Type, Format, ...) Log_Raw(Log_Format(Module_Name, Type, Format), ##__VA_ARGS__)
#else
#define Log_Raw(Tag, Format, ...)
#define Log_Raw_Line(Format, ...)
#define Log_All()
#endif

#if Log_Level >= 1
#define Log_Error(Module_Name, Format, ...) Log_All(Module_Name, "Error", Format, ##__VA_ARGS__)
#else
#define Log_Error(Module_Name, Format, ...)
#endif

#if Log_Level >= 2
#define Log_Warning(Module_Name, Format, ...) Log_All(Module_Name, "Warning", Format, ##__VA_ARGS__)
#else
#define Log_Warning(Module_Name, Format, ...)
#endif

#if Log_Level >= 3
#define Log_Information(Module_Name, Format, ...) Log_All(Module_Name, "Information", Format, ##__VA_ARGS__)
#else
#define Log_Information(Module_Name, Format, ...)
#endif

#if Log_Level >= 4
#define Log_Debug(Module_Name, Format, ...) Log_All(Module_Name, "Debug", Format, ##__VA_ARGS__)
#define Log_Trace() Log_All("Trace", "Debug", " - ");
#define Log_Dump(Variable) Log_All("Dump", "Debug", #Variable)
#else
#define Log_Debug(Module_Name, Format, ...)
#define Log_Trace()
#define Log_Dump(Variable)
#endif

#if Log_Level >= 5
#define Log_Verbose(Module_Name, Format, ...) Log_All(Module_Name, "Verbose", Format, ##__VA_ARGS__)
#else
#define Log_Verbose(Module_Name, Format, ...)
#endif

#endif  // Xila_Log_Hpp