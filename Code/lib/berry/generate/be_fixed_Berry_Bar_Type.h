#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_683B6B70_E5C1_4F46_BCE6_2DB999CF2139) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_87BDE45E_9CD3_4B99_B6F8_274E34EA497A) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_04D32D1D_5CD0_4D96_B376_E93FB6161B0A) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_02160AC6_5CFB_411F_AB72_B04DD74E3A5E) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_57009A40_8D96_4B2A_8CCA_0220527FB721) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_82968BD1_13F9_42C2_9C3E_1758FD53AE66) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_23D3855B_A1F4_416F_BE4A_5C2808201C3F) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_25C459D6_7E71_49ED_9CC8_7F1F3415E8EB) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_D1B5EE93_2ECA_4080_B24B_597D0CC8B086) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_94F18272_BC2F_4155_8F75_DED2CC615847) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_23750CEB_2D3D_468F_8D4E_196290089257) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_7E8F2B1F_1D69_42FA_925C_61BDA2BB5D0B) },
};

static be_define_const_map(
    Berry_Bar_Type_map,
    13
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Bar_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Bar_Type
);
