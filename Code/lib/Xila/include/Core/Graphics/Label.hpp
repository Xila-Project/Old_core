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
    namespace Graphics_Types
    {
        enum class Long_Type
        {
            Wrap = LV_LABEL_LONG_WRAP,
            Dot = LV_LABEL_LONG_DOT,
            Scroll = LV_LABEL_LONG_SCROLL,
            Scroll_Circular = LV_LABEL_LONG_SCROLL_CIRCULAR,
            Clip = LV_LABEL_LONG_CLIP
        };

        /// @brief Label class.
        typedef class Label_Class : public Object_Class
        {
        public:
            // - Methods

            // - - Constructors / destructors
            Label_Class();
            Label_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation
            virtual void Create(Object_Class Parent_Object) override;
            void Create(Object_Class Parent_Object, const String_Type &Text, Coordinate_Type Width = 0, Coordinate_Type Height = 0);

            void Insert_Text(uint32_t Position, const char *Text);
            void Cut_Text(uint32_t Position, uint32_t Length);
            bool Is_Char_Under_Position(Point_Type *Position);

            // - - Setters
            virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

            void Set_Text(const char *Text);
            void Set_Text_Format(const char *Format, ...);
            void Set_Text_Static(const char *Text);
            void Set_Long_Mode(Long_Type Long_Mode);
            void Set_Recolor(bool Recolor);
            void Set_Selection_Start(uint32_t Index);
            void Set_Selection_End(uint32_t Index);

            // - - Getters
            char *Get_Text();
            Long_Type Get_Long_Mode();
            bool Get_Recolor();
            void Get_Letter_Position(uint32_t Index, Point_Type *Position);
            uint32_t Get_Letter_On(Point_Type *Position_In);
            uint32_t Get_Selection_Start();
            uint32_t Get_Selection_End();

            // - - Attributes
            static const Graphics_Types::Class_Type &Class;

        } Label_Type;
    }
}

#endif