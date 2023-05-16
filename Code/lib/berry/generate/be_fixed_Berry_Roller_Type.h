#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_9239CFA7_3DDC_4B68_91F0_16EF6683CDB0) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_C237E436_9D30_4470_B889_140A335AB4AA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_57DB5EF2_9271_4AC2_8579_F157CEBC61CD) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_B2792913_2970_49E0_824E_CB608FC46548) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_38FEE76E_D946_409F_AB79_46DB2DBD13DA) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_ABCDBB50_7C8D_4893_9746_96051A86DC97) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_D9088625_1CB2_4A78_B670_BB37753C6CF5) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_37C8D543_0C2C_48FB_AB20_3980CD160508) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_6C243562_6450_408E_8355_0FF21C9D2DD3) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_80A93CC6_217E_4E14_A6A8_294F5150E288) },
};

static be_define_const_map(
    Berry_Roller_Type_map,
    11
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Roller_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Roller_Type
);
