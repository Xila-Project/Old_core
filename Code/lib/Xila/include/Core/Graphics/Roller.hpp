///
/// @file Roller.hpp
/// @author  ()
/// @brief
/// @version 0.1
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Roller_Hpp_Included
#define Roller_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
        /// @brief Roller class.
        typedef class Roller_Class : public Object_Class
        {
        public:
            // -- Types

            enum class Mode_Type
            {
                Normal = LV_ROLLER_MODE_NORMAL,
                Infinite = LV_ROLLER_MODE_INFINITE
            };

            // - Methods

            // - - Constructors / destructors
            Roller_Class();
            Roller_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation
            virtual void Create(Object_Class Parent_Object) override;

            // - - Setters
            virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

            void Set_Options(const char *Options, Mode_Type Mode);
            void Set_Selected(uint16_t Index, bool Animated);
            void Set_Visible_Row_Count(uint8_t Row_Count);

            // - - Getters
            uint16_t Get_Selected();
            String_Type &Get_Selected_String(String_Type &String);
            const char *Get_Options();
            uint16_t Get_Option_Count();

            // - Attributes
            static const Class_Type &Class;
        } Roller_Type;
    } // namespace Graphics_Types
} // namespace Xila_Namespace

#endif