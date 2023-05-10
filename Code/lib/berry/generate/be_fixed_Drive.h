#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Get_Size, 19), be_const_ctype_func(Berry_Drive_Class_Get_Size_EDED6D75_18E0_483A_AAAB_02D1DFEE1C26) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Cut, 4), be_const_ctype_func(Berry_Drive_Class_Cut_42860147_142C_4599_A84D_1FCFCC213E60) },
    { be_const_key(Rename, 22), be_const_ctype_func(Berry_Drive_Class_Rename_D03255BE_F5D3_4FA8_916E_F0B22C6DC902) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_2F3BA96E_3AFF_43E3_B8F8_E07B4A1CD10B) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_04762799_0C45_4224_AC56_AFA782BFE425) },
    { be_const_key(Seek_Mode_End, -1), be_const_int(2) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Drive_Class_Get_Type_346BF2CC_363C_4088_843E_B93E98CCA006) },
    { be_const_key(Open, 1), be_const_ctype_func(Berry_Drive_Class_Open_1DF1E27E_6991_40AC_9DFE_72CA568D3D77) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_2978D161_A1E2_4F63_A287_67C2D4746AEF) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_F41E8076_61B6_4FA6_BD69_1320C6AEA89E) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Get_Used_Size, 17), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_CFE49A0A_0CCA_4F03_92FB_46104DA3F4CD) },
    { be_const_key(Remove_File, 0), be_const_ctype_func(Berry_Drive_Class_Remove_File_D0E6F0C2_6B58_47A8_ACD1_38E4242091CA) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_0A86DB42_39D2_4021_B800_1E42B163505D) },
    { be_const_key(End, 2), be_const_ctype_func(Berry_Drive_Class_End_EA29FF5C_191C_46FC_8B80_50411CCBEFA7) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Drive_Class_Copy_7358D46C_8E15_40FF_A2BC_2B95C9707556) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_4067E7CD_C177_45C0_A140_60401DC03147) },
    { be_const_key(Seek_Mode_Current, -1), be_const_int(1) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
};

static be_define_const_map(
    m_libDrive_map,
    24
);

static be_define_const_module(
    m_libDrive,
    "Drive"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Drive);
