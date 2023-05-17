#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_AEC632EA_D399_43E0_AD51_1AEE0E42DD17) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_59A0BFE5_7141_47AA_83B5_085ED381A0D9) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_9F6692B1_62A6_46CA_9FFD_4DEE75335C16) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_3BA34EFA_A900_49F6_A1E6_BD74B170F6F1) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_28D58FA2_E719_464B_B043_649062B5DF22) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_554FD533_6E6F_4395_AC61_EA2E7977E40C) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_87DC5EB5_1CB3_4A71_AD22_80C74049733F) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_0FE6C1FD_A1B0_44B1_9422_E604E2D1AD82) },
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
