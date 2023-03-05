///
/// @file Installer.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 23-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Software/Shell/Shell.hpp"

void Shell_Class::Installer_Class::Open(Shell_Class *Shell_Pointer)
{
    Shell_Pointer->Installer_Pointer = new Installer_Class(Shell_Pointer);
}

void Shell_Class::Installer_Class::Close(Shell_Class *Shell_Pointer)
{
    delete Shell_Pointer->Installer_Pointer;
    Shell_Pointer->Installer_Pointer = NULL;
}

bool Shell_Class::Installer_Class::Is_Openned(Shell_Class *Shell_Pointer)
{
    return (Shell_Pointer->Installer_Pointer != NULL);
}

Shell_Class::Installer_Class::Installer_Class(Shell_Class *Shell_Pointer) : Shell_Pointer(Shell_Pointer)
{
    Dialog.Create(Shell_Pointer->Desk.Window);
    Dialog.Set_Title("Installer");
    Dialog.Set_Overlay(true);
    Dialog.Get_Body().Set_Flex_Flow(Flex_Flow_Type::Column);
    Dialog.Get_Body().Set_Flex_Alignment(Flex_Alignment_Type::Space_Evenly, Flex_Alignment_Type::Center, Flex_Alignment_Type::Center);

    {
        Object_Type Logo;
        Logo.Create(Dialog.Get_Body());
        Logo.Set_Size(4 * 16, 4 * 16);
        Logo.Set_Style_Pad_All(0, 0);
        Logo.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);

        {
            Object_Type Red;
            Red.Create(Logo);
            Red.Set_Size((4 * 5), (4 * 10));
            Red.Set_Alignment(Alignment_Type::Top_Left);
            Red.Set_Style_Pad_All(0, 0);
            Red.Set_Style_Background_Color(Color_Type::Xila_Red, 0);
        }

        {
            Object_Type Green;
            Green.Create(Logo);
            Green.Set_Size((4 * 5), (4 * 10));
            Green.Set_Alignment(Alignment_Type::Bottom_Right);
            Green.Set_Style_Pad_All(0, 0);
            Green.Set_Style_Background_Color(Color_Type::Xila_Green, 0);
        }

        {
            Object_Type Blue;
            Blue.Create(Logo);
            Blue.Set_Size((4 * 10), (4 * 5));
            Blue.Set_Alignment(Alignment_Type::Bottom_Left);
            Blue.Set_Style_Pad_All(0, 0);
            Blue.Set_Style_Background_Color(Color_Type::Xila_Blue, 0);
        }

        {
            Object_Type Yellow;
            Yellow.Create(Logo);
            Yellow.Set_Size((4 * 10), (4 * 5));
            Yellow.Set_Alignment(Alignment_Type::Top_Right);
            Yellow.Set_Style_Pad_All(0, 0);
            Yellow.Set_Style_Background_Color(Color_Type::Xila_Yellow, 0);
        }
    }

    {
        Graphics_Types::Label_Type Welcome_Label;
        Welcome_Label.Create(Dialog.Get_Body());
        Welcome_Label.Set_Text("Welcome to Xila OS installer!");
    }
    
    Setup_Button.Create(Dialog.Get_Body());
    Setup_Button.Set_Size(LV_PCT(100), 40);

    {
        Graphics_Types::Label_Type Setup_Label;
        Setup_Label.Create(Setup_Button);
        Setup_Label.Set_Text("Setup");
        Setup_Label.Set_Alignment(Alignment_Type::Center);
    }

    Username_Text_Area.Create(Dialog.Get_Body());
    Username_Text_Area.Set_Size(LV_PCT(80), 40);
    Username_Text_Area.Set_Placeholder_Text("Username");
    Username_Text_Area.Set_One_Line(true);
    Username_Text_Area.Set_Maximum_Length(20);
    Username_Text_Area.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Focused);
    Username_Text_Area.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Defocused);
    Username_Text_Area.Add_Flag(Flag_Type::Hidden);

    Password_Text_Area.Create(Dialog.Get_Body());
    Password_Text_Area.Set_Size(LV_PCT(80), 40);
    Password_Text_Area.Set_Placeholder_Text("Password");
    Password_Text_Area.Set_Password_Mode(true);
    Password_Text_Area.Set_One_Line(true);
    Password_Text_Area.Set_Maximum_Length(20);
    Password_Text_Area.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Focused);
    Password_Text_Area.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Defocused);

    Create_Account_Button.Create(Dialog.Get_Body());
    Create_Account_Button.Set_Size(LV_PCT(80), 40);

    {
        Graphics_Types::Label_Type Create_Account_Label;
        Create_Account_Label.Create(Create_Account_Button);
        Create_Account_Label.Set_Text("Create account");
        Create_Account_Label.Set_Alignment(Alignment_Type::Center);
    }
    
}
