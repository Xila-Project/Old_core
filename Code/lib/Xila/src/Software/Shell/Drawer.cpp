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

const Module_Class::Instruction_Type Shell_Class::Drawer_Class::Click_On_Item(NULL, NULL, "Clic");

Shell_Class::Drawer_Class::Drawer_Class(Shell_Class *Shell_Pointer) : Shell_Pointer(Shell_Pointer)
{
    Window.Create();
    Window.Set_Title("Drawer");

    List.Create(Window.Get_Body());
    List.Set_Size(Percentage(100), Percentage(100));
    List.Set_Flex_Flow(Object_Type::Flex::Column_Wrap);
    List.Set_Style_Pad_All(10, 0);
    List.Set_Style_Background_Opacity(Object_Type::Opacity::Transparent, 0);

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
                Container.Set_Style_Background_Opacity(Object_Type::Opacity::Transparent, 0);
                Container.Set_Style_Pad_All(0, 0);

                Icon.Create(Container);
                Icon.Set_Size(Percentage(100), Percentage(100));
                Icon.Set_Alignment(Alignment_Type::Top_Middle);
                Icon.Add_Event(&Click_On_Item, Types_Class::Event::Pressed);

                Label.Create(Container);
                Label.Set_Text_Format("Item");
                Label.Set_Alignment(Alignment_Type::Bottom_Middle);
                Label.Set_Long_Mode(Label_Type::Long_Dot);
                Label.Add_Event(&Click_On_Item, Types_Class::Event::Pressed);

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
    if (Instruction == Click_On_Item)
    {
        // TODO : Open software from drawer
        // Open_From_Drawer(0);
    }
    else
    {
        Shell_Pointer->Execute_Instruction(Instruction);
    }
}

// TODO : Open software from drawer
/*
void Shell_Class::Drawer_Class::Open_From_Drawer(uint8_t Slot)
{
if ((Slot + Offset) < (sizeof(Software_Management.Handle) / sizeof(Xila_Class::Software_Handle *)))
{
    if (Software_Management.Handle[Slot + Offset] != NULL)
    {
        if (Software_Management.Open(*Software_Management.Handle[Slot + Offset]) != Success)
        {
            DIALOG.Event(Event_Error_Open_Software, Error);
            Instance_Pointer->Send_Instruction('R', 'e');
        }
    }
    else
    {
        DESK.Open(Pages.Drawer);
    }
}
else
{
    DESK.Open(Pages.Drawer);
}
}
*/
