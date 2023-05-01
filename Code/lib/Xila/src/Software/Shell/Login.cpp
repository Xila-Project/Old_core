///
/// @file Login.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 13-01-2023
///
/// @copyright Copyright (c) 2023
///

#include "Software/Shell/Shell.hpp"

Shell_Class::Login_Class::Login_Class(Shell_Class *Shell_Pointer) : Shell_Pointer(Shell_Pointer)
{
    using namespace Graphics_Types;

    Dialog.Create(Shell_Pointer);
    Dialog.Set_Title("Login");
    Dialog.Get_Body().Set_Flex_Flow(Flex_Flow_Type::Column);
    Dialog.Get_Body().Set_Flex_Alignment(Flex_Alignment_Type::Space_Evenly, Flex_Alignment_Type::Center, Flex_Alignment_Type::Center);

    Name_Input.Create(Dialog.Get_Body());
    Name_Input.Set_Size(Percentage(80), 40);
    Name_Input.Set_Placeholder_Text("Username");
    Name_Input.Set_One_Line(true);
    Name_Input.Set_Maximum_Length(Maximum_Username_Length);
    Name_Input.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Focused);
    Name_Input.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Defocused);

    Password_Input.Create(Dialog.Get_Body());
    Password_Input.Set_Size(Percentage(80), 40);
    Password_Input.Set_Placeholder_Text("Password");
    Password_Input.Set_Password_Mode(true);
    Password_Input.Set_One_Line(true);
    Password_Input.Set_Maximum_Length(Maximum_Password_Length);
    Password_Input.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Focused);
    Password_Input.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Defocused);

    Login_Button.Create(Dialog.Get_Body(), "Login", Percentage(50), 40);
    Login_Button.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);
}

Shell_Class::Login_Class::~Login_Class()
{
    Dialog.Delete();
}

void Shell_Class::Login_Class::Open(Shell_Class *Shell_Pointer)
{
    if (!Is_Openned(Shell_Pointer))
        Shell_Pointer->Login_Pointer = new Login_Class(Shell_Pointer);
}

void Shell_Class::Login_Class::Close(Shell_Class *Shell_Pointer)
{
    delete Shell_Pointer->Login_Pointer;
    Shell_Pointer->Login_Pointer = NULL;
}

bool Shell_Class::Login_Class::Is_Openned(Shell_Class *Shell_Pointer)
{
    return Shell_Pointer->Login_Pointer != NULL;
}

void Shell_Class::Login_Class::Execute_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Get_Sender() == &Graphics)
    {
        switch (Instruction.Graphics.Get_Code())
        {
        case Graphics_Types::Event_Code_Type::Focused:
            if (Instruction.Graphics.Get_Target() == Name_Input)
            {
                Log_Verbose("Shell", "Focused on name input");
                Shell_Pointer->Keyboard.Set_Text_Area(Name_Input);
            }
            else if (Instruction.Graphics.Get_Target() == Password_Input)
            {
                Log_Verbose("Shell", "Focused on password input");
                Shell_Pointer->Keyboard.Set_Text_Area(Password_Input);
            }
            break;
        case Graphics_Types::Event_Code_Type::Defocused:
            Log_Verbose("Shell", "Defocused on name or password input");
            Shell_Pointer->Keyboard.Remove_Text_Area();
            break;
        case Graphics_Types::Event_Code_Type::Clicked:
            if (Instruction.Graphics.Get_Target() == Login_Button)
            {    
                Drive.Remove_Directory("/Users/Alix", true);

                // - Print Users dir content 
                Log_Verbose("Shell", "Users dir content :");
                
                File_Type Users = Drive.Open("/Users");
                Users.Rewind_Directory();

                File_Type Item = Users.Open_Next_File();
                while (Item)
                {
                    Log_Verbose("Login", "%s", Item.Get_Name());
                    Item = Users.Open_Next_File();
                }                

                Accounts.Create("Alix", "");

                Name_Input.Set_Text("Alix");                
                Password_Input.Set_Text("");

                if (Accounts.Login(Name_Input.Get_Text(), Password_Input.Get_Text()) == Result_Type::Success)
                {
                    Softwares.Open(Shell_Pointer->Get_Handle(), Accounts.Get_User(Accounts.Find_User(Name_Input.Get_Text())));
                }
                else
                {
                    Name_Input.Set_Style_Border_Color(Graphics_Types::Color_Type::Red[5], 0);
                    Password_Input.Set_Style_Border_Color(Graphics_Types::Color_Type::Red[5], 0);
                }
            }
        }
    }
}