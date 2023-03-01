///
/// @file Theme.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 24-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Theme_Hpp_Included
#define Theme_Hpp_Included

#define Button_Radius 4
#define Slider_Radius 4

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
        typedef class Theme_Class
        {
        public:
            void Initialize();

            static void Apply_Callback(lv_theme_t *Theme, lv_obj_t *Object);

            static Style_Type
                Style_Button,
                Style_Window,
                Style_Checkbox,
                Style_Slider_Main,
                Style_Slider_Indicator,
                Style_Slider_Knob;

        private:
            static lv_theme_t LVGL_Theme;
            
        } Theme_Type;
    };
}

#endif