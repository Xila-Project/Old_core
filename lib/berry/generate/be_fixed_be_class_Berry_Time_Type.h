#include "be_constobj.h"

static be_define_const_map_slots(be_class_Berry_Time_Type_map) {
    { be_const_key(Get_Hours, -1), be_const_ctype_func(Berry_Time_Type_Get_Hours) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Time_Type_Deinitialize) },
    { be_const_key(Set_Seconds, -1), be_const_ctype_func(Berry_Time_Type_Set_Seconds) },
    { be_const_key(Get_Milliseconds, -1), be_const_ctype_func(Berry_Time_Type_Get_Milliseconds) },
    { be_const_key(Get_Seconds, 4), be_const_ctype_func(Berry_Time_Type_Get_Seconds) },
    { be_const_key(Set_Minutes, -1), be_const_ctype_func(Berry_Time_Type_Set_Minutes) },
    { be_const_key(Get_Minutes, -1), be_const_ctype_func(Berry_Time_Type_Get_Minutes) },
    { be_const_key(Set_Milliseconds, 0), be_const_ctype_func(Berry_Time_Type_Set_Milliseconds) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Time_Type_Initialize) },
    { be_const_key(Set_Hours, -1), be_const_ctype_func(Berry_Time_Type_Set_Hours) },
};

static be_define_const_map(
    be_class_Berry_Time_Type_map,
    11
);

BE_EXPORT_VARIABLE be_define_const_class(
    be_class_Berry_Time_Type,
    1,
    NULL,
    Time_Type
);
