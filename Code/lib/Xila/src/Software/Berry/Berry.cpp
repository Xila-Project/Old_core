/// @file Berry.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-03-2023
///
/// @copyright Copyright (c) 2023
///

#include "Software/Berry/Berry.hpp"

bool Berry_Class::Softwares_Handles_Loaded = false;

Berry_Class::Berry_Class() : Software_Type(&Berry_Handle), Window()
{
    Window.Create(this);

    if (this->Get_Handle() == &Berry_Handle && !Softwares_Handles_Loaded)
        Load_Softwares_Handles();

        

    Virtual_Machine_Create();
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
}

void Berry_Class::Main_Task_Function()
{
    Instruction_Type Instruction;

    if (this->Get_Handle() == &Berry_Handle)
    {

    }
    else
    {
        Static_String_Type<32> Name;
        this->Get_Handle()->Get_Name(Name);

        Static_String_Type<64> Path;
        Path = Software_Directory_Path;
        Path += "/";
        Path += Name;
        Path += ".Xrf";
        if (!Virtual_Machine_Load_File(Path))
        {
            delete this;
        }
    }

    while (true)
    {
        if (this->Instruction_Available())
        {
            Instruction = this->Get_Instruction();
            Execute_Instruction(Instruction);
        }
        else
        {
            Main_Task.Delay(50);
        }
    }
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

    File_Type Softwares_Folder = Drive.Open(Users_Directory_Path);
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
            continue;

        if (strcmp(Software_Manifest["Type"] | "", "Software") != 0)
            continue;
        
        if (strcmp(Software_Manifest["Format"] | "", "Berry") != 0)
            continue;

        new Berry_Softwares_Handle_Class(Software_Manifest["Type"] | "");

        Software_Folder = Softwares_Folder.Open_Next_File();
    }
    Softwares_Handles_Loaded = true;
}

void Berry_Class::Virtual_Machine_Register_Function(const char *Name, bntvfunc Function)
{
    be_regfunc(Virtual_Machine, Name, Function);
}

bool Berry_Class::Virtual_Machine_Load_File(const char *Path)
{
    return be_loadfile(Virtual_Machine, Path);
}