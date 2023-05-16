#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_3EB4BE04_9520_4ABB_A92C_78C62E087843) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_6A3EA909_B444_4A37_93F2_72E3CD1CEE69) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_1B1D15EF_D4D0_41E7_A8FA_A38EFDC4A6C3) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_1E23C1EC_00B9_4948_9E59_600566CAAD61) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_588306FA_1AEC_46D2_B67C_F6BE81CEE81B) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_DA6D8955_48D6_49F0_94DA_4AA862CAED13) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_39F3D225_AA97_48B5_A273_492F97CB69BD) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_6B877199_DB8E_47CE_A0C4_7D6E07553F00) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_65110944_6B04_43A1_9764_CAFF324D1DB4) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_FD0B39B5_EB43_4520_80A0_1121A29173F6) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_36DD65FC_CE9F_4DDC_9B50_F3F665C66DA5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_E19A5721_45DA_47CE_91E4_13079C1C5DC8) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_D4E8F77B_8DAA_4E61_B147_32B6306D3937) },
};

static be_define_const_map(
    Berry_Slider_Type_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Slider_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Slider_Type
);
