///
/// @file Text_Area.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Text_Area_Hpp_Included
#define Text_Area_Hpp_Included

#include "Object.hpp"
#include "Label.hpp"

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
        typedef class Text_Area_Class : public Object_Class
        {
        public:
            /// @brief Text area custom part enumeration.
            enum
            {
                Placeholder = LV_PART_TEXTAREA_PLACEHOLDER
            };

            // - Methods
            Text_Area_Class();
            Text_Area_Class(const Object_Class &Object_To_Copy);

            virtual void Create(Object_Class Parent_Object) override;

            void Add_Char(uint32_t Character);
            void Add_Text(const char *Text);
            void Delete_Character();
            void Delete_Character_Forward();
            void Clear_Selection();

            void Cursor_Right();
            void Cursor_Left();
            void Cursor_Up();
            void Cursor_Down();

            bool Is_Selected();

            // - - Setters

            virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

            void Set_Text(const char *Text);
            void Set_Placeholder_Text(const char *Text);
            void Set_Cursor_Click_Position(bool Enabled);
            void Set_One_Line(bool Enabled);
            void Set_Accepted_Characters(const char *Accepted_Characters);
            void Set_Maximum_Length(uint32_t Length);
            void Set_Insert_Replace(const char *Text);
            void Set_Text_Selection(bool Enabled);
            void Set_Password_Mode(bool Enabled);
            void Set_Password_Show_Time(uint16_t Time);
            void Set_Text_Alignment(Text_Alignment_Type Alignment);
            void Set_Cursor_Position(int32_t Position);

            // - - Getters

            const char *Get_Text();
            const char *Get_Placeholder_Text();
            Label_Class Get_Label();
            uint32_t Get_Cursor_Position();
            bool Get_Cursor_Click_Position();
            bool Get_Password_Mode();
            bool Get_One_Line();
            const char *Get_Accepted_Characters();
            uint32_t Get_Maximum_Length();
            bool Get_Text_Selection();
            uint16_t Get_Password_Show_Time();

            // - Attributes

            static const Class_Type &Class;

        } Text_Area_Type;
    }
}

#endif