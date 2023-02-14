///
/// @file Switch.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 14-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Switch_Hpp_Included
#define Switch_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    typedef class Switch_Class : public Object_Class
    {
        // - Methods

        void Create(Object_Class Parent_Object) override;

        // - Setters
        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

    } Switch_Type;
}

#endif