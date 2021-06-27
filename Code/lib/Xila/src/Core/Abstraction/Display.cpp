///
 /// @file Display.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 28-03-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 

#include "Core/Core.hpp"

Xila_Class::Display_Class::Display_Class()
    : Nextion_Class(),
      State(true),
      Brightness(Default_Display_Brightness),
      Receive_Pin(Default_Display_Receive_Pin),
      Standby_Time(Default_Display_Standby_Time),
      Transmit_Pin(Default_Display_Transmit_Pin)
{
    Baud_Rate = Default_Display_Baud_Rate;
}

Xila_Class::Display_Class::~Display_Class()
{
}

///
 /// @brief Load display registry
 /// 
 /// @return Xila_Class::Success or Xila_Class::Error
Xila_Class::Event Xila_Class::Display_Class::Load_Registry()
{
    File Temporary_File = Xila.Drive.Open(Registry("Display"));
    DynamicJsonDocument Display_Registry(256);
    if (deserializeJson(Display_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    if (strcmp("Display", Display_Registry["Registry"] | "") != 0)
    {
        return Error;
    }
    Standby_Time = Display_Registry["Standby Time"] | Default_Display_Standby_Time;
    Receive_Pin = Display_Registry["Receive Pin"] | Default_Display_Receive_Pin;
    Transmit_Pin = Display_Registry["Transmit Pin"] | Default_Display_Transmit_Pin;
    Baud_Rate = Display_Registry["Baud Rate"] | Default_Display_Baud_Rate;
    Brightness = Display_Registry["Brightness"] | Default_Display_Brightness;
    return Success;
}

///
 /// @brief Save display registry
 /// 
 /// @return Xila_Class::Event 
Xila_Class::Event Xila_Class::Display_Class::Save_Registry()
{
    File Temporary_File = Xila.Drive.Open(Registry("Display"), FILE_WRITE);
    DynamicJsonDocument Display_Registry(256);
    Display_Registry["Registry"] = "Display";
    Display_Registry["Brightness"] = Brightness;
    Display_Registry["Receive Pin"] = Receive_Pin;
    Display_Registry["Transmit Pin"] = Transmit_Pin;
    Display_Registry["Standby Time"] = Standby_Time;
    Display_Registry["Baud Rate"] = Baud_Rate;
    if (serializeJson(Display_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Error;
    }
    Temporary_File.close();
    return Success;
}

///
/// @brief Callback function for display incomming string data
///
/// @param Received_Data String received data
/// @param Size Size in bytes of received data
void Xila_Class::Display_Class::Incomming_String_Data_From_Display(const char *Received_Data, uint8_t Size)
{
    while (Xila.Software.Openned[0] == NULL)
    {
        Xila.Task.Delay(20);
    }
    switch (Received_Data[0])
    {
    case Xila.Display.Instruction:
        Xila.Software.Openned[0]->Send_Instruction(Instruction(Received_Data[1], Received_Data[2]));
        break;
    case Xila.Display.Variable_String:
        Xila.Software.Openned[0]->Set_Variable(Received_Data + 2, Variable_String, Received_Data[1]);
        Xila.Display.Tag = '\0';
        break;
    case Xila.Display.Variable_Long:
        Xila.Display.Tag = Received_Data[1];
        break;
    default:
        //error handle
        break;
    }
}

///
 /// @brief Callback function for display incomming numeric data
 /// 
 /// @param Received_Data Received numeric data from the display
void Xila_Class::Display_Class::Incomming_Numeric_Data_From_Display(uint32_t Received_Data)
{
    if (Xila.Display.Tag != '\0')
    {
        Xila.Software.Openned[0]->Set_Variable(&Received_Data, Xila.Display.Variable_Long, Xila.Display.Tag);
        Xila.Display.Tag = '\0';
    }
}

///
 /// @brief Callback function for display incomming event
 /// 
 /// @param Event_Code Event code
void Xila_Class::Display_Class::Incomming_Event_From_Display(uint8_t Event_Code)
{
    switch (Event_Code)
    {
    case Current_Page_Number:
        Xila.System.Refresh_Header();
        break;
    case Serial_Buffer_Overflow:
        break;
    case Auto_Entered_Sleep_Mode:
        Xila.Display.Set_State(false);
        break;
    case Auto_Wake_From_Sleep_Mode:
        Xila.Display.Set_State(true);
        Xila.System.Refresh_Header();
        break;
    default:
        break;
    }
    //Openned[0]->Send_Instruction((uint16_t)Event_Code);
}