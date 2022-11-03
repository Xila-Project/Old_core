///
 /// @file Button.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 08-07-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

#ifndef Button_Hpp_Included
#define Button_Hpp_Included

#include "Object.hpp"

/// @brief Button class.
class Button_Class : public Object_Class
{
public:

    // - Methods

    // - - Management

    void Create(Object_Class Parent_Object);

    // - - Setters


    bool Set_Pointer(lv_obj_t* LVGL_Object_Pointer);
};

#endif