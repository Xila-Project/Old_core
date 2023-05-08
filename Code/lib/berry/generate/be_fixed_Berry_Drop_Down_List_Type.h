#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_1EF98EC5_56D2_4111_BDE9_45F7926BA87B) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_00ED41C2_EC1C_4F1F_B676_CEB64DEB16AD) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_C10885C8_0CCB_4046_B2B0_2236E04514FC) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_93B15816_6D22_4255_905B_458592F90885) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_B6507774_CF4A_4A55_B5A5_3D8698309D85) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_3A70EEF8_4B8F_4582_9ECD_A95D52323F20) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_E6CF98F2_0010_4237_A673_D0A216C6ECD0) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_09C72F12_FD99_4548_B4A3_635F68B00A5E) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_C13A0A2E_5BC5_449B_A1FA_5E286CC44BCA) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_B60AA795_8441_4011_9AC7_035F35A7CDE2) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_FA705F82_C691_464E_A8F5_8EC022919C42) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_49563C24_CE60_4C03_9157_76CFD23BEDC5) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_4658CB07_7911_44AB_AF86_73A60D086E74) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_0F160FA2_570B_4D10_8561_67ECEDE68A16) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_EE6E531D_6475_4F8C_83CC_DDF59A1FC1BE) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_318EF001_3950_41B9_B49E_932400167F12) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_4EFCE09C_8AF6_431F_BA8A_1E707367F65A) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_8294FC31_8C0C_422F_9782_31C5FBFF47B9) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_CB1BF557_E6FF_4145_B08C_157A183C4AC5) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_D06E4383_D740_4355_AB7C_711FBC623EC8) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_6CA71B2B_C8B2_40AE_81E8_99B6D1A9C4F5) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_187B890A_EDD9_45A2_8056_418F698BFCA7) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_FC20C619_745D_4039_91BD_463092717D29) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_136392F7_7F66_4771_A782_6FF1EE5493B7) },
};

static be_define_const_map(
    Berry_Drop_Down_List_Type_map,
    25
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Drop_Down_List_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Drop_Down_List_Type
);
