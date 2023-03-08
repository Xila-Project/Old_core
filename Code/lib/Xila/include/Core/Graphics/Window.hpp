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
            virtual ~Window_Class();
            virtual void Create(Object_Class Parent_Object) override;
            virtual void Create(const Software_Type *Owner_Module);

            // - - Setters
            void Set_Title(const char *Title);
            bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;
            void Set_State(Window_State_Type State);
            Window_State_Type Get_State();

            // - - Getters
            Object_Class Get_Body();
            Object_Class Get_Header();

            virtual const Class_Type* Get_Class() const override;
            const Software_Type *Get_Owner_Software() const;

            // - - Operators

            Window_Class& operator=(const Object_Class& Object);

            // - Attributes
            static const Class_Type Class;
        protected:
            // - Methods

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
            ~Parent_Window_Class();

            void Create(const Software_Type *Owner_Module) override;
            void Delete();

            virtual const Class_Type* Get_Class() const override;

            static Parent_Window_Class Get_User_Parent_Window(const Accounts_Types::User_Type* User); 

            // - Attributes
            static const Class_Type Class;
        private:
            // - Attributes
            static std::list <Parent_Window_Class*> List;

        } Parent_Window_Type;

      
    };

}

#endif