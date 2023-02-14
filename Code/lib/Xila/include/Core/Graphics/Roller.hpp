///
/// @file Roller.hpp
/// @author  ()
/// @brief
/// @version 0.1
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Roller_Hpp_Included
#define Roller_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    /// @brief Roller class.
    typedef class Roller_Class : public Object_Class
    {
    public:
        // -- Types

        enum class Mode_Type
        {
            Normal = LV_ROLLER_MODE_NORMAL,
            Infinite = LV_ROLLER_MODE_INFINITE
        };

        // -- Methods

        void Create(Object_Class Parent_Object) override;

        // -- Setters

        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

        void Set_Options(const char *Options, Mode_Type Mode);
        void Set_Selected(uint16_t Index, bool Animated);
        void Set_Visible_Row_Count(uint8_t Row_Count);

        // -- Getters

        uint16_t Get_Selected();
        void Get_Selected_String(char *Buffer, size_t Size);
        const char *Get_Options();
        uint16_t Get_Option_Count();
    } Roller_Type;
}

#endif