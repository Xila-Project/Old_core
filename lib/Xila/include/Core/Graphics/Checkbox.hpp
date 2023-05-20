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

namespace Xila_Namespace
{

    namespace Graphics_Types
    {
        /// @brief Checkbox class.
        typedef class Checkbox_Class : public Object_Class
        {
        public:
            // - Types

            typedef enum Draw_Part_Enumeration
            {
                Box = LV_CHECKBOX_DRAW_PART_BOX,
            } Draw_Part_Type;

            // - Methods
            Checkbox_Class();
            Checkbox_Class(const Object_Class &Object_To_Copy);

            virtual void Create(Object_Class Parent_Object) override;
            // - - Setters.

            virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

            void Set_Text(const char *Text);
            void Set_Text_Static(const char *Text);

            // - - Getters.
            const char *Get_Text();

            // - Attributes
            static const Class_Type &Class;

        } Checkbox_Type;
    } // namespace Graphics_Types
}

#endif
