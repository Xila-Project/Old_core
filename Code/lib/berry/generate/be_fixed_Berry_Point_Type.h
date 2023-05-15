#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_5CB64444_8E60_4DD7_BDFC_E3778497FFA5) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_F5498FE8_F12D_43A9_B47F_143CD30D7661) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_817B5623_D4CD_444D_9AFA_D32A810844EF) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_423516C4_5771_4B3F_9433_35440C1DD27D) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_29935B6F_A6BE_4934_9330_5BA670908B6B) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_0878C963_3F45_404B_9DD9_92B4AA7CF088) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_92DE3504_A8DD_474B_96C2_6CA722D92DBC) },
};

static be_define_const_map(
    Berry_Point_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Point_Type,
    1,
    NULL,
    Point_Type
);
