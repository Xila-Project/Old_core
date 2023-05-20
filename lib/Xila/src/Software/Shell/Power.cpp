/// @file Power.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 17-05-2023
///
/// @copyright Copyright (c) 2023

#include "Software/Shell/Shell.hpp"

Shell_Class::Power_Class::Power_Class(Shell_Class &Shell) : Shell(Shell)
{
    using namespace Graphics_Types;

    Dialog.Create(&Shell);

    Dialog.Set_Title("Power");
    Dialog.Get_Body().Set_Flex_Flow(Flex_Flow_Type::Column);
    Dialog.Get_Body().Set_Flex_Alignment(Flex_Alignment_Type::Space_Evenly, Flex_Alignment_Type::Center, Flex_Alignment_Type::Center);

    Dialog.Add_Event(&Shell, Event_Code_Type::Delete);

    Shutdown_Button.Create(Dialog.Get_Body(), LV_SYMBOL_POWER "Shutdown");
    Shutdown_Button.Add_Event(&Shell, Graphics_Types::Event_Code_Type::Clicked);
    
    Restart_Button.Create(Dialog.Get_Body(), LV_SYMBOL_REFRESH "Reboot");
    Restart_Button.Add_Event(&Shell, Graphics_Types::Event_Code_Type::Clicked);

    Static_String_Type<24> User_Name;
    if (Shell.Get_Owner_User()->Get_Name(User_Name) != "Xila")
    {
        Logout_Button.Create(Dialog.Get_Body(), LV_SYMBOL_NEW_LINE "Logout");
        Logout_Button.Add_Event(&Shell, Graphics_Types::Event_Code_Type::Clicked);
    }
}

Shell_Class::Power_Class::~Power_Class()
{
    Dialog.Delete();
}

void Shell_Class::Power_Class::Open(Shell_Class &Shell)
{
    using namespace Graphics_Types;
    if (!Is_Openned(Shell))
        Shell.Power_Pointer = new Power_Class(Shell);
    else
        Shell.Power_Pointer->Dialog.Set_State(Window_State_Type::Maximized);
}

bool Shell_Class::Power_Class::Is_Openned(Shell_Class &Shell)
{
    using namespace Graphics_Types;
    if (!Shell.Power_Pointer || !Shell.Power_Pointer->Dialog.Is_Valid())
        return false;

    return Shell.Power_Pointer->Dialog.Get_State() == Window_State_Type::Maximized;
}

void Shell_Class::Power_Class::Close(Shell_Class &Shell)
{
    if (Is_Openned(Shell))
    {
        delete Shell.Power_Pointer;
        Shell.Power_Pointer = NULL;
    }
}

void Shell_Class::Power_Class::Execute_Instruction(const Instruction_Type& Instruction)
{
    using namespace Graphics_Types;

    Object_Type Current_Target = Instruction.Graphics.Get_Current_Target();
    switch (Instruction.Graphics.Get_Code())
    {
    case Event_Code_Type::Clicked:
        if (Current_Target == Shutdown_Button)
            System.Shutdown();
        else if (Current_Target == Restart_Button)
            System.Restart();
        else if (Current_Target == Logout_Button)
            const_cast<Accounts_Types::User_Type*>(Shell.Get_Owner_User())->Logout();
        break;
    case Event_Code_Type::Delete:
        Close(Shell);
        break;
    }
}