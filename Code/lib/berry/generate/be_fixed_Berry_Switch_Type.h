#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_2A432D33_3D33_4BF4_9649_32BEC292E7AF) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_99AC1BC7_05A4_4BFE_9B50_4CC88FE253F0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_EF520C9A_F435_4D84_B0AB_02FC49EE28A4) },
};

static be_define_const_map(
    Berry_Switch_Type_map,
    4
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Switch_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Switch_Type
);
