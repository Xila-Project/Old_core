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

#include <vector>

#include "Object.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "Image.hpp"

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

    };

    typedef class Window_Class : public Object_Class
    {
    public:
        // - Methods

        virtual void Create(Object_Class Parent_Object) override;
        void Create(Object_Class Parent_Object, Module_Type* Owner_Module);
        void Create(Module_Type* Owner_Module);

        void Set_Title(const char *Title);

        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

        void Set_State(Graphics_Types::Window_State_Type State);
        Graphics_Types::Window_State_Type Get_State();

        Object_Class Get_Body();
        Object_Class Get_Header();

    protected:
        // - Methods

        void Set_Interface();

        Object_Class Header;
        Object_Class Body;

        Label_Class Title_Label;
        Label_Class Clock_Label;

        Button_Class Network_Button;
        Image_Class Network_Image;
        Button_Class Battery_Button;
        Image_Class Battery_Image;
        Button_Class Sound_Button;
        Image_Class Sound_Image;

        Button_Class Close_Button;
        Button_Class Minimize_Button;

    } Window_Type;

    typedef class Parent_Window_Class : public Window_Class
    {
    public:
        // - Methods


        static Window_Class Get_User_Parent_Window_Index(const Accounts_Types::User_Type *Owner_User);

    private:
        // - Attributes
        Accounts_Types::User_Type* Owner_User;
        Module_Type* Owner_Module;
        static std::vector<Window_Class> Parent_List;

    } Parent_Window_Type;

}

#endif