/// @file Personnal.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 06-05-2023
///
/// @copyright Copyright (c) 2023
///

#include "Software/Preferences/Preferences.hpp"

void Preferences_Class::Draw_Personal()
{
    using namespace Graphics_Types;

    Personal_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    Personal_Tab.Set_Style_Pad_All(0, 0);
    Personal_Tab.Clear_Flag(Flag_Type::Scroll_Elastic);
    Personal_Tab.Clear_Flag(Flag_Type::Scroll_Momentum);

    // - Grid layout

    Object_Type Grid;
    Grid.Create(Personal_Tab);
    Grid.Set_Size(Percentage(100), Percentage(100));
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    // - - Style section

    const uint8_t Style_Section_Row = 0;

    {
        // - - - Style title label

        {
            Label_Type Label;
            Label.Create(Grid, "Style");
            Label.Set_Style_Text_Font(&lv_font_montserrat_24, 0);
            Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Style_Section_Row, 1);
        }

        // - - - Color

        {
            Label_Type Label;
            Label.Create(Grid, "Dark mode :");
            Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 3, Grid_Alignment_Type::Center, Style_Section_Row + 1, 1);
        }

        Personal_Dark_Mode_Switch.Create(Grid);
        Personal_Dark_Mode_Switch.Set_Grid_Cell(Grid_Alignment_Type::Center, 3, 2, Grid_Alignment_Type::Center, Style_Section_Row + 1, 1);
        Personal_Dark_Mode_Switch.Add_Event(this, Event_Code_Type::Value_Changed);

        {
            Label_Type Label;
            Label.Create(Grid, "Color :");
            Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 2, Grid_Alignment_Type::Center, Style_Section_Row + 2, 1);
        }


        for (uint8_t i = 0; i < 7; i++)
        {
            Graphics_Types::Button_Type Button;
            Button.Create(Grid);
            Button.Set_Style_Background_Color(Personal_Primary_Colors[i], 0);
            Button.Set_Style_Radius(LV_RADIUS_CIRCLE, 0);
            Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, i + 2, 1, Grid_Alignment_Type::Stretch, Style_Section_Row + 2, 1);
            Button.Add_Event(this, Event_Code_Type::Clicked);
        }

    }

    Refresh_Personal();
}

void Preferences_Class::Execute_Personal_Instruction(const Instruction_Type &Instruction)
{
    using namespace Graphics_Types;

    if ((Instruction.Graphics.Get_Code() == Event_Code_Type::Value_Changed) && (Instruction.Graphics.Get_Target() == Personal_Dark_Mode_Switch))
        Graphics.Set_Theme_Dark_Mode(Personal_Dark_Mode_Switch.Has_State(State_Type::Checked));
    else if (Instruction.Graphics.Get_Code() ==  Event_Code_Type::Clicked)
    {
        for (uint8_t i = Personal_Tab.Get_Child(0).Get_Children_Count() - 1; i > 0; i--)
        {
            Object_Type Checkbox = Personal_Tab.Get_Child(0).Get_Child(i);

            if (Instruction.Graphics.Get_Target() == Checkbox)
            {
                for (uint8_t j = 0; j < 7; j++)
                {
                    if (Checkbox.Get_Style_Background_Color(Part_Type::Main) == Personal_Primary_Colors[j])
                    {
                        Graphics.Set_Theme_Primary_Color(Personal_Primary_Colors[j]);
                        Graphics.Set_Theme_Secondary_Color(Personal_Secondary_Colors[j]);
                        break;
                    }
                }
            }
        }
    }
}

void Preferences_Class::Refresh_Personal()
{
    if (Graphics.Get_Theme_Dark_Mode())
        Personal_Dark_Mode_Switch.Add_State(Graphics_Types::State_Type::Checked);
    else
        Personal_Dark_Mode_Switch.Clear_State(Graphics_Types::State_Type::Checked);


    /*
    switch (Keyboard.Layout)
    {
    case Keyboard.American:
        Display.Set_Text(F("LAYOUT_TXT"), F("American"));
        break;
    case Keyboard.German:
        Display.Set_Text(F("LAYOUT_TXT"), F("German"));
        break;
    case Keyboard.French:
        Display.Set_Text(F("LAYOUT_TXT"), F("French"));
        break;
    case Keyboard.Spanish:
        Display.Set_Text(F("LAYOUT_TXT"), F("Spanish"));
        break;
    case Keyboard.Italian:
        Display.Set_Text(F("LAYOUT_TXT"), F("Italian"));
        break;
    case Keyboard.English:
        Display.Set_Text(F("LAYOUT_TXT"), F("English"));
        break;
    default:
        break;
    }*/
}
