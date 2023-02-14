///
/// @file Calendar.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 09-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Calendar_Hpp_Included
#define Calendar_Hpp_Included

#include "Object.hpp"
#include "Button_Matrix.hpp"

namespace Xila_Namespace
{
    typedef class Calendar_Class : public Object_Class
    {
    public:
        typedef lv_calendar_date_t Date_Type;

        // -- Methods

        void Create(Object_Class Parent_Object) override;

        // -- -- Setters.

        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);

        void Set_Today_Date(uint32_t Year, uint32_t Month, uint32_t Day);
        void Set_Showed_Date(uint32_t Year, uint32_t Month);
        void Set_Highlighted_Dates(Date_Type *Date, uint16_t Number);

        void Set_Days_Names(const char **Day_Names);

        // -- -- Getters.
        Button_Matrix_Class Get_Button_Matrix();

        const Date_Type *Get_Today_Date();
        const Date_Type *Get_Showed_Dates();
        Date_Type *Get_Highlighted_Dates();
        uint16_t Get_Highlighted_Dates_Number();
        bool Get_Pressed_Date(Date_Type *Date);
    } Calendar_Type;
}

#endif