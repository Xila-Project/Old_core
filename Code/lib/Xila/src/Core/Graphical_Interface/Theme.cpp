///
/// @file Theme.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 24-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Theme.hpp"

using namespace Xila_Namespace;

void Theme_Class::Apply_Callback(lv_theme_t *Theme, lv_obj_t *Object)
{
    LV_UNUSED(Theme);

    if (lv_obj_check_type(Object, &lv_obj_class))
    {
        lv_obj_set_style_radius(Object, 0, 0);
        lv_obj_set_style_border_width(Object, 0, 0);
    }

    if (lv_obj_check_type(Object, &lv_btn_class))
    {
        lv_obj_add_style(Object, &Style_Button, 0);
    }

    else if (lv_obj_check_type(Object, &lv_label_class))
    {
        lv_obj_set_style_text_color(Object, lv_color_white(), 0);
    }

    else if (lv_obj_check_type(Object, &lv_checkbox_class))
    {
        // Set label color
        lv_obj_set_style_text_color(Object, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
        // Add style for the indicator
        lv_obj_add_style(Object, &Style_Checkbox, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        // Set background color of the indicator
        lv_obj_set_style_bg_color(Object, lv_palette_darken(LV_PALETTE_GREY, 3), LV_PART_INDICATOR | LV_STATE_CHECKED);
    }

    else if (lv_obj_check_type(Object, &lv_slider_class))
    {
        lv_obj_add_style(Object, &Style_Slider_Main, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_style(Object, &Style_Slider_Indicator, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_add_style(Object, &Style_Slider_Knob, LV_PART_KNOB | LV_STATE_DEFAULT);
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
