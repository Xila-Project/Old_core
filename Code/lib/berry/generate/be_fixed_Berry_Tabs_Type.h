#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_CF3BBD66_8989_4196_9C2C_F988FEE81026) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_9E6199A7_C883_468A_8B94_DA891542C50E) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_EDC034EA_3427_4F46_96F9_87856CE08D94) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_22B18BF9_0949_431A_8583_1E73B94C9FE6) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_1392D84F_5861_4039_9AD7_F7080FDB4CB5) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_926A43E8_1AAB_4485_88E8_6E4BFA8EFCFB) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_D1B93040_997D_463F_9585_545EFFC3E323) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_A929201F_48A7_444C_B4C6_9D62B435AA8B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_89CEDECB_0873_4D94_8D85_10D714F8B283) },
};

static be_define_const_map(
    Berry_Tabs_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Tabs_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Tabs_Type
);
