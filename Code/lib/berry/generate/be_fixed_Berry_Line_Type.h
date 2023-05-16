#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_7F1F1DE5_BEC1_4307_8DE9_4C2E485D5543) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_A781839C_9F6D_4D42_BDA3_F749FF519143) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_2790F5E8_62DC_4037_8A95_24FB6FC3842E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_6BF6E8DF_280B_47A4_8AD3_6452EAB89A55) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_A72D0213_D6C9_49D1_B36A_5C8C652F7525) },
};

static be_define_const_map(
    Berry_Line_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Line_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Line_Type
);
