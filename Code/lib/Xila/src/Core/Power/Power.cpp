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

#include "Core/Power/Power.hpp"

#include "soc/rtc_wdt.h"

using namespace Xila_Namespace;

///
/// @brief Construct a new Xila_Class::Power_Class::Power_Class object
///
Power_Class::Power_Class()
    : Battery_Class(Default_Battery_Sensing_Pin, Default_Battery_Minimum_Voltage, Default_Battery_Maximum_Voltage, Default_Battery_Conversion_Factor)
{
    Button_Mutex = portMUX_INITIALIZER_UNLOCKED;
    Button_Counter = 0;
}

///
/// @brief Load power registry.
///
/// @return Result::Type
Module_Class::Result::Type Power_Class::Load_Registry()
{
    using namespace Xila;

    File Temporary_File = Drive.Open(Registry("Power"));
    DynamicJsonDocument Power_Registry(256);
    if (deserializeJson(Power_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Result::Error;
    }
    Temporary_File.close();
    if (strcmp(Power_Registry["Registry"] | "", "Power") != 0)
    {
        return Result::Error;
    }
    Set_Sessing_Pin(Power_Registry["Sensing Pin"] | Default_Battery_Sensing_Pin);
    Set_Voltages(Power_Registry["Minimum Voltage"] | Default_Battery_Minimum_Voltage, Power_Registry["Maximum Voltage"] | Default_Battery_Maximum_Voltage);
    Set_Conversion_Factor(Power_Registry["Conversion Factor"] | Default_Battery_Conversion_Factor);
    return Result::Success;
}

///
/// @brief Save power registry.
///
/// @return Result::Type
Module_Class::Result::Type Power_Class::Save_Registry()
{
    using namespace Xila;
    DynamicJsonDocument Power_Registry(Default_Registry_Size);
    Power_Registry["Registry"] = "Power";
    Power_Registry["Minimum Voltage"] = Get_Minimum_Voltage();
    Power_Registry["Maximum Voltage"] = Get_Maximum_Voltage();
    Power_Registry["Sensing Pin"] = Get_Sensing_Pin();
    Power_Registry["Conversion Factor"] = Get_Conversion_Factor();
    File Temporary_File = Drive.Open(Registry("Power"), FILE_WRITE);
    if (serializeJson(Power_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Result::Error;
    }
    Temporary_File.close();
    return Result::Success;
}

///
/// @brief Handler of the power button interrupt.
///
void IRAM_ATTR Power_Class::Button_Interrupt_Handler()
{
    using namespace Xila;
    //vTaskEnterCritical(&Power.Button_Mutex);
    if (Pin.Digital_Read(Power_Button_Pin) == Pin.High) // rise
    {
        if (Power.Button_Timer != 0 && (Time.Milliseconds() - Power.Button_Timer) > Default_Button_Long_Press)
        {
            Power.Button_Counter = 0;
            Power.Deep_Sleep();
        }
        else
        {
            Power.Button_Timer = 0;
            Power.Button_Counter = 1;
        }
    }
    else // falling
    {
        Power.Button_Timer = Time.Milliseconds();
        Power.Button_Counter = 0;
    }

    //vTaskExitCritical(&Power.Button_Mutex);
}

///
/// @brief Check if power button is pressed.
///
void Power_Class::Check_Button()
{
    if (Button_Counter != 0)
    {
        Dialog.Power();
        Button_Counter = 0;
    }
}

///
/// @brief Make the board go in deep sleep.
///
void Power_Class::Deep_Sleep()
{
    Log_Information("Going into deep-sleep.");
    
    Display.Set_Serial_Wake_Up(true);
    Display.Set_Touch_Wake_Up(false);
    Display.Set_Current_Page(F("Core_Load"));

    Pin.Digital_Write(Default_Display_Switching_Pin, Pin.Low);

    Drive.End();

    Task_Class::Delay(10);

    esp_sleep_enable_ext0_wakeup(Power_Button_Pin, LOW);
    esp_deep_sleep_start();
}
