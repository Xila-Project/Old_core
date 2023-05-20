#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_4D2C91B2_A215_4BF7_9B4C_674D9365F152) },
    { be_const_key(Open, 18), be_const_ctype_func(Berry_Drive_Class_Open_73F53369_9FFE_4295_9CAE_584D549639B7) },
    { be_const_key(Rename, 13), be_const_ctype_func(Berry_Drive_Class_Rename_96DBDF04_40DB_4843_BD91_44952E68F833) },
    { be_const_key(End, 0), be_const_ctype_func(Berry_Drive_Class_End_B337BB24_81BD_448B_AB67_3B3FC4C99F90) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_F21DDE24_8C15_41BB_9E71_14E85FDC4D9C) },
    { be_const_key(Get_Used_Size, 14), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_CA35C4F5_4BDF_4400_90FC_3E9CE5A812D4) },
    { be_const_key(Seek_Mode_Current, 10), be_const_int(1) },
    { be_const_key(Get_Type, 9), be_const_ctype_func(Berry_Drive_Class_Get_Type_96EFA199_E3E4_4B0D_B1F5_6C8FF72C4B14) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_9D46FAF1_8467_4E8E_9B48_6AE476BBF89A) },
    { be_const_key(File_Type, 17), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, 15), be_const_ctype_func(Berry_Drive_Class_Exists_6A53CFA3_326B_4B27_8E33_5B0157399F7F) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_End, 21), be_const_int(2) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_A198A0A8_22AD_4FCA_B57B_F8A147FBB279) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_6D6A4137_3E30_467C_95ED_5BF6D49CF48E) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Remove_File, 11), be_const_ctype_func(Berry_Drive_Class_Remove_File_5FE836B0_ACCD_4467_AE0B_B4FBEBBCF02D) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_C7A7ABBB_ECBE_4D29_99A7_CB10E065BDEF) },
    { be_const_key(Drive_Unknow, 19), be_const_int(4) },
};

static be_define_const_map(
    m_libDrive_map,
    23
);

static be_define_const_module(
    m_libDrive,
    "Drive"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Drive);
