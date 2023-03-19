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

namespace Xila_Namespace
{
    // - Forward declaration
    typedef class Module_Class Module_Type;

    /// @brief Button class.
    typedef class Button_Class : public Object_Class
    {
    public:
        // - Methods

        // - - Constructors / destructors

        /// @brief Default constructor.
        Button_Class();

        /// @brief Copy constructor to allow conversion from object.
        Button_Class(const Object_Class &Object_To_Copy);

        // - - Management

        /// @brief Create a new button.
        /// @param Parent Parent object of the new button.
        virtual void Create(Object_Class Parent_Object) override;

        /// @brief Button create shortcut method that allow in one line to create a button with a label, defined size and event.
        /// @param Parent_Object
        /// @param Label_Text
        /// @param Width
        /// @param Height
        /// @param Module
        /// @param Event_Code
        void Create(Object_Class Parent_Object, const String_Type &Label_Text, Coordinate_Type Width = 0, Coordinate_Type Height = 0, Module_Type *Module = NULL, Graphics_Types::Event_Code_Type Event_Code = Graphics_Types::Event_Code_Type::Clicked);

        // - - Setters

        /// @brief Set the pointer of the object.
        /// @param LVGL_Object_Pointer
        /// @return 'true' if the pointer is valid, 'false' otherwise.
        virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

        // - - Attributes

        /// @brief Button class.
        static const Graphics_Types::Class_Type &Class;
    } Button_Type;
}

#endif