#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_D140355E_FD03_4397_9204_4DD922ACAA48) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_3C4BE10F_ABC4_4943_B042_0C6240270BBC) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_2D21A5E0_216A_4018_99DE_1AA22C6314ED) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_4DC35716_C61D_4CF2_8918_311C822DE29B) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_CF9384C0_8D4A_45AD_9A58_DAC22DA41B79) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_0EEE063D_0746_491C_AF73_DDDE4880FD77) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_38FA0420_FE66_49D4_BB7C_BAD9DE831C3B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_0940765C_55A5_489B_8FBE_E3D88C6C5758) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_5A5FD891_36B4_4F2C_9336_90AF0B7BBD68) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_50D6206E_F62D_46B9_8A92_760E224A0DD1) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_AA1F54A6_85B0_4CAC_850C_4643E84496F0) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_61BDE825_8CB3_426D_9E62_FCD8E452192C) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_C680D26D_41C5_43DD_B357_956CBA02AFA5) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_63AAF96B_9DA8_4C4B_AC83_F9DA5DA81339) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_8F75FA1F_7EF6_4EC1_BC27_7B47B85588D2) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_55CCEB6B_85F6_46AF_BB2F_72280EE7CBC4) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_37D6DC12_8C20_4671_AA5D_4D52385AFB6D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_6961827B_C25B_44C2_A7EC_617B731E9922) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_212DC9A0_A807_4169_81AB_6239DC4113E7) },
};

static be_define_const_map(
    Berry_Label_Type_map,
    20
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Label_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Label_Type
);
