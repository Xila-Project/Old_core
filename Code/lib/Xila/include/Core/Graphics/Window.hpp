///
/// @file Window.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 06-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Window_Hpp_Included
#define Window_Hpp_Included

#include <list>

#include "Object.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "Image.hpp"

#include "Core/Software/Software.hpp"
#include "Core/Account/Accounts.hpp"


namespace Xila_Namespace
{

    namespace Graphics_Types
    {
        enum class Window_State_Type
        {
            Minimized,
            Windowed,
            Maximized,
            Full_screen
        };

        typedef class Window_Class : public Object_Class
        {
        public:
            // - Methods
            // - - Constructors / destructors

            /// @brief Default constructor.
            Window_Class();

            /// @brief Copy constructor to allow conversion from object.
            Window_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation

            /// @brief Create a new window with a parent object.
            virtual void Create(Object_Class Parent_Object) override;

            /// @brief Create a new parent window for software.
            virtual void Create(const Software_Type *Owner_Module);

            // - - Setters

            /// @brief Set the title of the window.
            /// @param Title Title of the window.
            void Set_Title(const char *Title);

            /// @brief Set the pointer of the object.
            /// @param LVGL_Object_Pointer
            /// @return 
            virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

            /// @brief Set the state of the window.
            /// @param State State of the window.
            void Set_State(Window_State_Type State);

            // - - Getters

            /// @brief Get the state of the window.
            /// @return State of the window.
            Window_State_Type Get_State();

            /// @brief Get the body of the window.
            /// @return Body of the window.
            Object_Class Get_Body();

            /// @brief Get the header of the window.
            /// @return Header of the window.
            Object_Class Get_Header();

            /// @brief Get the title label of the window.
            /// @return Title label of the window.
            const Software_Type *Get_Owner_Software() const;

            // - Attributes

            /// @brief Custom LVGL class for Window (almost identical to object class).
            static const Graphics_Types::Class_Type Class;
        protected:
            // - Methods
            // - - Setters
            void Set_Interface();

            // - Attributes
            const Software_Type *Owner_Software;

            Object_Class Header;
            Object_Class Body;

            Label_Class Title_Label;

            Button_Class Close_Button;
            Button_Class Minimize_Button;

        } Window_Type;

        typedef class Parent_Window_Class : public Window_Class
        {
        public:
            // - Methods
            Parent_Window_Class();
            Parent_Window_Class(const Object_Type& Object_To_Copy);

            virtual void Create(const Software_Type *Owner_Module) override;

            static Parent_Window_Class Get_User_Parent_Window(const Accounts_Types::User_Type* User); 

            // - Attributes

            /// @brief Custom LVGL class for Parent window (almost identical to object class).
            static const Graphics_Types::Class_Type Class;
        } Parent_Window_Type;      
    };
}

#endif