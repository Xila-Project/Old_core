///
/// @file Shell.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila main user interface source file.
/// @version 0.1.0
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/Shell/Shell.hpp"
#include "Software/Shell/Translation.hpp"

Xila::Software_Handle_Type Shell_Class::Handle("Shell", Shell_Class::Create_Instance);

/// @brief Shell constructor.
Shell_Class::Shell_Class() : Software_Class(&Handle), Desk(this)
{
}

/// @brief Shell destructor.
Shell_Class::~Shell_Class()
{
    Drawer_Class::Close(this);
    Login_Class::Close(this);
    Installer_Class::Close(this);
}


Software_Type *Shell_Class::Open_Shell()
{
    return new Shell_Class();
}

/// @brief Shell main task.
void Shell_Class::Main_Task_Function()
{
    uint32_t Next_Refresh = 0;
    while (1)
    {
        if (this->Instruction_Available())
        {
            this->Execute_Instruction(Get_Instruction());
        }
        else
        {
            if (System.Get_Up_Time_Milliseconds() > Next_Refresh)
            {
                Desk.Refresh_Overlay();
                Next_Refresh = System.Get_Up_Time_Milliseconds() + 1000;
            }
            Main_Task.Delay(40);
        }
    }
}

/// @brief 
/// @param Instruction 
void Shell_Class::Execute_Instruction(Instruction_Type Instruction)
{
    if (Drawer_Class::Is_Openned(this))
    {
        if (Drawer_Pointer->Window.Get_State() == Graphics_Types::Window_State_Type::Maximized)
        {
            Drawer_Pointer->Execute_Instruction(Instruction);
        }
    }
    else if (Installer_Class::Is_Openned(this))
    {
        if (Installer_Pointer->Dialog.Get_State() == Graphics_Types::Window_State_Type::Maximized)
        {
            Installer_Pointer->Execute_Instruction(Instruction);
        }
    }
    else
    {
        Desk.Execute_Instruction(Instruction);
    }

}

// -- Shell registry management -- //

/// @brief Load shell registry.
/// @return 
Result_Type Shell_Class::Load_Registry()
{
    /*
    char User_Registry_Path[40];
    snprintf(User_Registry_Path, sizeof(User_Registry_Path), (Users_Directory_Path "/%s/Shell/Shell.xrf"), Account.Get_Logged_User()->Get_Name());

    File_Type Registry_File = Drive.Open(User_Registry_Path, true);
    DynamicJsonDocument Shell_Registry(256);
    if (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();
  
    if (strcmp("Shell", Shell_Registry["Registry"] | "") != 0)
    {
        DESK.Background = Default_Background;
        return Result_Type::Error;
    }
    DESK.Background = Shell_Registry["Desk Background"] | Default_Background;
    */
    return Result_Type::Success;
}

Result_Type Shell_Class::Create_Registry()
{
    

}

/// @brief Save shell registry.
/// @return 
Result_Type Shell_Class::Save_Registry()
{
    Static_String_Type<64> Shell_Registry_Path = Users_Directory_Path;
    Shell_Registry_Path += "/";
    Shell_Registry_Path += Accounts.Get_Current_Username();
    Shell_Registry_Path += "/Registry/Shell.xrf";

    File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

    StaticJsonDocument<256> Shell_Registry;
    deserializeJson(Shell_Registry, Registry_File);
    Shell_Registry["Registry"] = "Shell";
    Shell_Registry["Desk background"] = Desk.Background;
    if (serializeJson(Shell_Registry, Registry_File) == 0)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();
    return Result_Type::Success;
}
