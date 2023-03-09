///
/// @file Spinbox.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 23-02-2023
///
/// @copyright Copyright (c) 2023
///

#ifndef Spinbox_Hpp_Included
#define Spinbox_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    typedef class Spinbox_Class : public Object_Class
    {
    public:
        // - Methods
        
        // - - Constructors / destructors
        Spinbox_Class();
        Spinbox_Class(const Object_Class &Object_To_Copy);

        // - - Manipulation
        virtual void Create(Object_Class Parent_Object) override;

        // - - Manipulation.
        void Step_Next();
        void Step_Previous();
        void Increment();
        void Decrement();

        // - - Getters.
        bool Get_Rollover();
        int32_t Get_Value();
        int32_t Get_Step();

        // - - Setters.
        virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;
        void Set_Value(int32_t Value);
        void Set_Rollover(bool Rollover);
        void Set_Digit_Format(uint8_t Digit_Count, uint8_t DecimalSeparator_Position_Point_Position);
        void Set_Step(uint32_t Step);
        void Set_Range(int32_t Minimum_Value, int32_t Maximum_Value);
        void Set_Cursor_Position(uint8_t Cursor_Position);
        void Set_Digit_Step_Direction(Direction_Type Direction);

        // - Attributes
        static const Graphics_Types::Class_Type& Class;
    } Spinbox_Type;
}

#endif