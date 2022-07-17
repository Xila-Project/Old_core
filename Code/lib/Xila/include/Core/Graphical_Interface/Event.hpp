///
/// @file Event.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 17-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Event_Hpp_Included
#define Event_Hpp_Included

#include "lvgl.h"

/// @brief Event class.
class Event_Class
{
public:

    typedef enum
    {
        All = LV_EVENT_ALL,
        // -- Interaction related events
        Pressed = LV_EVENT_PRESSED,
        Pressing = LV_EVENT_PRESSING,
        Press_Lost = LV_EVENT_PRESS_LOST,

        Short_Clicked = LV_EVENT_SHORT_CLICKED,
        Long_Pressed = LV_EVENT_LONG_PRESSED,
        Long_Pressed_Repeat = LV_EVENT_LONG_PRESSED_REPEAT,

        Clicked = LV_EVENT_CLICKED,
        Released = LV_EVENT_RELEASED,
        Scroll_Begin = LV_EVENT_SCROLL_BEGIN,
        Scroll_End = LV_EVENT_SCROLL_END,
        Scroll = LV_EVENT_SCROLL,
        Gesture = LV_EVENT_GESTURE,
        Key = LV_EVENT_KEY,
        Focused = LV_EVENT_FOCUSED,
        Defocused = LV_EVENT_DEFOCUSED,
        Leave = LV_EVENT_LEAVE,
        Hit_Test = LV_EVENT_HIT_TEST,
        // -- Drawing context
        Cover_Check = LV_EVENT_COVER_CHECK,

        Extra_Draw_Size = LV_EVENT_REFR_EXT_DRAW_SIZE,
        Draw_Main_Begin = LV_EVENT_DRAW_MAIN_BEGIN,
        Draw_Main = LV_EVENT_DRAW_MAIN,
        Draw_Main_End = LV_EVENT_DRAW_MAIN_END,

        Draw_Post_Begin = LV_EVENT_DRAW_POST_BEGIN,
        Draw_Post = LV_EVENT_DRAW_POST,
        Draw_Post_End = LV_EVENT_DRAW_POST_END,
        Draw_Part_Begin = LV_EVENT_DRAW_PART_BEGIN,
        Draw_Part_End = LV_EVENT_DRAW_PART_END,

        // -- Special events
        Value_Changed = LV_EVENT_VALUE_CHANGED,
        Insert = LV_EVENT_INSERT,
        Refresh = LV_EVENT_REFRESH,
        Ready = LV_EVENT_READY,
        Cancel = LV_EVENT_CANCEL,

        // -- State events
        Delete = LV_EVENT_DELETE,
        Child_Changed = LV_EVENT_CHILD_CHANGED,
        Child_Created = LV_EVENT_CHILD_CREATED,
        Child_Deleted = LV_EVENT_CHILD_DELETED,

        // -- Screen events
        Screen_Unload_Start = LV_EVENT_SCREEN_UNLOAD_START,
        Screen_Load_Start = LV_EVENT_SCREEN_LOAD_START,
        Screen_Loaded = LV_EVENT_SCREEN_LOADED,
        Screen_Unloaded = LV_EVENT_SCREEN_UNLOADED,

        // -- Appearance events
        Size_Changed = LV_EVENT_SIZE_CHANGED,
        Style_Changed = LV_EVENT_STYLE_CHANGED,
        Layout_Changed = LV_EVENT_LAYOUT_CHANGED,
        Get_Self_Size = LV_EVENT_GET_SELF_SIZE,

        Last_Event = _LV_EVENT_LAST
    } Event_Code_Type;
};

#endif
