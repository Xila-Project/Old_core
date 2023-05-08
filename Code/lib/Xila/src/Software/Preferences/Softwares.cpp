 /// @file Softwares.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 06-05-2023
 /// 
 /// @copyright Copyright (c) 2023

#include "Software/Preferences/Preferences.hpp"

void Preferences_Class::Refresh_Softwares()
{
    char Software_Name[Softwares.Get_Handle_Count() * (Default_Software_Name_Length + 1) + 1];
    memset(Software_Name, '\0', sizeof(Software_Name));
    Static_String_Type<Default_Software_Name_Length> Software_Name_String;

    uint8_t Handle_Count = Softwares.Get_Handle_Count();

    for (uint8_t i = 0; i < Handle_Count; i++)
    {
        Softwares.Get_Handle(i)->Get_Name(Software_Name_String);
        strlcat(Software_Name, Software_Name_String, sizeof(Software_Name));
        if (i < Softwares.Get_Handle_Count() - 1)
        {
            strlcat(Software_Name, "\n", sizeof(Software_Name));
        }
    }

    Softwares_Roller.Set_Options(Software_Name, Graphics_Types::Roller_Mode_Type::Normal);
}

void Preferences_Class::Execute_Softwares_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Graphics.Get_Target() == Softwares_Delete_Button)
    {
        // TODO
    }
}

void Preferences_Class::Draw_Softwares()
{
    using namespace Graphics_Types;

    Softwares_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    Softwares_Tab.Set_Style_Pad_All(0, 0);
    Softwares_Tab.Clear_Flag(Flag_Type::Scroll_Elastic);
    Softwares_Tab.Clear_Flag(Flag_Type::Scroll_Momentum);

    // - Grid layout

    Object_Type Grid;
    Grid.Create(Softwares_Tab);
    Grid.Set_Size(Percentage(100), Percentage(100));
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    // - - Software section

    const uint8_t Software_Section_Row = 0;

    {
        // - - - Software title label
        {
            Label_Type Label;
            Label.Create(Grid, "Softwares");
            Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Software_Section_Row, 1);
        }
        // - - - Softwares roller

        Softwares_Roller.Create(Grid);
        Softwares_Roller.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Center, Software_Section_Row + 1, 1);

        // - - - Delete button

        Softwares_Delete_Button.Create(Grid, "Delete", 0, 0, this);
        Softwares_Delete_Button.Set_Grid_Cell(Grid_Alignment_Type::Center, 6, 2, Grid_Alignment_Type::Center, Software_Section_Row + 1, 1);
    }

    Refresh_Softwares();
}