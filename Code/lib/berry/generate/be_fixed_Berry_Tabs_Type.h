#include "be_constobj.h"

static be_define_const_map_slots(Berry_Tabs_Type_map) {
    { be_const_key(Set_Active_Tab, 1), be_const_ctype_func(Berry_Tabs_Class_Set_Active_Tab_A267AD55_BE8E_49DB_9F73_20ECD26B3395) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Tabs_Class_Deinitialize_933083D8_918A_48DB_A32C_2E831F2C1E64) },
    { be_const_key(Add_Tab, 0), be_const_ctype_func(Berry_Tabs_Class_Add_Tab_2A042C24_96D8_4658_8655_D31A20F9B943) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Tabs_Class_Create_47334179_1991_489B_AEF2_9266A2ABDC6A) },
    { be_const_key(Get_Tab_Active, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Active_6B61B896_FA97_4BB7_9D1D_1FAB70AF1AE7) },
    { be_const_key(Rename_Tab, 6), be_const_ctype_func(Berry_Tabs_Class_Rename_Tab_0F2D195C_9778_4A7C_BE46_FE997A61253E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Tabs_Class_Initialize_77BDB81F_CB1D_4143_9EDC_7FFA13D82786) },
    { be_const_key(Get_Tab_Buttons, -1), be_const_ctype_func(Berry_Tabs_Class_Get_Tab_Buttons_756C4E33_3616_440C_A0AE_C3FB5675BAF9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Content, 3), be_const_ctype_func(Berry_Tabs_Class_Get_Content_4EB2C495_DD4B_4BFE_84CE_CE63B03C1740) },
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
