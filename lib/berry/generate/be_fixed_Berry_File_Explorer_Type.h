#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Explorer_Type_map) {
    { be_const_key(init, 5), be_const_ctype_func(Berry_File_Explorer_Class_Initialize_E7ECACE3_ECA4_4393_9142_5E33EA336DA8) },
    { be_const_key(Get_Path, 14), be_const_ctype_func(Berry_File_Explorer_Class_Get_Path_F7493CAA_B704_4BFC_A713_C4AA88AD4604) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Go_Parent_Folder, -1), be_const_ctype_func(Berry_File_Explorer_Class_Go_Parent_Folder_E605288B_0222_482F_939B_3DB96D9764A8) },
    { be_const_key(Get_Selected_Count, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Count_D6A197E2_AB6D_42EC_B4F1_2D6B4D7ACB37) },
    { be_const_key(Get_Selection_State, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selection_State_5192CABE_B75C_477B_B8E2_BD3A7E06EE7B) },
    { be_const_key(Refresh, 13), be_const_ctype_func(Berry_File_Explorer_Class_Refresh_91C72C2D_4FAF_47CD_9FC3_7C0DDA89A938) },
    { be_const_key(Get_Selected_Name, 11), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Name_B928EE92_9A94_4965_85DC_6C41693952B0) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_File_Explorer_Class_Delete_B221D9DE_44EE_4757_BA63_083C7A548CAB) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_File_Explorer_Class_Create_3B1B4FD8_549D_47EF_9004_3D965A0919A7) },
    { be_const_key(Set_Selection_State, 1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Selection_State_1F76FD71_B035_4C12_B3C5_A1C603A8460C) },
    { be_const_key(Get_Focused_Name, 12), be_const_ctype_func(Berry_File_Explorer_Class_Get_Focused_Name_A8C4E10F_F1EB_4863_BE99_DEA58B92DC1D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Explorer_Class_Deinitialize_01C97087_5E18_4610_8FA9_DF27BB5BC4FE) },
    { be_const_key(Set_Path, -1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Path_CD7C42C5_6D82_4CB9_AFFE_31D3ADC4DA58) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_File_Explorer_Class_Clear_Selection_26FC7B62_C818_4D29_96DD_764DF173E46E) },
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
