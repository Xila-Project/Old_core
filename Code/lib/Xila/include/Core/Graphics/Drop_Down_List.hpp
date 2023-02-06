///
/// @file Drop_Down_List.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 30-06-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Drop_Down_List_Hpp_Included
#define Drop_Down_List_Hpp_Included

#include "Object.hpp"
#include "List.hpp"

namespace Xila_Namespace
{
    typedef class Drop_Down_List_Class : public Object_Class
    {
    public:
        // - Methods

        // - - Management

        void Create(Object_Class Parent_Object);

        void Add_Option(const char *Option, uint32_t Position);
        void Clear_Options();

        void Open();
        void Close();

        bool Is_Open();

        // - - Setters
        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);
        void Set_Text(const char *Text);
        void Set_Options(const char *Options);
        void Set_Options_Static(const char *Options);
        void Set_Selected(uint16_t Selected_Option);
        void Set_Direction(Direction_Type Direction);
        void Set_Symbol(const void *Symbol);
        void Set_Selected_Highlight(bool Enabled);

        // - - Getters
        List_Class Get_List();
        const char *Get_Text();
        const char *Get_Options();
        uint16_t Get_Selected_Option();
        uint16_t Get_Option_Count();
        void Get_Selected_String(char *Buffer, size_t Buffer_Size);
        const char *Get_Symbol();
        bool Get_Selected_Highlight();
        Direction_Type Get_Direction();

    } Drop_Down_List_Type;
}

#endif