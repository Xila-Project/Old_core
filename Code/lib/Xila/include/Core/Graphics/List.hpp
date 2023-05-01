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
    namespace Graphics_Types
    { 
        /// @brief List class.
        typedef class List_Class : public Object_Class
        {
        public:
            // - Methods

            // - - Constructors / destructors
            List_Class();
            List_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation
            virtual void Create(Object_Class Parent_Object) override;

            Object_Type Add_Text(const char *Text);
            Object_Type Add_Button(const char *Icon, const char *Text);

            // - - Setters
            virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

            // - - Getters
            const char *Get_Button_Text(Button_Class &Button);

            // - Attributes
            static const Class_Type &Class;
        } List_Type;

    } // namespace Graphics_Types
}

#endif