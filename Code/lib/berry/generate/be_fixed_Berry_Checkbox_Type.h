#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_8066B04A_B0DF_42ED_90E5_1D406886A6A9) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_C28F1E40_559F_43E6_8477_5E4B75A1155A) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_89A83180_5319_4D5D_9CB5_2F9678F490A9) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_BCEBAE71_DDA2_420B_B9B3_B9AEC53BDEB6) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_5A0C5F98_387C_4BC1_85E9_E0115CB3E1A7) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_AE734BDC_2DAF_4E8A_AF5D_BE2E627387BD) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Checkbox_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Checkbox_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Checkbox_Type
);
