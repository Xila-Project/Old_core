/// @file Berry.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-03-2023
///
/// @copyright Copyright (c) 2023
///

#include "Software/Berry/Berry.hpp"

#ifdef __cplusplus
extern "C"
{
#endif
#include "berry.h"
#include "be_repl.h"
#include "be_vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
}
#endif

bool Berry_Class::Softwares_Handles_Loaded = false;

Berry_Class::Berry_Class(const Accounts_Types::User_Type *Owner_User) : Software_Type(&Berry_Handle, Owner_User), Window()
{
    Serial.begin(115200);
}

Berry_Class::~Berry_Class()
{
    Window.Delete();

    Virtual_Machine_Delete();
}

void Berry_Class::Execute_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Get_Sender() == &Softwares)
    {
        if (Instruction.Softwares.Get_Code() == Softwares_Types::Event_Code_Type::Close)
        {
            delete this;
        }
    }
    else
    {
        if (Instruction.Get_Sender() == &Graphics)
        {
            if (Instruction.Graphics.Get_Code() == Graphics_Types::Event_Code_Type::Clicked)
            {
               
            }

        }
    }
}

void Berry_Class::Main_Task_Function()
{
    Instruction_Type Instruction;

    Window.Create(this);

    if (this->Get_Handle() == &Berry_Handle && !Softwares_Handles_Loaded)
        Load_Softwares_Handles();

    Virtual_Machine_Create();

    // - REPL
    if (this->Get_Handle() == &Berry_Handle)
    {

        Log_Verbose("Berry", "Starting REPL");

        if (REPL() != Result_Type::Success)
        {
            // TODO : Add dialog
        }
    }
    // - Other
    else
    {
        Static_String_Type<32> Name;
        this->Get_Handle()->Get_Name(Name);

        Window.Set_Title(Name);

        Static_String_Type<64> Path;
        Path = Software_Directory_Path;
        Path += "/";
        Path += Name;
        Path += ".Xrf";
        if (Virtual_Machine_Load_File(Path) != Result_Type::Success)
        {
            // TODO : Add dialog to show the error.
            delete this;
        }

        if (Call(0) != Result_Type::Success)
        {
            // TODO : Add dialog
        }
    }

    delete this;
}

void Berry_Class::Virtual_Machine_Create()
{
    Virtual_Machine = be_vm_new();
}

void Berry_Class::Virtual_Machine_Delete()
{
    be_vm_delete(Virtual_Machine);
}

void Berry_Class::Load_Softwares_Handles()
{
    if (Softwares_Handles_Loaded)
        return;

    File_Type Softwares_Folder = Drive.Open(Software_Directory_Path);
    if (!Softwares_Folder)
        return;

    Softwares_Folder.Rewind_Directory();

    File_Type Software_Folder = Softwares_Folder.Open_Next_File();

    while (Software_Folder)
    {
        if (!Software_Folder.Is_Directory())
            continue;

        Static_String_Type<32> Manifest_Path = Software_Folder.Get_Path();
        Manifest_Path += "/Manifest.Xrf";
        File_Type Manifest_File = Drive.Open(Manifest_Path);

        StaticJsonDocument<512> Software_Manifest;
        if (!Manifest_File || deserializeJson(Software_Manifest, Manifest_File) != DeserializationError::Ok)
        {
            Software_Folder.Close();
            continue;
        }

        if (strcmp(Software_Manifest["Type"] | "", "Software") != 0)
        {
            Software_Folder.Close();
            continue;
        }

        if (strcmp(Software_Manifest["Format"] | "", "Berry") != 0)
        {
            Software_Folder.Close();
            continue;
        }

        new Berry_Softwares_Handle_Class(Software_Manifest["Type"] | "");

        Software_Folder.Close();
        Software_Folder = Softwares_Folder.Open_Next_File();
    }

    Softwares_Handles_Loaded = true;
}

void Berry_Class::Virtual_Machine_Register_Function(const char *Name, bntvfunc Function)
{
    be_regfunc(Virtual_Machine, Name, Function);
}

Result_Type Berry_Class::Virtual_Machine_Load_File(const char *Path)
{
    Byte_Type Error = be_loadfile(Virtual_Machine, Path);
    if (Error != BE_OK)
        return Result_Type::Error;
    return Result_Type::Success;
}

Result_Type Berry_Class::Virtual_Machine_Load_String(const char *String)
{
    Byte_Type Error = be_loadstring(Virtual_Machine, String);
    if (Error != BE_OK)
        return Result_Type::Error;
    return Result_Type::Success;
}

Result_Type Berry_Class::Call(Integer_Type Argument_Count)
{
    Byte_Type Error = be_pcall(Virtual_Machine, Argument_Count);
    if (Error != BE_OK)
        return Result_Type::Error;
    return Result_Type::Success;
}

Result_Type Berry_Class::REPL()
{
    // - Set interface

    Window.Set_Title("Berry");
    Window.Set_Flex_Flow(Flex_Flow_Type::Column);

    Prompt_Label_Text = new char[(80 + 1) * 24 + 1];

    memset(Prompt_Label_Text, 0, (80 + 1) * 24 + 1);

    Prompt_Label.Create(Window.Get_Body());
    Prompt_Label.Set_Width(Percentage(100));
    Prompt_Label.Set_Flex_Grow(1);
    Prompt_Label.Set_Text_Static(Prompt_Label_Text);

    Input_Text_Area.Create(Window.Get_Body());
    Input_Text_Area.Set_Size(Percentage(100), 40);



//    Byte_Type Error = be_repl(Virtual_Machine, 
//    [](Berry_Class* Berry, const char* Prompt) -> char* {return Berry->Get_Line(Prompt);},
//    [](Berry_Class* Berry, const char* Line) -> void {Berry->Free_Line(Line);});

 //   if (Error != BE_OK)
 //       return Result_Type::Error;
    return Result_Type::Success;
}