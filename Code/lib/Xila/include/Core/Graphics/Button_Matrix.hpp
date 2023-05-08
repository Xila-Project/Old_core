///
/// @file Button_Matrix.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Button_Matrix_Hpp_Included
#define Button_Matrix_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
        // - Base types
        using Button_Matrix_Draw_Callback_Type = lv_btnmatrix_btn_draw_cb_t;
        
        enum class Button_Matrix_Control_Type : lv_btnmatrix_ctrl_t
        {
            Hidden = LV_BTNMATRIX_CTRL_HIDDEN,
            No_Repeat = LV_BTNMATRIX_CTRL_NO_REPEAT,
            Disabled = LV_BTNMATRIX_CTRL_DISABLED,
            Checkable = LV_BTNMATRIX_CTRL_CHECKABLE,
            Checked = LV_BTNMATRIX_CTRL_CHECKED,
            Click_Trigger = LV_BTNMATRIX_CTRL_CLICK_TRIG,
            Popover = LV_BTNMATRIX_CTRL_POPOVER,
            Recolor = LV_BTNMATRIX_CTRL_RECOLOR,
            Custom_1 = LV_BTNMATRIX_CTRL_CUSTOM_1,
            Custom_2 = LV_BTNMATRIX_CTRL_CUSTOM_2
        };


        /// @brief Button matrix class.
        typedef class Button_Matrix_Class : public Object_Class
        {
        public:
            // - Methods

            // - - Constructor / destructor

            /// @brief Default constructor.
            Button_Matrix_Class();

            /// @brief Copy constructor.
            Button_Matrix_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation

            /// @brief Create a new button matrix object.
            /// @param Parent_Object Parent object of the new button matrix.
            virtual void Create(Object_Class Parent_Object) override;

            /// @brief
            void Clear_Button_Control(uint16_t Button_Identifier, Button_Matrix_Control_Type Control);
            void Clear_All_Buttons_Control(Button_Matrix_Control_Type Control);
            bool Has_Button_Control(uint16_t Button_Identifier, Button_Matrix_Control_Type Control);

            // - - Setters.

            virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

            void Set_Button_Width(uint16_t Button_Identifier, uint8_t Width);

            void Set_Map(const char **Map);
            void Set_Control_Map(Button_Matrix_Control_Type *Map);
            void Set_Selected_Button(uint16_t Button_Identifier);
            void Set_Button_Control(uint16_t Button_Identifier, Button_Matrix_Control_Type Control);
            void Set_Button_Control_All(Button_Matrix_Control_Type Control);

            void Set_One_Checked(bool Enabled);

            // - - Getters
            const char **Get_Map();
            uint16_t Get_Selected_Button();

            const char *Get_Button_Text(uint16_t Button_Identifier);
            bool Get_Popovers();
            bool Get_One_Checked();

            // - - Attributes
            static const Class_Type &Class;
        } Button_Matrix_Type;
    }
}

#endif