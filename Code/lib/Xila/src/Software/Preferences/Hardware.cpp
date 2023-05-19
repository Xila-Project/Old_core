/// @file Hardware.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 06-05-2023
///
/// @copyright Copyright (c) 2023

#include "Software/Preferences/Preferences.hpp"

void Preferences_Class::Refresh_Hardware()
{
    Hardware_Display_Brightness_Slider.Set_Value(Display.Get_Brightness(), false);
    Hardware_Sound_Volume_Slider.Set_Value(Sound.Get_Volume(), false);
    Hardware_Battery_Level_Label.Set_Text(Power.Get_Charge_Level() + " %");

    switch (Drive.Get_Type())
    {
    case Drive_Types::Drive_Type_Type::None:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : None - Size : %u", Drive.Get_Size());
        break;
    case Drive_Types::Drive_Type_Type::MMC:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : MMC - Size : %u", Drive.Get_Size());
        break;
    case Drive_Types::Drive_Type_Type::SD_SC:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : SD SC - Size : %u", Drive.Get_Size());
        break;
    case Drive_Types::Drive_Type_Type::SD_HC:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : SD HC - Size : %u", Drive.Get_Size());
        break;
    default:
        Hardware_Drive_Informations_Label.Set_Text_Format("Type : Unknown - Size : %u", Drive.Get_Size());
        break;
    }

    if ((Display.Get_Standby_Time() <= 30) && (Display.Get_Standby_Time() > 0))
        Hardware_Energy_Standby_Roller.Set_Selected(0, false);
    else if (Display.Get_Standby_Time() <= (1 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(1, false);
    else if (Display.Get_Standby_Time() <= (2 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(2, false);
    else if (Display.Get_Standby_Time() <= (3 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(3, false);
    else if (Display.Get_Standby_Time() <= (4 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(4, false);
    else if (Display.Get_Standby_Time() <= (5 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(5, false);
    else if (Display.Get_Standby_Time() <= (10 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(6, false);
    else if (Display.Get_Standby_Time() <= (20 * 60))
        Hardware_Energy_Standby_Roller.Set_Selected(7, false);
    else
        Hardware_Energy_Standby_Roller.Set_Selected(8, false);
}

void Preferences_Class::Execute_Hardware_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Graphics.Get_Target() == Hardware_Display_Brightness_Slider)
    {
        Display.Set_Brightness(Hardware_Display_Brightness_Slider.Get_Value());
    }
    else if (Instruction.Graphics.Get_Target() == Hardware_Display_Calibrate_Button)
    {
        Display.Calibrate();
    }
    else if (Instruction.Graphics.Get_Target() == Hardware_Sound_Volume_Slider)
    {
        Sound.Set_Volume(Hardware_Sound_Volume_Slider.Get_Value());
    }
    else if (Instruction.Graphics.Get_Target() == Hardware_Energy_Apply_Button)
    {
        switch (Hardware_Energy_Standby_Roller.Get_Selected())
        {
        case 0:
            Display.Set_Standby_Time(30);
            break;
        case 1:
            Display.Set_Standby_Time(1 * 60);
            break;
        case 2:
            Display.Set_Standby_Time(2 * 60);
            break;
        case 3:
            Display.Set_Standby_Time(3 * 60);
            break;
        case 4:
            Display.Set_Standby_Time(4 * 60);
            break;
        case 5:
            Display.Set_Standby_Time(5 * 60);
            break;
        case 6:
            Display.Set_Standby_Time(10 * 60);
            break;
        case 7:
            Display.Set_Standby_Time(20 * 60);
            break;
        default:
            Display.Set_Standby_Time(0);
            break;
        }
    }
}

void Preferences_Class::Draw_Hardware()
{
    using namespace Graphics_Types;

    Hardware_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    Hardware_Tab.Set_Style_Pad_All(0, 0);
    Hardware_Tab.Clear_Flag(Flag_Type::Scroll_Elastic);
    Hardware_Tab.Clear_Flag(Flag_Type::Scroll_Momentum);

    // - Grid layout
    Object_Type Grid;
    Grid.Create(Hardware_Tab);
    Grid.Set_Size(Percentage(100), Percentage(100));
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    const uint8_t Display_Section_Row = 0;

    {
        Label_Type Label;
        Label.Create(Grid, "Display");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Display_Section_Row, 1);
        Label.Clear_Pointer();

        Label.Create(Grid, "Brightness :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 2, Grid_Alignment_Type::Center, Display_Section_Row + 1, 1);
        Label.Clear_Pointer();

        Hardware_Display_Brightness_Slider.Create(Grid);
        Hardware_Display_Brightness_Slider.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 2, 4, Grid_Alignment_Type::Center, Display_Section_Row + 1, 1);
        Hardware_Display_Brightness_Slider.Set_Range(10, 100);
        Hardware_Display_Brightness_Slider.Add_Event(this, Event_Code_Type::Value_Changed);

        Hardware_Display_Calibrate_Button.Create(Grid, "Calibrate", 0, 0, this);
        Hardware_Display_Calibrate_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Display_Section_Row + 1, 1);
    }

    const uint8_t Sound_Section_Row = Display_Section_Row + 2;

    {
        Label_Type Label;
        Label.Create(Grid, "Sound");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Sound_Section_Row, 1);
        Label.Clear_Pointer();

        Label.Create(Grid, "Volume :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 2, Grid_Alignment_Type::Center, Sound_Section_Row + 1, 1);
        Label.Clear_Pointer();

        Hardware_Sound_Volume_Slider.Create(Grid);
        Hardware_Sound_Volume_Slider.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 2, 6, Grid_Alignment_Type::Center, Sound_Section_Row + 1, 1);
        Hardware_Sound_Volume_Slider.Set_Range(0, 100);
    }

    const uint8_t Battery_Section_Row = Sound_Section_Row + 2;

    {
        Label_Type Label;
        Label.Create(Grid, "Battery");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Battery_Section_Row, 1);
        Label.Clear_Pointer();

        Label.Create(Grid, "Level :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 2, Grid_Alignment_Type::Center, Battery_Section_Row + 1, 1);
        Label.Clear_Pointer();

        Hardware_Battery_Level_Label.Create(Grid);
        Hardware_Battery_Level_Label.Set_Grid_Cell(Grid_Alignment_Type::Start, 2, 6, Grid_Alignment_Type::Center, Battery_Section_Row + 1, 1);
    }

    const uint8_t Drive_Section_Row = Battery_Section_Row + 2;

    {
        Label_Type Label;
        Label.Create(Grid, "Drive");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Drive_Section_Row, 1);
        Label.Clear_Pointer();

        Hardware_Drive_Informations_Label.Create(Grid);
        Hardware_Drive_Informations_Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Drive_Section_Row + 1, 1);
    }

    const uint8_t Energy_Section_Row = Drive_Section_Row + 2;

    {
        Label_Type Label;
        Label.Create(Grid, "Energy");
        Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Energy_Section_Row, 1);
        Label.Clear_Pointer();

        Hardware_Energy_Apply_Button.Create(Grid, "Apply", 0, 0, this);
        Hardware_Energy_Apply_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Energy_Section_Row, 1);

        // - - - Standby label

        Label.Create(Grid, "Standby :");
        Label.Set_Grid_Cell(Grid_Alignment_Type::End, 0, 2, Grid_Alignment_Type::Center, Energy_Section_Row + 1, 2);
        Label.Clear_Pointer();

        // - - - Standby roller

        Hardware_Energy_Standby_Roller.Create(Grid);
        Hardware_Energy_Standby_Roller.Set_Grid_Cell(Grid_Alignment_Type::Center, 2, 4, Grid_Alignment_Type::Center, Energy_Section_Row + 1, 2);
        Hardware_Energy_Standby_Roller.Set_Options("30 seconds\n1 minute\n2 minutes\n3 mintes\n4 minutes\n5 minutes\n10 minutes\n20 minutes\nNever", Roller_Mode_Type::Normal);
    }
}