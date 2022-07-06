///
 /// @file Animation.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 04-07-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #ifndef Animation_Hpp_Included
 #define Animation_Hpp_Included

#include "lvgl.h"

class Animation_Class
{
public:

    typedef lv_anim_t LVGL_Animation_Type;

    Animation_Class();
    ~Animation_Class();

    
    const LVGL_Animation_Type* Get_Pointer();
    void Set_Pointer(LVGL_Animation_Type*);

private:


   LVGL_Animation_Type* LVGL_Animation_Pointer;


};

Animation_Class::Animation_Class() : LVGL_Animation_Pointer(NULL)
{

}


Animation_Class::~Animation_Class()
{
}



 #endif