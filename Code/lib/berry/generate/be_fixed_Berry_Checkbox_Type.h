#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_F1541488_41DB_459F_9C83_6F783DDAC23F) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_D0A9F2E1_D21E_40B5_88ED_076F86621E31) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_98387866_1BAC_4439_8D38_C714F64D626E) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_3C1AA2FD_A763_4C2F_A1A9_42626D9D2DDA) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_38B6931A_C953_4454_85D3_10E1D26CBB61) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_E7F9347D_7E80_41CB_86E8_EFC3741E7A5F) },
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
