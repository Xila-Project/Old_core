#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_0BBE1436_F27D_45D0_A4B6_A3E479D9A289) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_E15E124E_3A5E_4E62_A7E8_981392E6DB6C) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_CEF3B598_CA30_4869_B30F_DEC2B4A7FBC1) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_53BD9721_04DB_44C7_8318_DBB126A89E54) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_BCFA5B29_4BF3_46C1_877B_CD1852D0BC96) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_89A90E78_2221_46C8_9497_9CE77C91C858) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_4AFF7503_D6A5_4025_96EA_016067D50640) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_7C036001_62F1_46F2_87CF_D1D98F4C5C17) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_72C96140_816C_4183_AF46_7117C2F2A3BC) },
};

static be_define_const_map(
    Berry_Area_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Area_Type,
    1,
    NULL,
    Area_Type
);
