#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_MMC, 1), be_const_int(1) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_2B8CE47A_364B_4BA6_B889_3D7FD14EF89A) },
    { be_const_key(Remove_File, -1), be_const_ctype_func(Berry_Drive_Class_Remove_File_60911068_66F3_4228_8626_720BC1153100) },
    { be_const_key(Get_Type, 19), be_const_ctype_func(Berry_Drive_Class_Get_Type_1F183E0A_53FD_45BA_BCB8_653B8E98A1BA) },
    { be_const_key(Seek_Mode_End, 0), be_const_int(2) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_B5B00EDA_E885_4F63_9760_78E0624B91A8) },
    { be_const_key(Open, 16), be_const_ctype_func(Berry_Drive_Class_Open_D16111FC_C663_4DD0_BC1E_969808AFBD82) },
    { be_const_key(Remove_Directory, 23), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_735997FB_A170_4794_A8F5_5E87CB56F10E) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_2989A6BA_5BE5_49FF_8259_45027DB032A8) },
    { be_const_key(End, 7), be_const_ctype_func(Berry_Drive_Class_End_AC9EDE07_8B3A_4597_A5C5_2FC91062463B) },
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Copy, 5), be_const_ctype_func(Berry_Drive_Class_Copy_5AF42A05_9299_4F13_BAF2_B4797F44B2DC) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_5B554AAF_2C34_4F42_BF53_9EEC3F21A52C) },
    { be_const_key(Get_Used_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_35C6CD16_C86B_4C87_A82D_9FFB30238A27) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_3317CA14_5085_4250_A776_8BA6D88FD8CB) },
    { be_const_key(Rename, -1), be_const_ctype_func(Berry_Drive_Class_Rename_8686FE70_D983_4E84_985D_C6D6CBE8BA08) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_0A87A5B1_449A_4FE1_AFE7_196157F72317) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_Drive_Class_Cut_8570D355_0270_4860_A066_F778BF783A28) },
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
