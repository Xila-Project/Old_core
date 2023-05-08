#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Dialog_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Get_Color_3D21F14A_9E02_451B_B6E5_B9BF53857980) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Set_Color_325F4F87_DEB7_45D5_8E5C_213C38619D85) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_Color_Dialog_Class_Deinitialize_1C8DE671_F639_4FA1_A95B_73C259418982) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Dialog_Class_Create_391C5F77_7533_4567_9071_BAF0BA28967C) },
};

static be_define_const_map(
    Berry_Color_Dialog_Type_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Dialog_Type,
    1,
    (bclass *)&Berry_Dialog_Type,
    Color_Dialog_Type
);
