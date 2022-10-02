///
/// @file Button_Matrix.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Button_Matrix_Hpp_Included
#define Button_Matrix_Hpp_Included

#include "Object.hpp"

class Button_Matrix_Class : public Object_Class
{
public:
    // -- Types

    typedef lv_btnmatrix_btn_draw_cb_t Button_Draw_Callback_Type;

    // -- Enumerations

    class Control
    {
    public:
        typedef lv_btnmatrix_ctrl_t Type;

        enum Enumeration
        {
            Hidden = LV_BTNMATRIX_CTRL_HIDDEN,
            No_Repeat = LV_BTNMATRIX_CTRL_NO_REPEAT,
            Disabled = LV_BTNMATRIX_CTRL_DISABLED,
            Checkable = LV_BTNMATRIX_CTRL_CHECKABLE,
            Checked = LV_BTNMATRIX_CTRL_CHECKED,
            Click_Trigger = LV_BTNMATRIX_CTRL_CLICK_TRIG,
            Popover = LV_BTNMATRIX_CTRL_POPOVER,
            Recolor = LV_BTNMATRIX_CTRL_RECOLOR,
            Custom_1 = LV_BTNMATRIX_CTRL_CUSTOM_1,
            Custom_2 = LV_BTNMATRIX_CTRL_CUSTOM_2
        };
    };

    class Draw_Part
    {
    public:
        typedef enum Enumeration
        {
            Button = LV_BTNMATRIX_DRAW_PART_BTN
        } Type;
    };

    // -- Methods

    // -- -- Constructor

    void Create(Object_Class Parent_Object);

    // -- -- Action methods
    void Clear_Button_Control(uint16_t Button_Identifier, Control::Type Control);
    void Clear_All_Buttons_Control(Control::Type Control);
    bool Has_Button_Control(uint16_t Button_Identifier, Control::Type Control);

    // - - Setters.

    bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

    void Set_Button_Width(uint16_t Button_Identifier, uint8_t Width);

    void Set_Map(const char **Map);
    void Set_Control_Map(Control::Type *Map);
    void Set_Selected_Button(uint16_t Button_Identifier);
    void Set_Button_Control(uint16_t Button_Identifier, Control::Type Control);
    void Set_Button_Control_All(Control::Type Control);

    void Set_One_Checked(bool Enabled);

    // -- -- Get attributes values.
    const char **Get_Map();
    uint16_t Get_Selected_Button();

    const char *Get_Button_Text(uint16_t Button_Identifier);
    bool Get_Popovers();
    bool Get_One_Checked();
};

#endif