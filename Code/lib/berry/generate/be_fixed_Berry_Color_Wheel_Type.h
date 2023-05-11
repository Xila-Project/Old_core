#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Wheel_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Color_5904BC91_DE53_480E_B62D_96BFC80744DE) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Color_1377BFEB_AFDE_41DB_8A23_3E61DC93546B) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Color_Wheel_Class_Deinitialize_4153B031_24E7_42D2_865D_74C9105C7996) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_30DFF5AC_FC10_4D2A_8D44_31E8651A1198) },
    { be_const_key(Get_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_Fixed_5D3F2224_CBB1_4D3D_B45A_69E6B699CB6B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Initialize_F287D0BF_BE33_4145_95DE_C2F257DD1F0B) },
    { be_const_key(Set_Mode_Fixed, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_Fixed_457A5B63_27E0_4631_A976_DB608F975AB5) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_78D6396B_D927_4F3D_9EF6_0013957A1D27) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Wheel_Class_Create_3928DF89_8018_43E4_9087_CD7AFA0AEC04) },
};

static be_define_const_map(
    Berry_Color_Wheel_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Wheel_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Color_Wheel_Type
);
