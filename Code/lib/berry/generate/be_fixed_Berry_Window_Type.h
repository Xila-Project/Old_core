#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, 7), be_const_ctype_func(Berry_Window_Class_Create_31897684_0807_40AA_87D4_0E7E05D04C90) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_BFE5CE87_6948_4367_A0CF_8492B31AE751) },
    { be_const_key(Delete, 8), be_const_ctype_func(Berry_Window_Class_Delete_B4BE6108_6E24_40FF_91B5_DD9F2A764F1E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_F595DD7E_1867_4BA9_96AE_43E2DC9352FF) },
    { be_const_key(Get_Body, 11), be_const_ctype_func(Berry_Window_Class_Get_Body_EA0B582D_F794_4646_BBA3_53A2ED38CB16) },
    { be_const_key(Get_Owner_Software, -1), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_74B2029E_0EF3_4BE9_9A33_E38F36BA9E35) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_F9CBF941_FF0C_425F_824E_99608E5BF599) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_BF932236_3F6D_4C43_80FA_BFA837642704) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, 0), be_const_ctype_func(Berry_Window_Class_Set_State_385C8D06_4037_45A6_8E4E_FAB8E03EDE0F) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_7174827E_D16C_44FA_B897_4CCF908E7D84) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_39195F94_2736_434F_A072_9F7D9C75F59D) },
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
