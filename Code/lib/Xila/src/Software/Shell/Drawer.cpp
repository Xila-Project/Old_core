///
/// @file Drawer.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-09-2022
///
/// @copyright Copyright (c) 2022
///

#include "Software/Shell/Shell.hpp"

Shell_Class::Drawer_Class::Drawer_Class(Shell_Class *Shell_Pointer) : Shell_Pointer(Shell_Pointer)
{
    Log_Verbose("Drawer", "Drawer created");

    Window.Create(Shell_Pointer);
    Window.Set_Title("Drawer");

    Log_Trace();

    // - Set flex container
    Window.Get_Body().Set_Flex_Flow(Flex_Flow_Type::Column_Wrap);
    Window.Get_Body().Set_Style_Pad_Row(5, 0);
    Window.Get_Body().Set_Style_Pad_Column(5, 0);

    Log_Trace();

    {
        Object_Type Container;
        Button_Type Icon;
        Graphics_Types::Label_Type Label;
        Static_String_Class<Default_Software_Name_Length> Name;

        for (Byte_Type i; i < Softwares.Get_Handle_Count(); i++)
        {
            if (&Shell_Handle != Softwares.Get_Handle(i))
            {
                Log_Verbose("Drawer", "Adding software to drawer");
        
                Container.Create(Window.Get_Body());
                Container.Set_Size(10 * 8, 9 * 8);
                Container.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
                Container.Set_Style_Pad_All(0, 0);
                Container.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);

                Icon.Create(Container);
                Icon.Set_Size(32, 32);
                Icon.Set_Alignment(Alignment_Type::Top_Middle);
                Icon.Add_Flag(Flag_Type::Event_Bubble);
                Icon.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);

                Label.Create(Container);
                Label.Set_Size(Percentage(100), 32);
                Label.Set_Alignment(Alignment_Type::Bottom_Middle);
                Label.Set_Long_Mode(Graphics_Types::Long_Type::Dot);
                Label.Add_Flag(Flag_Type::Event_Bubble);
                Softwares.Get_Handle(i)->Get_Name(Name);
                Label.Set_Text(Name);
                Label.Add_Event(Shell_Pointer, Graphics_Types::Event_Code_Type::Clicked);

                Container.Clear_Pointer();
                Icon.Clear_Pointer();
                Label.Clear_Pointer();
            }
        }
    }
}

Shell_Class::Drawer_Class::~Drawer_Class()
{
    Window.Delete();
}

void Shell_Class::Drawer_Class::Execute_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Get_Sender() == &Graphics)
    {
        switch (Instruction.Graphics.Get_Code())
        {
        case Graphics_Types::Event_Code_Type::Clicked:
            for (uint8_t i = 0; i < Window.Get_Body().Get_Child_Count(); i++)
            {
                if (Instruction.Graphics.Get_Object() == Window.Get_Body().Get_Child(i))
                {
                    Softwares.Get_Handle(i)->Create_Instance(Shell_Pointer->Get_Owner_User());
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
}

void Shell_Class::Drawer_Class::Open(Shell_Class *Shell_Pointer)
{
    if (!Is_Openned(Shell_Pointer))
        Shell_Pointer->Drawer_Pointer = new Drawer_Class(Shell_Pointer);
}

void Shell_Class::Drawer_Class::Close(Shell_Class *Shell_Pointer)
{
    delete Shell_Pointer->Drawer_Pointer;
    Shell_Pointer->Drawer_Pointer = NULL;
}

bool Shell_Class::Drawer_Class::Is_Openned(Shell_Class *Shell_Pointer)
{
    return Shell_Pointer->Drawer_Pointer != NULL;
}