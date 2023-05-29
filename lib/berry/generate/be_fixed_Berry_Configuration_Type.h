#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_A662E693_5F45_4A18_AF34_8E88E371EBB8) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_AAAECCED_D3D3_4693_A279_FD6C1486D6BC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_30D9AB9D_4E51_4397_9518_E2A3238FB0AE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_DCD2D10A_DED8_4757_9CDE_6E7EDDCC377B) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_40E0A60D_690A_438D_8DC8_A47E15BA9248) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_CF3BF4BE_5116_4278_9B8F_A2064DC54277) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_9B9BE2E5_32E4_4B89_A4FB_4795FD0F490F) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_4BCC054E_4F49_4DA5_A20A_AAE7CEC30E2E) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_543A224E_7ECD_4185_93AE_0FD5983370EF) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_84ED9E67_9159_41EB_B308_E8A6C0D3D165) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_CD2EFA85_37F7_48CA_8A29_55F08215E5EC) },
};

static be_define_const_map(
    Berry_Configuration_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Configuration_Type,
    1,
    NULL,
    Configuration_Type
);
