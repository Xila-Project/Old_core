#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_AB3631B7_329B_4AEC_965A_66D04614D32A) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_B491AB14_A582_46C1_9837_8B72D80A8576) },
    { be_const_key(Delete, 8), be_const_ctype_func(Berry_Window_Class_Delete_B064B4D2_8199_4C27_A84E_E13A1062D7E9) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_370AF9A8_A2C8_49A2_82FC_91396F029B5E) },
    { be_const_key(Get_Body, 11), be_const_ctype_func(Berry_Window_Class_Get_Body_98010FBA_08F1_4BD1_8608_41B3217A7419) },
    { be_const_key(Get_Owner_Software, -1), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_C131AC81_943E_4267_962C_FF54777827CE) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_B2211EEF_F011_4439_900D_DB2010766CBF) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_46FAF103_7251_4422_BBE4_46DE8B4CCE08) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, 0), be_const_ctype_func(Berry_Window_Class_Set_State_01C9D195_391E_48E5_A503_4E779C709C2E) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_ECB96914_D470_4723_B920_5AE7439AC810) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_4470C0A2_9BC8_4486_AD54_72BCCAF14982) },
};

static be_define_const_map(
    Berry_Window_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Window_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Window_Type
);
