///
/// @file Power.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core.hpp"

#include "Power/Power.hpp"
#include "Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Power_Types;

Power_Type Xila_Namespace::Power;

/// @brief Construct a new Xila_Class::Power_Class::Power_Class object
Power_Class::Power_Class() : Button_Clicked(0), Button_Timer(0), Task(this)
{
}

Power_Class::~Power_Class()
{
}

Result_Type Power_Class::Start()
{
    Log_Information("Power", "Start power module...");
#ifdef Xila_Power_Button_Default_Pin
    Pin.Set_Mode(Xila_Power_Button_Default_Pin, Pin_Types::Mode_Type::Input);
    Pin.Attach_Interrupt(Xila_Power_Button_Default_Pin, Button_Interrupt_Handler, Pin_Types::Interrupt_Mode_Type::Change);
#endif

    if (Task.Get_State() == Task_Type::State_Type::Running)
    {
        return Result_Type::Success;
    }

    if (Load_Registry() != Result_Type::Success)
    {
        // if (Create_Registry() != Result_Type::Success)
        //{
        // return Result_Type::Error;
        //}
        Create_Registry();
    }

    return Result_Type::Success;
}

Result_Type Power_Class::Stop()
{
    if (Task.Get_State() == Task_Type::State_Type::Running)
    {
        Task.Delete();
    }

    if (Save_Registry() != Result_Type::Success)
    {
        return Result_Type::Error;
    }

    return Result_Type::Success;
}

///
/// @brief Load power registry.
///
/// @return Result_Type
Result_Type Power_Class::Load_Registry()
{
    // - Open registry file
    Drive_Types::File_Type Registry_File = Drive.Open(Registry("Power"));

    // - Load registry
    StaticJsonDocument<256> Power_Registry;
    if (!Registry_File || (deserializeJson(Power_Registry, Registry_File) != DeserializationError::Ok) || (strcmp(Power_Registry["Registry"] | "", "Power") != 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();

// - Get values from registry
//#ifdef Xila_Power_Default_Battery_Sensing_Pin
//    Set_Sessing_Pin(Power_Registry["Sensing Pin"] | Xila_Power_Battery_Default_Sensing_Pin);
//    Set_Voltages(Power_Registry["Minimum Voltage"] | Xila_Power_Default_Battery_Minimum_Voltage, Power_Registry["Maximum Voltage"] | Xila_Power_Default_Battery_Maximum_Voltage);
//    Set_Conversion_Factor(Power_Registry["Conversion Factor"] | Xila_Power_Default_Battery_Conversion_Factor);
//#endif

    return Result_Type::Success;
}

///
/// @brief Save power registry.
///
/// @return Result_Type
Result_Type Power_Class::Create_Registry()
{
    // - Open registry file
    StaticJsonDocument<256> Power_Registry;

    // - Set values in registry
    Power_Registry["Registry"] = "Power";

    // - Open registry file
    Drive_Types::File_Type Registry_File = Drive.Open(Registry("Power"), true);

    // - Write registry
    if (!Registry_File || (serializeJson(Power_Registry, Registry_File) == 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    // - Close registry file
    Registry_File.Close();
    return Result_Type::Success;
}

Result_Type Power_Class::Save_Registry()
{
    // - Open registry file
    Drive_Types::File_Type Registry_File = Drive.Open(Registry("Power"));

    // - Load registry
    StaticJsonDocument<256> Power_Registry;
    if (!Registry_File || (deserializeJson(Power_Registry, Registry_File) != DeserializationError::Ok) || (strcmp(Power_Registry["Registry"] | "", "Power") != 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();

    // - Set values in registry
    /*
    Power_Registry["Minimum Voltage"] = Get_Minimum_Voltage();
    Power_Registry["Maximum Voltage"] = Get_Maximum_Voltage();
    Power_Registry["Sensing Pin"] = Get_Sensing_Pin();
    Power_Registry["Conversion Factor"] = Get_Conversion_Factor();
    */

    // - Write registry
    if (serializeJson(Power_Registry, Registry_File) == 0)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    // - Close registry file
    Registry_File.Close();
    return Result_Type::Success;
}

void IRAM_ATTR Power_Class::Button_Interrupt_Handler()
{
#ifdef Xila_Power_Button_Default_Pin
    using namespace Xila_Namespace::Pin_Types;

    // vTaskEnterCritical(&Power.Button_Mutex);

    // - Released button (Falling edge )
    if (Pin.Digital_Read(Xila_Power_Button_Default_Pin) == Digital_State_Type::Low) // rise
    {
        // - If button is long pressed.
        if (Power.Button_Timer != 0 && Power.Button_Timer <= System.Get_Up_Time_Milliseconds())
        {
            Power.Button_Clicked = 0;
            Power.Restart();
        }
        // - If button is pressed.
        else
        {
            Power.Button_Timer = 0;
            Power.Button_Clicked = 1;
        }
    }
    // - Rising edge
    else
    {
        Power.Button_Timer = System.Get_Up_Time_Milliseconds() + Xila_Power_Button_Default_Long_Press_Time;
        Power.Button_Clicked = 0;
    }

    // vTaskExitCritical(&Power.Button_Mutex);
#endif
}

///
/// @brief Check if power button is pressed.
///
void Power_Class::Check_Button()
{
    if (Button_Clicked != 0)
    {
        Instruction_Type Instruction(this, NULL);
        Instruction.Power.Set_Code(Event_Code_Type::Power_Button_Pressed);
        Softwares.Send_Instruction_User_Softwares(Accounts.Get_Logged_User(), Instruction);

        Button_Clicked = 0;
    }
}

/// @brief Make the board go in deep sleep.
void Power_Class::Deep_Sleep()
{
    Log_Information("Power", "Going into deep-sleep.");

    /*Display.Set_Serial_Wake_Up(true);
    Display.Set_Touch_Wake_Up(false);
    Display.Set_Current_Page(F("Core_Load"));

    Pin.Digital_Write(Default_Display_Switching_Pin, Pin.Low);*/

    Drive.End();

    Task_Type::Delay_Static(10);
#ifdef Xila_Power_Button_Default_Pin
    esp_sleep_enable_ext0_wakeup((gpio_num_t)Xila_Power_Button_Default_Pin, HIGH);
#endif
    esp_deep_sleep_start();
}

void Power_Class::Restart()
{
    ESP.restart();
}