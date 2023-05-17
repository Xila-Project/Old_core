#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_Window_Class_Initialize_E06156A4_37D2_4F55_981B_3B4A1A983F25) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_375DF88C_8002_42F5_8094_BC8827BE294C) },
    { be_const_key(Is_Valid, 11), be_const_ctype_func(Berry_Window_Class_Is_Valid_3E8C4BD6_E88B_4F7B_920B_20ED3D46EFEA) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_3F06B630_0796_4620_BC4E_FEB59994A3B1) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_E2EE2AE2_143C_440C_B7BE_C4A41A78EE30) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_Window_Class_Get_Header_90A77ED7_9476_4FEE_8EEC_C5C1C7327F20) },
    { be_const_key(Set_State, 5), be_const_ctype_func(Berry_Window_Class_Set_State_C67DF353_D5D7_4682_82DA_C5892EDA41EA) },
    { be_const_key(Get_Minimize_Button, 4), be_const_ctype_func(Berry_Window_Class_Get_Minimize_Button_D2AAA759_15C4_4E94_8E46_2B653DC4349D) },
    { be_const_key(Get_Owner_Software, 12), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_42D01278_8117_4038_869E_ACA929E3BE09) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Window_Class_Create_C9447FC8_20FA_4829_84B2_1DFEF0ABDAA8) },
    { be_const_key(Set_Title, -1), be_const_ctype_func(Berry_Window_Class_Set_Title_14279313_D6DB_4C3D_B715_18A849C6C22B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Window_Class_Delete_705049BE_952A_4444_8B52_4EC7862686DB) },
    { be_const_key(Get_Body, -1), be_const_ctype_func(Berry_Window_Class_Get_Body_00A8CA53_40C5_4A48_99D9_824D2D4017D8) },
    { be_const_key(Get_Close_Button, -1), be_const_ctype_func(Berry_Window_Class_Get_Close_Button_6A43689F_EA7D_4EA5_B3AE_4BD468CDEB7E) },
};

static be_define_const_map(
    Berry_Window_Type_map,
    15
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Window_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Window_Type
);
