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

/// @brief Shell constructor.
Shell_Class::Shell_Class() : Software_Class(&Handle), Desk(this)
{
    if (this->Load_Registry() != Result_Type::Success)
    {
        this->Create_Registry();
    }
}

/// @brief Shell destructor.
Shell_Class::~Shell_Class()
{
    this->Save_Registry();
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
            if (this->Get_Owner_User()->Get_State() == Accounts_Types::User_State_Type::Locked)
            {
                if (Desk.Window.Get_State() != Graphics_Types::Window_State_Type::Minimized)
                {
                    Desk.Window.Set_State(Graphics_Types::Window_State_Type::Minimized);
                }
            }
            else if (System.Get_Up_Time_Milliseconds() > Next_Refresh)
            {
                Desk.Refresh_Overlay();
                Next_Refresh = System.Get_Up_Time_Milliseconds() + 5000;
            }
            
            Main_Task.Delay(40);
        }
    }
}

/// @brief 
/// @param Instruction 
void Shell_Class::Execute_Instruction(Instruction_Type Instruction)
{
    if (Instruction.Get_Sender() == &Softwares)
    {
        switch (Instruction.Softwares.Get_Code())
        {
            case Softwares_Types::Event_Code_Type::Close:
                delete this;
                break;
        }
    }

    else if (Drawer_Class::Is_Openned(this) && (Drawer_Pointer->Window.Get_State() == Graphics_Types::Window_State_Type::Maximized))
    {
        Drawer_Pointer->Execute_Instruction(Instruction);
    }
    else if (Installer_Class::Is_Openned(this) && (Installer_Pointer->Dialog.Get_State() == Graphics_Types::Window_State_Type::Maximized))
    {
        Installer_Pointer->Execute_Instruction(Instruction);
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
    // - Open registry file
    Static_String_Type<64> Shell_Registry_Path;
    this->Get_Owner_User()->Get_Home_Folder_Path(Shell_Registry_Path);
    Shell_Registry_Path += "/Shell/Shell.xrf";
    File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

    // - Load registry
    StaticJsonDocument<256> Shell_Registry;
    if (!Registry_File || (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok) || (strcmp("Shell", Shell_Registry["Registry"] | "") != 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();

    // - Load registry values
    this->Desk.Set_Background_Color(Color_Type(Shell_Registry["Desk"]["Background color"] | Shell_Default_Background_Color));
    this->Desk.Set_Foreground_Color(Color_Type(Shell_Registry["Desk"]["Foreground color"] | Shell_Default_Foreground_Color));
    
    return Result_Type::Success;
}

Result_Type Shell_Class::Create_Registry()
{
    // - 
    StaticJsonDocument<256> Shell_Registry;
    Shell_Registry["Registry"] = "Shell";
    Shell_Registry.createNestedObject("Desk");

    // - Open registry file
    Static_String_Type<64> Shell_Registry_Path;
    this->Get_Owner_User()->Get_Home_Folder_Path(Shell_Registry_Path);
    Shell_Registry_Path += "/Registry/Shell.xrf";
    File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

    // - Write registry
    if (!Registry_File || (serializeJson(Shell_Registry, Registry_File) == 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    Registry_File.Close();
    return Result_Type::Success;
}

/// @brief Save shell registry.
/// @return 
Result_Type Shell_Class::Save_Registry()
{
    // - Open registry file
    Static_String_Type<64> Shell_Registry_Path;
    this->Get_Owner_User()->Get_Home_Folder_Path(Shell_Registry_Path);
    Shell_Registry_Path += "/Registry/Shell.xrf";
    File_Type Registry_File = Drive.Open(Shell_Registry_Path, true);

    // - Load registry
    StaticJsonDocument<256> Shell_Registry;
    if (!Registry_File || (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok) || ((strcmp("Shell", Shell_Registry["Registry"] | "") != 0)))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    // - Save registry values
    Shell_Registry["Background color"] = static_cast<uint32_t>(Desk.Get_Background_Color());
    Shell_Registry["Foreground color"] = static_cast<uint32_t>(Desk.Get_Foreground_Color());

    // - Write registry
    if (serializeJson(Shell_Registry, Registry_File) == 0)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    // - Close registry file
    Registry_File.Close();
    return Result_Type::Success;
}
