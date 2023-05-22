#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_13646647_4252_4EE4_B3CF_23D6291535A0) },
    { be_const_key(Open, 18), be_const_ctype_func(Berry_Drive_Class_Open_2BDBE9EB_A16B_4715_BB8A_3910CD5C30A7) },
    { be_const_key(Rename, 13), be_const_ctype_func(Berry_Drive_Class_Rename_70D11C24_2648_4EBF_849C_8B5AB4B3A645) },
    { be_const_key(End, 0), be_const_ctype_func(Berry_Drive_Class_End_7535CB5F_4592_4662_A5C1_5EBC39189752) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_3A7D353C_62E9_4324_8959_C16734A3D77D) },
    { be_const_key(Get_Used_Size, 14), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_119C190F_818A_4633_9590_7DD2EA35A066) },
    { be_const_key(Seek_Mode_Current, 10), be_const_int(1) },
    { be_const_key(Get_Type, 9), be_const_ctype_func(Berry_Drive_Class_Get_Type_AB59EF46_30DE_42E2_BF52_1F43B27F61A1) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_8D393B9A_AFF8_4839_934B_D1F2CDBA287A) },
    { be_const_key(File_Type, 17), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, 15), be_const_ctype_func(Berry_Drive_Class_Exists_B5130633_07D3_441F_BDE1_55F374A7D45D) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_End, 21), be_const_int(2) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_74A2A9B4_E528_4810_BAFE_434C34CA25DB) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_EAE30C58_9FDF_4574_88ED_FE3EE123741D) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Remove_File, 11), be_const_ctype_func(Berry_Drive_Class_Remove_File_8CF4E696_B76A_4E29_930E_90D95C0B4C09) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_AE512A85_B4CA_4F73_A315_02FEB04F7F14) },
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
