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
        // TODO : Make it protected.
        void Create();

        void Set_Title(const char *Title);

        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

        void Set_State(Graphics_Types::Window_State_Type State);        
        Graphics_Types::Window_State_Type Get_State();

        Object_Class Get_Body();
        Object_Class Get_Header();

        const Accounts_Class::User_Class* Get_Owner_User();


    protected:
        // - Methods
    
        void Set_Interface();
        void Set_Owner_User(const Accounts_Class::User_Class* Owner_User);

        static Window_Class Get_User_Parent_Window_Index(const Accounts_Class::User_Type* Owner_User);

        // - Attributes
        static std::vector<Window_Class> Parent_List;

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

}

#endif