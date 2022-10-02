///
/// @file Checkbox.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Checkbox_Hpp_Included
#define Checkbox_Hpp_Included

#include "Object.hpp"

class Checkbox_Class : public Object_Class
{
public:

    // - Types

    typedef enum Draw_Part_Enumeration
    {
        Box = LV_CHECKBOX_DRAW_PART_BOX,
    } Draw_Part_Type;

    // - Methods

    void Create(Object_Class Parent_Object);

    // - - Setters.

    bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

    void Set_Text(const char *Text);
    void Set_Text_Static(const char *Text);

    // - - Getters.
    const char *Get_Text();
};

#endif
