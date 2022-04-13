#include "Loader.hpp"
#include "Configuration.hpp"

#include <Update.h>
#include <FS.h>
#include <SD_MMC.h>
#include <SD.h>

#include "Nextion_Library.hpp"
#include "Loader.hpp"

#include "SD.h"
#include "SD_MMC.h"

#include "Nextion_Library.hpp"

Nextion_Class Display;

Xila_Loader_Class Xila_Loader;

void Xila_Loader_Class::Start()
{
    xTaskCreate(Loop, "Xila loader task", 4 * 1024, NULL, 0, NULL);

    Display.Set_Callback_Function_Numeric_Data(Xila_Loader.Display_Numeric_Data_Handler);
    Display.Set_Callback_Function_String_Data(Xila_Loader.Display_String_Data_Handler);
    Display.Set_Callback_Function_Event(Xila_Loader.Display_Event_Handler);

#if USB_Serial == 1
    Serial.begin(Default_USB_Serial_Speed);
#endif

}

void Xila_Loader_Class::Loop(void*)
{
    Display.Loop();
    vTaskDelay(pdMS_TO_TICKS(20));
}

void Xila_Loader_Class::Display_Numeric_Data_Handler(uint32_t Data)
{

}

void Xila_Loader_Class::Display_String_Data_Handler(const char* Data, uint8_t Size)
{
    if (strcmp(Data, "#Bo"))
    {
        Xila_Loader.Boot();
    }
    else if (strcmp(Data, "#IR"))
    {
        Xila_Loader.Load();
    }
    else
    {
        // Unrecognized instructions.
    }

}
void Xila_Loader_Class::Display_Event_Handler(uint8_t Event)
{

}

void Xila_Loader_Class::Boot()
{
    
}

void Xila_Loader_Class::Load()
{
    File Executable_File;

#if Drive_Mode == 0

    Executable_File = SD.open(Executable_File_Path);

#elif Drive_Mode == 1

    Executable_File = SD_MMC.open(Executable_File_Path);

#endif

    if (!Executable_File || Executable_File.isDirectory() || Executable_File.size() == 0)
    {
        Display.Set_Text(F("EVENT_TXT"), F("Failed to load the executable file. Check the drive files."));
        return;
    }

    Display.Set_Text(F("EVENT_TXT"), F("The loading will start in 3 seconds."));
    vTaskDelay(pdMS_TO_TICKS(3000));

    if (Update.begin(Executable_File.size(), U_FLASH))
    {
        size_t Written = Update.writeStream(Executable_File);
        if (Written != Executable_File.size())
        {
            Display.Set_Text(F("EVENT_TXT"), F("Failed to load the entire executable. Retry ?"));
            return;
        }

        if (Update.end())
        {
            if (Update.isFinished())
            {
                Serial.println("Executable loaded successfully.");
            }
            else
            {
                Serial.println("Failed to load the executable.");
            }
        }
        else
        {
            Serial.println("Error Occurred. Error #: " + String(Update.getError()));
        }
    }
    else
    {
        Display.Set_Text(F("EVENT_TXT"), F("Not enough space. Please check flash partitioning."));
    }

    Boot();
}
