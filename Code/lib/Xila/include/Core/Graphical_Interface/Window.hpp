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

#include "Object.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "Image.hpp"

class Window_Class : public Object_Class
{
public:

    void Create();
    void Create(Object_Class &Parent_Object);

    void Set_Title(const char *Title);

    bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

    Object_Class Get_Body();
    Object_Class Get_Header();

private:

    Object_Class Window;
    Object_Class Header;
    Object_Class Body;

    Label_Class Title_Label;
    Label_Class Clock_Label;

    Button_Class Network_Button;
    Image_Class Battery_Image;
    Button_Class Battery_Button;
    Image_Class Battery_Image;
    Button_Class Sound_Button;
    Image_Class Sound_Image;

    Button_Class Close_Button;
    Button_Class Minimize_Button;
};

Object_Type Class::Create()
{
    return lv_win_create(Xila_Class::Display_Class::Screen_Class::Get(), NULL);
}

inline void Class::Set_Title(Object_Type Object_Type, String Title)
{
    lv_win_set_title(Object_Type, Title.c_str());
}

#endif