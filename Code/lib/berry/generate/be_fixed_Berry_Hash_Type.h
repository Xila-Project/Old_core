#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_211F164B_5F91_41EA_82A3_BE597D5F1878) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_C46DF562_9F1F_4570_B952_F35B92D2D836) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_51985932_B054_4F78_AC42_2AD4EF87573C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_60BCB544_CB73_4920_B6D6_8B58831F5542) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_DF3633C4_5AD3_4EBC_A7B4_92CC8F3BAC13) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_1BDE1989_6976_4B44_83E9_7E9A495B5BD4) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_2E7CFF2C_8091_4DA1_88CF_C4E96781467F) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_3DB025AD_7475_4AAA_8FE1_83D81877AC61) },
};

static be_define_const_map(
    Berry_Hash_Type_map,
    9
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Hash_Type,
    1,
    NULL,
    Hash_Type
);
