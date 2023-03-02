///
/// @file Theme.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 24-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Theme.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// TODO : Integrate directly into object creation (useless to use a callback)

void Theme_Class::Apply_Callback(lv_theme_t *Theme, lv_obj_t *LVGL_Object)
{
    static Object_Type Object;

    LV_UNUSED(Theme);

    Object.Clear_Pointer();
    Object.Set_Pointer(LVGL_Object);

    // - Apply theme's style

    // - - Object
    if (Object.Get (&lv_obj_class))
    {
        Object.Set_Style_Radius(0, 0);
        Object.Set_Style_Border_Width(0, 0);
    }

    // - - Button
    else if (Object.Check_Type(&lv_btn_class))
    {
        Object.Add_Style(Style_Button, 0);
    }

    // - - Label
    else if (Object.Check_Type(&lv_label_class))
    {
        Object.Set_Style_Text_Color(Color_Type::White, 0);
    }

    // - - Checkbox
    else if (Object.Check_Type(&lv_checkbox_class))
    {
        // Set label color
        Object.Set_Style_Text_Color(Color_Type::White, Part_Type::Main | State_Type::Default);
        // Add style for the indicator
        Object.Add_Style(Style_Checkbox, Part_Type::Indicator | State_Type::Default);
        // Set background color of the indicator
        Object.Set_Style_Background_Color(Color_Type::White, Part_Type::Indicator | State_Type::Checked);
    }

    // - - Slider
    else if (Object.Check_Type(&lv_slider_class))
    {
        Object.Add_Style(Style_Slider_Main, Part_Type::Main | State_Type::Default);
        Object.Add_Style(Style_Slider_Indicator, Part_Type::Indicator | State_Type::Default);
        Object.Add_Style(Style_Slider_Knob, Part_Type::Knob | State_Type::Default);
    }

    // - - Textarea
    else if (Object.Check_Type(&lv_textarea_class))
    {
        Object.Set_Style_Background_Color(Color_Type::White, Part_Type::Main | State_Type::Default);
        Object.Set_Style_Border_Side(Border_Side_Type::Bottom, Part_Type::Main | State_Type::Default);
        Object.Set_Style_Border_Color(Color_Type::White, Part_Type::Main | State_Type::Default);
        Object.Set_Style_Border_Color(Color_Type::White, Part_Type::Main | State_Type::Disabled);
        Object.Set_Style_Border_Color(Color_Type::White, Part_Type::Main | State_Type::Edited);
        Object.Set_Style_Border_Color(Color_Type::White, Part_Type::Main | State_Type::Focused);
        Object.Set_Style_Border_Color(Color_Type::White, Part_Type::Cursor | State_Type::Focused);
    
        // TODO : Add object event to add keyboard
        Object.Add_Event(&Graphics, Event_Code_Type::Focused);
        Object.Add_Event(&Graphics, Event_Code_Type::Defocused);
    }
}

void Theme_Class::Initialize()
{
    /*Initialize the styles*/
    // Button style

    Style_Button.Initialize();
    Style_Button.Set_Background_Color(Color_Type::White);
    Style_Button.Set_Border_Color(Color_Type::White);
    Style_Button.Set_Border_Width(1);
    Style_Button.Set_Radius(Button_Radius);
    Style_Button.Set_Shadow_Width(0);

    // Checkbox style
    Style_Button.Initialize();
    Style_Button.Set_Background_Color(Color_Type::Grey[2]);

    // Slider style

    // -- Main

    Style_Slider_Main.Initialize();
    Style_Slider_Main.Set_Background_Color(Color_Type::Grey[2]);
    Style_Slider_Main.Set_Border_Color(Color_Type::White);
    Style_Slider_Main.Set_Border_Width(1);
    Style_Slider_Main.Set_Radius(Slider_Radius);

    // -- Indicator
    Style_Slider_Indicator.Initialize();
    Style_Slider_Indicator.Set_Background_Color(Color_Type::Grey[3]);
    Style_Slider_Indicator.Set_Radius(Slider_Radius);
    Style_Slider_Indicator.Set_Border_Color(Color_Type::White);
    Style_Slider_Indicator.Set_Border_Width(1);
    Style_Slider_Indicator.Set_Border_Side(Border_Side_Type::Full);

    // -- Knob
    Style_Slider_Knob.Initialize();
    Style_Slider_Knob.Set_Background_Color(Color_Type::White);
    Style_Slider_Knob.Set_Radius(Slider_Radius);
    Style_Slider_Knob.Set_Width(Percentage(100));
    Style_Slider_Knob.Set_Height(Percentage(100));
    Style_Slider_Knob.Set_Opacity(Opacity_Type::Transparent);

    /*Initialize the new theme from the current theme*/

    lv_theme_t *Default_Theme = lv_disp_get_theme(NULL);
    LVGL_Theme = *Default_Theme; // Copy default material theme

    /*Set the parent theme and the style apply callback for the new theme*/
    lv_theme_set_parent(&LVGL_Theme, Default_Theme);
    lv_theme_set_apply_cb(&LVGL_Theme, Apply_Callback);

    /*Assign the new theme to the current display*/
    lv_disp_set_theme(NULL, &LVGL_Theme);
}
