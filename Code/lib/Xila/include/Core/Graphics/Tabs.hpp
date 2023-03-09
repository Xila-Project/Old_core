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

namespace Xila_Namespace
{
    typedef class Tabs_Class : public Object_Class
    {
    public:
        // - Methods

        // - - Constructors / destructors
        Tabs_Class(const Object_Class &Object_To_Copy);

        // - - Manipulation
        virtual void Create(Object_Class& Parent_Object) override;
        virtual void Create(Object_Class& Parent_Object, Direction_Type Direction, Coordinate_Type Size);

        Object_Class Add_Tab(const String_Type& Name);
        void Rename_Tab(uint32_t Index, const String_Type &New_name);

        // - - Setters.
        virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

        void Set_Active_Tab(uint32_t Identifier, bool Animation);

        // - - Getters.
        uint16_t Get_Tab_Active();
        uint16_t Get_Tab_Count();

        Object_Class Get_Content();
        Button_Class Get_Tab_Buttons();

        uint16_t Get_Animation_Time();

        // - Attributes
        static const Graphics_Types::Class_Type& Class;
    } Tabs_Type;
}

#endif