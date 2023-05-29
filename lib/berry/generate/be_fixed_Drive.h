#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_509A0C66_1F28_4135_8662_32272AF61833) },
    { be_const_key(Open, 18), be_const_ctype_func(Berry_Drive_Class_Open_D258C0FC_E9B2_49A5_80F0_5531194C93D2) },
    { be_const_key(Rename, 13), be_const_ctype_func(Berry_Drive_Class_Rename_3E06BD8E_9E78_4C56_8162_4D325F9F9A0B) },
    { be_const_key(End, 0), be_const_ctype_func(Berry_Drive_Class_End_6995C328_1904_40FF_9899_0DBDF3EC815B) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_C908EF0D_1A59_40CE_923E_C0D491C3FEC1) },
    { be_const_key(Get_Used_Size, 14), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_3858A05A_4B90_4206_93FC_AA0BD1BF0435) },
    { be_const_key(Seek_Mode_Current, 10), be_const_int(1) },
    { be_const_key(Get_Type, 9), be_const_ctype_func(Berry_Drive_Class_Get_Type_2E85C249_45E6_40B0_8C13_558CC524B54F) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_435D76F3_4D38_4A3B_A31D_5AE6E6A66A7A) },
    { be_const_key(File_Type, 17), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, 15), be_const_ctype_func(Berry_Drive_Class_Exists_7B87F6F3_4E47_420C_B7FC_DF3CA4A07FB8) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_End, 21), be_const_int(2) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_47293A56_64FA_4B53_9CB8_881B856E05AF) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_A972F9FC_ABAA_4187_A52A_9FD0D7377B26) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Remove_File, 11), be_const_ctype_func(Berry_Drive_Class_Remove_File_70F4E62F_1F24_4E1C_AC96_882F27C0DCA1) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_57D32F34_DBA7_4339_9011_39F6A26C1DCC) },
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
