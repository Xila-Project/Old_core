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
    Window.Create();
    Window.Set_Title("Drawer");

    Window.Get_Body().Set_Flex_Flow(Flex_Flow_Type::Row);

    List.Create(Window.Get_Body());
    List.Set_Size(Percentage(100), Percentage(100));

    List.Set_Flex_Flow(Flex_Flow_Type::Column_Wrap);
    List.Set_Style_Pad_All(10, 0);
    List.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);

    {
        Object_Type Container;
        Button_Type Icon;
        Label_Type Label;

        for (auto &Software_Handle_Pointer : Software_Handle_Class::List)
        {
            if (*Software_Handle_Pointer != Shell_Class::Handle)
            {
                Container.Create(List);
                Container.Set_Size(Percentage(100), Percentage(100));
                Container.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
                Container.Set_Style_Pad_All(0, 0);

                Icon.Create(Container);
                Icon.Set_Size(Percentage(100), Percentage(100));
                Icon.Set_Alignment(Alignment_Type::Top_Middle);
                Icon.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);

                Label.Create(Container);
                Label.Set_Text_Format("Item");
                Label.Set_Alignment(Alignment_Type::Bottom_Middle);
                Label.Set_Long_Mode(Label_Type::Long_Dot);
                Label.Add_Event(Shell_Pointer, Graphics_Type::Event_Code_Type::Pressed);

                Container.Clear_Pointer();
                Icon.Clear_Pointer();
                Label.Clear_Pointer();
            }
        }
    }
}

Shell_Class::Drawer_Class::~Drawer_Class()
{
    List.Delete();
    Window.Delete();
}

void Shell_Class::Drawer_Class::Execute_Instruction(Instruction_Type Instruction)
{
    if (Instruction.Get_Sender() == &Graphics)
    {
        switch (Instruction.Graphics.Get_Code())
        {
        case Graphics_Type::Pressed :
            for (uint8_t i = 0; i < List.Get_Child_Count(); i++)
            {
                if ((Instruction.Graphics.Get_Object() == List.Get_Child(i).Get_Child(0)) || (Instruction.Graphics.Get_Object().Get_Child(1) == List.Get_Child(i).Get_Child(1)))
                {
                    Software_Handle_Class::List[i]->Create_Instance();
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
    Shell_Pointer->Drawer_Pointer = new Drawer_Class(Shell_Pointer);
}

void Shell_Class::Drawer_Class::Close(Shell_Class *Shell_Pointer)
{
    delete Shell_Pointer->Drawer_Pointer;
    Shell_Pointer->Drawer_Pointer = NULL;
}

bool Shell_Class::Drawer_Class::Is_Open(Shell_Class *Shell_Pointer)
{
    if (Shell_Pointer->Drawer_Pointer == NULL)
    {
        return true;
    }
    return false;
}