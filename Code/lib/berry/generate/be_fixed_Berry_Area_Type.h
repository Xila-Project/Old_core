#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_790A67D9_CB7B_4797_8457_BB84E072CA27) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_7BEAF7F9_BF7C_4C5C_8EBC_C607415206A4) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_487B4BF3_0852_45AE_98BA_9ED914D63BEA) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_57BCC972_DCDE_45F1_9556_B93E4C9148B9) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_2AE20A96_97EC_45E3_9477_7E62FDDD0C0A) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_90F1FD7E_61AA_400E_A909_5960E0DDA411) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_4E427ED3_D1E9_4471_8D69_0FB5A4DDA44F) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_BE090B1B_254C_4D4F_B77E_2C08C5A78390) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_952ADA27_2DC0_4776_9A8C_A673492FE30D) },
};

static be_define_const_map(
    Berry_Area_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Area_Type,
    1,
    NULL,
    Area_Type
);
