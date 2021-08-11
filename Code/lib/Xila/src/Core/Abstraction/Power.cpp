///
/// @file Power.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"
#include "soc/rtc_wdt.h"

extern Xila_Class::Software_Handle Shell_Handle;

///
/// @brief Construct a new Xila_Class::Power_Class::Power_Class object
///
Xila_Class::Power_Class::Power_Class()
    : Battery_Class(Default_Battery_Sensing_Pin, Default_Battery_Minimum_Voltage, Default_Battery_Maximum_Voltage, Default_Battery_Conversion_Factor)
{
    Button_Mutex = portMUX_INITIALIZER_UNLOCKED;
    Button_Counter = 0;
}

///
 /// @brief Load power registry.
 /// 
 /// @return Xila_Class::Event 
Xila_Class::Event Xila_Class::Power_Class::Load_Registry()
{
    File Temporary_File = Xila.Drive.Open(Registry("Power"));
    DynamicJsonDocument Power_Registry(256);
    if (deserializeJson(Power_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    if (strcmp(Power_Registry["Registry"] | "", "Power") != 0)
    {
        return Error;
    }
    Set_Sessing_Pin(Power_Registry["Sensing Pin"] | Default_Battery_Sensing_Pin);
    Set_Voltages(Power_Registry["Minimum Voltage"] | Default_Battery_Minimum_Voltage, Power_Registry["Maximum Voltage"] | Default_Battery_Maximum_Voltage);
    Set_Conversion_Factor(Power_Registry["Conversion Factor"] | Default_Battery_Conversion_Factor);
    return Success;
}

///
 /// @brief Save power registry.
 /// 
 /// @return Xila_Class::Event 
Xila_Class::Event Xila_Class::Power_Class::Save_Registry()
{
    DynamicJsonDocument Power_Registry(Default_Registry_Size);
    Power_Registry["Registry"] = "Power";
    Power_Registry["Minimum Voltage"] = Get_Minimum_Voltage();
    Power_Registry["Maximum Voltage"] = Get_Maximum_Voltage();
    Power_Registry["Sensing Pin"] = Get_Sensing_Pin();
    Power_Registry["Conversion Factor"] = Get_Conversion_Factor();
    File Temporary_File = Xila.Drive.Open(Registry("Power"), FILE_WRITE);
    if (serializeJson(Power_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    return Success;
}

///
 /// @brief Handler of the power button interrupt.
 /// 
void IRAM_ATTR Xila_Class::Power_Class::Button_Interrupt_Handler()
{
    vTaskEnterCritical(&Xila.Power.Button_Mutex);
    if (Xila.GPIO.Digital_Read(Power_Button_Pin) == Xila.GPIO.High) // rise
    {
        if (Xila.Power.Button_Timer != 0 && (Xila.Time.Milliseconds() - Xila.Power.Button_Timer) > Default_Button_Long_Press)
        {
            Xila.Power.Button_Counter = 0;
            Xila.Power.Deep_Sleep();
        }
        else
        {
            Xila.Power.Button_Timer = 0;
            Xila.Power.Button_Counter = 1;
        }
    }
    else // falling
    {
        Xila.Power.Button_Timer = Xila.Time.Milliseconds();
        Xila.Power.Button_Counter = 0;
    }

    vTaskExitCritical(&Xila.Power.Button_Mutex);
}

///
 /// @brief Check if power button is pressed.
 /// 
void Xila_Class::Power_Class::Check_Button()
{
    if (Button_Counter != 0)
    {
        Xila.Dialog.Power();
        Button_Counter = 0;
    }
}

///
 /// @brief Make the board go in deep sleep.
 /// 
void Xila_Class::Power_Class::Deep_Sleep()
{
    Xila.Display.Set_Serial_Wake_Up(true);
    Xila.Display.Set_Touch_Wake_Up(false);
    Xila.Display.Set_Current_Page(F("Core_Load"));

    Xila.GPIO.Digital_Write(Default_Display_Switching_Pin, Xila.GPIO.Low);

    Xila.Drive.End();

    Xila.Task.Delay(10);

    esp_sleep_enable_ext0_wakeup(Power_Button_Pin, LOW);
    esp_deep_sleep_start();
}
