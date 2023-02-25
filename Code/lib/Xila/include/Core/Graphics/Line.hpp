///
/// @file Line.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 10-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

#include "Object.hpp"

namespace Xila_Namespace
{
    /// @brief Line class.
    typedef class Line_Class : public Object_Class
    {
    public:
        // - Methods

        void Create(Object_Class Parent_Object) override; 

        // - - Setters
        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

        void Set_Points(const Point_Type *Points, uint16_t Number);
        void Set_Y_Inversion(bool Inversion);

        // - - Getters
        bool Get_Y_Inversion();
    } Line_Type;
}

#endif