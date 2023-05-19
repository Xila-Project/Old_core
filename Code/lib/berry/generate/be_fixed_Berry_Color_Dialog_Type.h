#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Dialog_Type_map) {
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Get_Color_1BC53F0D_4B2D_4785_B2A4_7846F28148A5) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Set_Color_4B9584C8_4030_4406_83DC_1591F2C963FC) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_Color_Dialog_Class_Deinitialize_8E886EE0_507D_4BCF_AFA4_FE5C95C9A964) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Color_Dialog_Class_Create_8A11D286_089C_4DA3_AD0B_99EA93924165) },
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
