#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_MMC, 1), be_const_int(1) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_17635B3C_0D24_4949_8038_8A30FDE87285) },
    { be_const_key(Remove_File, -1), be_const_ctype_func(Berry_Drive_Class_Remove_File_D4BDC05C_5679_4954_9951_BCCD72ADD950) },
    { be_const_key(Get_Type, 19), be_const_ctype_func(Berry_Drive_Class_Get_Type_18C25583_4466_43B4_A285_C58EA2195627) },
    { be_const_key(Seek_Mode_End, 0), be_const_int(2) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_5A59C160_050E_4C82_A553_C129A7AEC0E4) },
    { be_const_key(Open, 16), be_const_ctype_func(Berry_Drive_Class_Open_D6020EE0_3B05_4B31_B07E_B0C40B2DE8C2) },
    { be_const_key(Remove_Directory, 23), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_CD809724_8738_47CB_B7CB_6DDBBEC9DAD9) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_B7C3A43C_909C_497E_8FE5_84A99BC8C21D) },
    { be_const_key(End, 7), be_const_ctype_func(Berry_Drive_Class_End_AC86A73F_999D_4895_B835_262BE9B9268C) },
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Copy, 5), be_const_ctype_func(Berry_Drive_Class_Copy_B1094A02_00F8_4029_898D_EB9670A3DCEB) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_DC03D514_4CCE_42E9_BBFD_A3652E2CB0EA) },
    { be_const_key(Get_Used_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_4F874E4A_8210_4E13_A928_EB111AAD2759) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_211AA350_44D2_4222_820C_1BCD15005EF2) },
    { be_const_key(Rename, -1), be_const_ctype_func(Berry_Drive_Class_Rename_4B4D89F8_DFE2_468E_923E_0ABB4EB8EE43) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_D5C21762_0571_4069_B0FA_4ED4C7576C91) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_Drive_Class_Cut_83E88A81_4D5E_4A62_AC30_10033FCEB1CE) },
    { be_const_key(Seek_Mode_Current, 9), be_const_int(1) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
};

static be_define_const_map(
    m_libDrive_map,
    25
);

static be_define_const_module(
    m_libDrive,
    "Drive"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Drive);
