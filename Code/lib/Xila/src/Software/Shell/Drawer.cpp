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

Shell_Class::Drawer_Class::Drawer_Class()
{
    Window.Create();

    List.Create(Window.Get_Body());
    List.Set_Size(Percentage(100), Percentage(100));
    List.Set_Flex_Flow(Object_Type::Flex::Column_Wrap);
    List.Set_Style_Pad_All(10, 0);
    List.Set_Style_Background_Opacity(Object_Type::Opacity::Transparent, 0);

    {
        Object_Type Container;
        Button_Type Icon;
        Label_Type Label;

        for (uint8_t i = 0; i < 60; i++)
        {
            Container.Create(List);
            Container.Set_Size(Percentage(100), Percentage(100));
            Container.Set_Style_Background_Opacity(Object_Type::Opacity::Transparent, 0);
            Container.Set_Style_Pad_All(0, 0);

            Icon.Create(Container);
            Icon.Set_Size(Percentage(100), Percentage(100));
            Icon.Set_Alignment(Object_Type::Alignment::Top_Middle);

            Label.Create(Container);
            Label.Set_Text_Format("Item %u", i);
            Label.Set_Alignment(Object_Type::Alignment::Bottom_Middle);
            Label.Set_Long_Mode(Object_Type::Long::Dot);

            Container.Clear_Pointer();
            Icon.Clear_Pointer();
            Label.Clear_Pointer();
        }
    }
}

Shell_Class::Drawer_Class::~Drawer_Class()
{
    List.Delete();
    Window.Delete();
}

void Shell_Class::Drawer_Class::Refresh_Drawer()
{
    // Delete all child of an object.
    for (uint8_t i = List.Get_Child; i--; i > 0)
    {
        List.Get_Child(i).Delete();
    }

    {
        using namespace Xila;
        Object_Type Container;
        Button_Type Icon;
        Label_Type Label;

        for (auto & Software_Handle : Software_Handle_Type::List)
        {
            Container.Create(List);
            Container.Set_Size(Percentage(100), Percentage(100));
            Container.Set_Style_Background_Opacity(Object_Type::Opacity::Transparent, 0);
            Container.Set_Style_Pad_All(0, 0);

            Icon.Create(Container);
            Icon.Set_Size(Percentage(100), Percentage(100));
            Icon.Set_Alignment(Object_Type::Alignment::Top_Middle);

            Label.Create(Container);
            Label.Set_Text(Software_Handle->Get_Name());
            Label.Set_Alignment(Object_Type::Alignment::Bottom_Middle);
            Label.Set_Long_Mode(Object_Type::Long::Dot);

            Container.Clear_Pointer();
            Icon.Clear_Pointer();
            Label.Clear_Pointer();
        }
    }
}

void Shell_Class::Drawer_Class::Execute_Drawer_Instruction(Xila_Class::Instruction_Type Instruction)
{
    switch (Instruction.Get_Argument())
    {
    case Instruction('R', 'e'):
        Refresh_Drawer();
        break;
    case Instruction('N', 'd'): // Nd : Next drawer items
        if ((Offset + 15) < (sizeof(Software_Management.Handle) / sizeof(Software_Management.Handle[1])))
        {
            if (Software_Management.Handle[Offset + 15] != NULL)
            {
                Offset += 15;
                Instance_Pointer->Send_Instruction('R', 'e');
            }
        }
        break;
    case Instruction('P', 'd'): // Pd : Previous drawer items
        if (Offset > 14)
        {
            Offset -= 15;
            Instance_Pointer->Send_Instruction('R', 'e');
        }
        else
        {
            Offset = 0;
        }
        break;
    case Instruction('d', '0'): // dx : Open software from drawer
        Open_From_Drawer(0);
        break;
    case Instruction('d', '1'): // dx : Open software from drawer
        Open_From_Drawer(1);
        break;
    case Instruction('d', '2'): // dx : Open software from drawer
        Open_From_Drawer(2);
        break;
    case Instruction('d', '3'): // dx : Open software from drawer
        Open_From_Drawer(3);
        break;
    case Instruction('d', '4'): // dx : Open software from drawer
        Open_From_Drawer(4);
        break;
    case Instruction('d', '5'): // dx : Open software from drawer
        Open_From_Drawer(5);
        break;
    case Instruction('d', '6'): // dx : Open software from drawer
        Open_From_Drawer(6);
        break;
    case Instruction('d', '7'): // dx : Open software from drawer
        Open_From_Drawer(7);
        break;
    case Instruction('d', '8'): // dx : Open software from drawer
        Open_From_Drawer(8);
        break;
    case Instruction('d', '9'): // dx : Open software from drawer
        Open_From_Drawer(9);
        break;
    case Instruction('d', 'A'): // dx : Open software from drawer
        Open_From_Drawer(10);
        break;
    case Instruction('d', 'B'): // dx : Open software from drawer
        Open_From_Drawer(11);
        break;
    case Instruction('d', 'C'): // dx : Open software from drawer
        Open_From_Drawer(12);
        break;
    case Instruction('d', 'D'): // dx : Open software from drawer
        Open_From_Drawer(13);
        break;
    case Instruction('d', 'E'): // dx : Open software from drawer
        Open_From_Drawer(14);
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

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
