///
/// @file Color_Dialog.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 13-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Graphics/Dialog.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

void Color_Dialog_Class::Create(Object_Class Parent_Object)
{
    if (!Parent_Object)
    {
        return;
    }

    this->Set_Pointer(lv_obj_create(Parent_Object));
    this->Set_Interface();
    this->Set_Size(Percentage(75), Percentage(75));

    Color_Wheel.Create(this->Get_Body());
    Color_Wheel.Set_Size(Percentage(100), Percentage(100));
}

Color_Type Color_Dialog_Class::Get_Color()
{
    return Color_Wheel.Get_Color();
}


void Color_Dialog_Class::Set_Color(Color_Type Color)
{
    Color_Wheel.Set_Color(Color);
}





