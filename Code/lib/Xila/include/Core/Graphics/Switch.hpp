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
    public:
        // - Methods

        // - - Constructors / destructors
        Switch_Class(const Object_Class &Object_To_Copy);

        // - - Manipulation
        virtual void Create(Object_Class& Parent_Object) override;
        
        // - - Setters
        virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

        // - Attributes
        static const Graphics_Types::Class_Type& Class;

    } Switch_Type;
}

#endif