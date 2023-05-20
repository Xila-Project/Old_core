#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_CBBF9281_892F_43F6_ACFE_189FE899CE17) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_D4840338_ECA8_4770_99E0_15578258E832) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_4AE1C8AF_FC1D_4A7C_9FA2_581DAA842EF2) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_D297EDEF_57AF_43DE_9062_07178061EEB6) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_19CD62B7_67B1_4AD6_9027_856DCE65D3A0) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_DD8B2D82_FA02_447F_B3C5_273FC0A73497) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_B6F5AC07_DE1B_4004_BE83_E9EE670279E8) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_0782667C_9DD7_4404_9DD7_5958BB736A04) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_8FFBDAF7_291D_4E5F_99C8_FB27DE40471C) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_524CFFF6_7107_406E_BBE6_A2D7811487CE) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_01CEB2A9_A8C5_44E3_8B43_726A7D3D4E0A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_A65666AC_20B3_43EC_AA26_93A8126EA465) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_3BC6A3CF_9834_4A4B_A657_6616F8FA0909) },
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
