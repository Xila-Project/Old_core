///
 /// @file Line.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 12-07-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #include "Core/Graphics/Line.hpp"

#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace; 

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Line_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object)
    {
        Set_Pointer(lv_line_create(Parent_Object.Get_Pointer()));
    }
}


// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Line_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{ 
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_line_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Line_Class::Set_Points(const Point_Type* Points, uint16_t Number)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_line_set_points(Get_Pointer(), Points, Number);
}

void Line_Class::Set_Y_Inversion(bool Inversion)
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_line_set_y_invert(Get_Pointer(), Inversion);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //


bool Line_Class::Get_Y_Inversion()
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_line_get_y_invert(Get_Pointer());
}