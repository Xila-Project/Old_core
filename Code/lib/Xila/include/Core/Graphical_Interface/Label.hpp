///
/// @file Label.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 10-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED

#include "Object.hpp"

namespace Xila_Namespace
{
    /// @brief Label class.
    typedef class Label_Class : public Object_Class
    {
    public:
        // - Types

        /// @brief Label class.

        typedef lv_label_long_mode_t Long_Mode_Type;

        enum Long_Mode_Enumeration
        {
            Long_Wrap = LV_LABEL_LONG_WRAP,
            Long_Dot = LV_LABEL_LONG_DOT,
            Long_Scroll = LV_LABEL_LONG_SCROLL,
            Long_Scroll_Circular = LV_LABEL_LONG_SCROLL_CIRCULAR,
            Long_Clip = LV_LABEL_LONG_CLIP
        };
        // - Methods

        void Create(Object_Class Parent_Object);

        void Insert_Text(uint32_t Position, const char *Text);
        void Cut_Text(uint32_t Position, uint32_t Length);
        bool Is_Char_Under_Position(Point_Type *Position);

        // - - Setters
        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

        void Set_Text(const char *Text);
        void Set_Text_Format(const char *Format, ...);
        void Set_Text_Static(const char *Text);
        void Set_Long_Mode(Long_Mode_Type Long_Mode);
        void Set_Recolor(bool Recolor);
        void Set_Selection_Start(uint32_t Index);
        void Set_Selection_End(uint32_t Index);

        // - - Getters
        char *Get_Text();
        Long_Mode_Type Get_Long_Mode();
        bool Get_Recolor();
        void Get_Letter_Position(uint32_t Index, Point_Type *Position);
        uint32_t Get_Letter_On(Point_Type *Position_In);
        uint32_t Get_Selection_Start();
        uint32_t Get_Selection_End();
    } Label_Type;
}

#endif