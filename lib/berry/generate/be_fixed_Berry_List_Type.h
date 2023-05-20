#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Type_map) {
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_List_Class_Add_Text_1A5A7D08_65A2_4824_A58A_4E4D7547B9D2) },
    { be_const_key(Create, 3), be_const_ctype_func(Berry_List_Class_Create_17BC38F6_F8BD_4F14_B7F9_C71F445EF2C5) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_B9FEA4A8_2F60_4564_B8AF_8EC2D71F63C5) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_4DEC854B_6F17_4167_A24F_E33B93090FA0) },
    { be_const_key(Get_Button_Text, 2), be_const_ctype_func(Berry_List_Class_Get_Button_Text_BE56BDF8_B4B6_4FA1_8582_A3588E781F7D) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_List_Class_Deinitialize_0571FDC0_47E3_4640_B216_005EEF0DA1D6) },
    { be_const_key(_p, 0), be_const_var(0) },
};

static be_define_const_map(
    Berry_List_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_List_Type,
    1,
    (bclass *)&Berry_Object_Type,
    List_Type
);
