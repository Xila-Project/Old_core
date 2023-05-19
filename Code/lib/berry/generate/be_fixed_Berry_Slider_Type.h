#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_986D1441_BDD9_44E5_89C6_BD3CA1DCEFB1) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_EE4FB80B_C350_41B0_9751_F873A7FF006A) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_A90BB5DC_51CA_4952_BF93_A158EB219170) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_BFF03151_B7F3_4022_8F01_1DD5D166EEBC) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_8621C442_2E98_438C_8D1D_C68D01D2B263) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_F1C3917C_E477_466B_B18E_0BA6DA6B6294) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_70FE37B7_F2E0_4B90_9C4C_934CA79034C4) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_B84E67A1_C2E4_4BF7_880A_C8CB33019C82) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_B826EF39_E021_46DA_8B0F_6D6D07C50AB7) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_3F9BE2AD_5BA7_479F_BC93_8001D497B121) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_CA03D154_B6AC_4E94_9B34_751AD5B721CA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_E7FE015C_027E_4E03_83A0_BFC308D6BF0D) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_89FD0BC3_920D_43B0_848A_86A653E538B6) },
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
