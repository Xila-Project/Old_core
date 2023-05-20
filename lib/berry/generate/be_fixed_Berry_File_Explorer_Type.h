#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Explorer_Type_map) {
    { be_const_key(init, 5), be_const_ctype_func(Berry_File_Explorer_Class_Initialize_939D3A1B_18F0_4768_8939_72EE8D4EB70F) },
    { be_const_key(Get_Path, 14), be_const_ctype_func(Berry_File_Explorer_Class_Get_Path_B398B648_C276_4E7C_9110_6FE593AF01ED) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Go_Parent_Folder, -1), be_const_ctype_func(Berry_File_Explorer_Class_Go_Parent_Folder_D395CBF8_BCC0_4882_B3F5_3FFA79FD4333) },
    { be_const_key(Get_Selected_Count, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Count_67FE0B31_3CBE_4C15_B858_152D6947D492) },
    { be_const_key(Get_Selection_State, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selection_State_C0B280A0_D650_4AF2_A116_AAC82F3B4561) },
    { be_const_key(Refresh, 13), be_const_ctype_func(Berry_File_Explorer_Class_Refresh_33680F14_C60C_4ADB_B24A_E54B645888CA) },
    { be_const_key(Get_Selected_Name, 11), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Name_C2AD5EB5_D727_45D4_9C0E_4F65998A165A) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_File_Explorer_Class_Delete_9DA62CF5_F1BC_4F7D_9539_9A8B40181F22) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_File_Explorer_Class_Create_8C952754_B1F7_4868_BB83_E473BD8762D2) },
    { be_const_key(Set_Selection_State, 1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Selection_State_7E9D28E3_453F_480D_AF8F_83F5F0A53725) },
    { be_const_key(Get_Focused_Name, 12), be_const_ctype_func(Berry_File_Explorer_Class_Get_Focused_Name_6319705D_1FC4_48FE_AAE1_F7B7AC143A72) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Explorer_Class_Deinitialize_9961D805_7A5E_43F3_B958_AC006CC25A07) },
    { be_const_key(Set_Path, -1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Path_E6C453F3_140B_4E79_9061_EA0338271A01) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_File_Explorer_Class_Clear_Selection_22215417_CE60_42E2_9A7C_CCB2FC28CAE9) },
};

static be_define_const_map(
    Berry_File_Explorer_Type_map,
    15
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_File_Explorer_Type,
    1,
    (bclass *)&Berry_Object_Type,
    File_Explorer_Type
);
