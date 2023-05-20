#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_CB3741D8_C74E_4DE8_A36F_62390AE8E2D9) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_C070FA3E_BEBE_4811_A971_CDB3374F30E5) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_A8467ABC_739E_48C0_B08B_260DDD8F765C) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_E7556A16_582D_4861_B73C_0C4B2E6675B3) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_52D40AFC_D1BB_4E1F_938E_F7E5941855F6) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_7F18F261_C067_47A1_B382_B9B514F73DEC) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_BB5E3377_8FDC_4052_A9DB_92E9C3D555FC) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_A8E176C5_0256_414C_BE3F_A682FE0DD59F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_4ED3FF75_39A5_477D_B367_CCB316FCFC87) },
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
