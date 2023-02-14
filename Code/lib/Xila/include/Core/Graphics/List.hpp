///
/// @file List.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "Object.hpp"
#include "Label.hpp"
#include "Button.hpp"

namespace Xila_Namespace
{
    /// @brief List class.
    typedef class List_Class : public Object_Class
    {
    public:
        // - Methods

        void Create(Object_Class Parent_Object) override;

        Label_Class Add_Text(const char *Text);
        Button_Class Add_Button(const char *Icon, const char *Text);

        // - - Setters

        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

        // - - Getters

        const char *Get_Button_Text(Button_Class &Button);
    } List_Type;
}

#endif