#include "be_constobj.h"

static be_define_const_map_slots(be_class_Berry_Date_Type_map) {
    { be_const_key(Set_Month, 4), be_const_ctype_func(Berry_Date_Type_Set_Month) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Date_Type_Deinitialize) },
    { be_const_key(Get_Day, 0), be_const_ctype_func(Berry_Date_Type_Get_Day) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Date_Type_Set) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Date_Type_Initialize) },
    { be_const_key(Set_Day, -1), be_const_ctype_func(Berry_Date_Type_Set_Day) },
    { be_const_key(Set_Year, -1), be_const_ctype_func(Berry_Date_Type_Set_Year) },
    { be_const_key(Get_Month, -1), be_const_ctype_func(Berry_Date_Type_Get_Month) },
    { be_const_key(Get_Year, 7), be_const_ctype_func(Berry_Date_Type_Get_Year) },
};

static be_define_const_map(
    be_class_Berry_Date_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    be_class_Berry_Date_Type,
    1,
    NULL,
    Date_Type
);
