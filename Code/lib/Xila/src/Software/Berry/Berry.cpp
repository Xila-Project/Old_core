/// @file Berry.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-03-2023
///
/// @copyright Copyright (c) 2023
///

#include "Software/Berry/Berry.hpp"



extern "C"
{
#include "berry.h"
#include "be_repl.h"
#include "be_vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

char *Prompt_String;

bool Berry_Class::Softwares_Handles_Loaded = false;

Berry_Class::Berry_Class(const Accounts_Types::User_Type *Owner_User)
    : Software_Type(&Berry_Handle, Owner_User, 8 * 1024),
      Input_String(NULL)
{
     
}

Berry_Class::Berry_Class(const Accounts_Types::User_Type* Owner_User, const Berry_Softwares_Handle_Class* Handle)
    : Software_Type(Handle, Owner_User, 8 * 1024),
      Input_String(NULL)
{
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
            switch (Instruction.Graphics.Get_Code())
            {
            case Graphics_Types::Event_Code_Type::Clicked:
                break;

            case Graphics_Types::Event_Code_Type::Focused:
                if (Instruction.Graphics.Get_Target() == Input_Text_Area)
                    Keyboard.Set_Text_Area(Input_Text_Area);
                break;
            case Graphics_Types::Event_Code_Type::Defocused:
                if (Instruction.Graphics.Get_Target() == Input_Text_Area)
                    Keyboard.Remove_Text_Area();
                break;
            case Graphics_Types::Event_Code_Type::Ready:
                if (Instruction.Graphics.Get_Target() == Keyboard)
                {
                    strlcpy(Input_String, Input_Text_Area.Get_Text(), 80 + 1);
                    Input_Text_Area.Set_Text("");
                }
                break;
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

        REPL();
    }
    // - Other
    else
    {
        Log_Verbose("Berry", "Starting custom software")

            //   Static_String_Type<32> Name;
            //   this->Get_Handle()->Get_Name(Name);
            //
            //   Window.Set_Title(Name);
            //
            //   Static_String_Type<64> Path;
            //   Path = Software_Directory_Path;
            //   Path += "/";
            //   Path += Name;
            //   Path += ".Xrf";

        Window.Set_Title("Berry");
        Window.Get_Body().Set_Flex_Flow(Flex_Flow_Type::Column);

        char Prompt_String_Local[(80 + 1) * 24 + 1];
        char Input_String[80 + 1];

        Prompt_String = Prompt_String_Local;
        this->Input_String = Input_String;

        memset(Prompt_String, 0, (80 + 1) * 24 + 1);
        memset(this->Input_String, 0, 80 + 1);

        Prompt_Container.Create(Window.Get_Body());
        Prompt_Container.Set_Width(Percentage(100));
        Prompt_Container.Set_Flex_Grow(1);
        Prompt_Container.Set_Style_Pad_All(0, 0);
        Prompt_Container.Clear_Flag(Flag_Type::Scroll_Elastic); // - Remove, very annoying.

        Prompt_Label.Create(Prompt_Container);
        Prompt_Label.Set_Width(Percentage(100));
        Prompt_Label.Set_Text_Static(Prompt_String_Local);

        Input_Text_Area.Create(Window.Get_Body());
        Input_Text_Area.Set_Size(Percentage(100), 40);
        Input_Text_Area.Add_Event(this, Graphics_Types::Event_Code_Type::Focused);
        Input_Text_Area.Add_Event(this, Graphics_Types::Event_Code_Type::Defocused);
        Input_Text_Area.Set_Placeholder_Text(">_");
        Input_Text_Area.Set_Maximum_Length(80);
        Input_Text_Area.Set_One_Line(true);

        Keyboard.Create(Window.Get_Body());
        Keyboard.Remove_Text_Area();
        Keyboard.Add_Event(this, Graphics_Types::Event_Code_Type::Ready);

        Prompt_Label.Delete();
        Input_Text_Area.Delete();


        if (Virtual_Machine_Load_File("/test.be") != Result_Type::Success)
        {
            Log_Verbose("Berry", "Failed to load file");
            // TODO : Add dialog to show the error.
            delete this;
        }

        if (Call(0) != Result_Type::Success)
        {
            // TODO : Add dialog
        }


        Prompt_String = NULL;
        this->Input_String = NULL;
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
