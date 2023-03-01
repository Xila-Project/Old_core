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



void Theme_Class::Apply_Callback(lv_theme_t *Theme, lv_obj_t *LVGL_Object)
{
    static Object_Type Object;

    LV_UNUSED(Theme);

    Object.Clear_Pointer();
    Object.Set_Pointer(LVGL_Object);

    // - Apply theme's style

    // - - Object
    if (Object.Check_Type(&lv_obj_class))
    {
        Object.Set_Style_Radius(0, 0);
        Object.Set_Style_Border_Width(0, 0);
    }

    // - - Button
    else if (Object.Check_Type(&lv_btn_class))
    {
        Object.Add_Style(&Style_Button, 0);
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
        Object.Add_Style(&Style_Checkbox, Part_Type::Indicator | State_Type::Default);
        // Set background color of the indicator
        Object.Set_Style_Background_Color(Color_Type::White, Part_Type::Indicator | State_Type::Checked);
    }

    // - - Slider
    else if (Object.Check_Type(&lv_slider_class))
    {
        Object.Add_Style(&Style_Slider_Main, Part_Type::Main | State_Type::Default);
        Object.Add_Style(&Style_Slider_Indicator, Part_Type::Indicator | State_Type::Default);
        Object.Add_Style(&Style_Slider_Knob, Part_Type::Knob | State_Type::Default);
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
    
    lv_style_init(&Style_Button);
    lv_style_set_bg_color(&Style_Button, lv_palette_darken(LV_PALETTE_GREY, 3));
    lv_style_set_border_color(&Style_Button, lv_color_white());
    lv_style_set_border_width(&Style_Button, 1);
    lv_style_set_radius(&Style_Button, Button_Radius);
    lv_style_set_shadow_width(&Style_Button, 0);

    // Checkbox style
    lv_style_init(&Style_Checkbox);
    lv_style_set_border_color(&Style_Checkbox, lv_palette_darken(LV_PALETTE_GREY, 3));

    // Slider style

    // -- Main
    lv_style_init(&Style_Slider_Main);
    lv_style_set_bg_color(&Style_Slider_Main, lv_palette_darken(LV_PALETTE_GREY, 2));

    lv_style_set_border_color(&Style_Slider_Main, lv_color_white());
    lv_style_set_border_width(&Style_Slider_Main, 1);

    lv_style_set_radius(&Style_Slider_Main, Slider_Radius);

    // -- Indicator
    lv_style_init(&Style_Slider_Indicator);
    lv_style_set_bg_color(&Style_Slider_Indicator, lv_palette_darken(LV_PALETTE_GREY, 3));

    lv_style_set_radius(&Style_Slider_Indicator, Slider_Radius);

    lv_style_set_border_color(&Style_Slider_Indicator, lv_color_white());
    lv_style_set_border_width(&Style_Slider_Indicator, 1);
    lv_style_set_border_side(&Style_Slider_Indicator, LV_BORDER_SIDE_FULL);

    // -- Knob
    lv_style_init(&Style_Slider_Knob);
    lv_style_set_radius(&Style_Slider_Knob, Slider_Radius);
    lv_style_set_width(&Style_Slider_Knob, LV_PCT(100));
    lv_style_set_height(&Style_Slider_Knob, LV_PCT(100));

    lv_style_set_opa(&Style_Slider_Knob, LV_OPA_0); // Delete knob

    /*Initialize the new theme from the current theme*/
    lv_theme_t *Default_Theme = lv_disp_get_theme(NULL);
    LVGL_Theme = *Default_Theme; // Copy default material theme

    /*Set the parent theme and the style apply callback for the new theme*/
    lv_theme_set_parent(&LVGL_Theme, Default_Theme);
    lv_theme_set_apply_cb(&LVGL_Theme, Apply_Callback);

    /*Assign the new theme to the current display*/
    lv_disp_set_theme(NULL, &LVGL_Theme);
}
