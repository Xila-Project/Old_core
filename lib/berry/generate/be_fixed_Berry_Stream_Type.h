#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_8842A979_8572_4D2E_B0EB_E07B9EEC9136) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_03278073_AEFC_4878_8C09_5A9406EE8860) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_7216C9A1_A4B5_469D_8C31_7E27906888C6) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_6FDDDC20_6DAB_4202_B728_1752FF27F706) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_1BFD0FC7_7303_45EE_8F2B_BF2B16CDD1F8) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_BE4D344F_D8D9_4728_AE12_95DBE178310A) },
};

static be_define_const_map(
    Berry_Stream_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Stream_Type,
    1,
    NULL,
    Stream_Type
);
