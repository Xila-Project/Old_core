#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Class_map) {
    { be_const_key(init, 13), be_const_ctype_func(Berry_Calendar_Class_Initialize_Graphics_TypesCalendar_Class) },
    { be_const_key(Get_Highlighted_Dates, 12), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_void) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Set_Highlighted_Dates, 3), be_const_ctype_func(Berry_Calendar_Class_Set_Highlighted_Dates_void_lv_calendar_date_t_uint16_t) },
    { be_const_key(Get_Button_Matrix, 1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_void) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_void_Date_Type) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_void) },
    { be_const_key(Set_Showed_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_void_uint32_t_uint32_t) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_void) },
    { be_const_key(Get_Today_Date, 8), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_void) },
    { be_const_key(Get_Showed_Date, 14), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_void) },
    { be_const_key(Set_Days_Names, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Days_Names_void_char) },
    { be_const_key(Get_Pressed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_void_Date_Type) },
};

static be_define_const_map(
    Berry_Calendar_Class_map,
    15
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Calendar_Class,
    1,
    NULL,
    Calendar_Type
);
