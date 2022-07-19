///
/// @file Tabs.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 10-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Tabs_Hpp_Included
#define Tabs_Hpp_Included

#include "Object.hpp"
#include "Button.hpp"

class Tabs_Class : public Object_Class
{
public:
    // -- Types

    typedef lv_tabview_btns_pos_t Buttons_Position_Type;
    typedef lv_tabview_part_t Part_Type;

    enum
    {
        None = LV_TABVIEW_TAB_POS_NONE,
        Top = LV_ALIGN_TAB_POS_TOP,
        Bottom = LV_ALIGN_TAB_POS_BOTTOM,
        Left = LV_ALIGN_TAB_POS_LEFT,
        Right = LV_ALIGN_TAB_POS_RIGHT,
    };

    enum
    {
        Background = LV_TABVIEW_PART_BG,
        Virtual_Last = LV_TABVIEW_PART_VIRTUAL_LAST,
        Background_Scrollable = LV_TABVIEW_PART_BG_SCROLLABLE,
        Tab_Background = LV_TABVIEW_PART_TAB_BG,
        Tab_Button = LV_TABVIEW_PART_TAB_BTN,
        Part_Indicator = LV_TABVIEW_PART_INDICATOR,
        Real_Last = LV_TABVIEW_PART_REAL_LAST
    };

    // - Methods
    void Create(Object_Class &Parent_Object);

    void Add_Tab(const char* Name);
    void Rename_Tab(const char* Name);

    // - - Setters.
    bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

    void Set_Active_Tab(uint16_t Identifier, bool Animation);

    // - - Getters.
    uint16_t Get_Tab_Active();
    uint16_t Get_Tab_Count();

    Object_Class Get_Content();
    Button_Class Get_Tab_Buttons();

    uint16_t Get_Animation_Time();
    Buttons_Position_Type Get_Buttons_Position();
};

#endif