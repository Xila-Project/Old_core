#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_27CEE544_CE40_47B7_A61B_07E3AE80F165) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_B81B33FF_B4A5_445E_99F4_9F865A3C993D) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_A355846E_B8EA_4C04_88C1_8A1049ADFA63) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_FE93BEEC_36D1_45C3_B1BD_77FC53B44657) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_CF826E38_B52E_4C9A_8120_8F27CA2FBB89) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_56386575_FB87_4CBB_A4A6_2D39FC63FF31) },
    { be_const_key(_p, 2), be_const_var(0) },
};

static be_define_const_map(
    Berry_Volume_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Volume_Type,
    1,
    NULL,
    Volume_Type
);
