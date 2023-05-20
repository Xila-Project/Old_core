#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_9D8C37CD_4814_40F1_91B5_126A0707FB66) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_5C00A786_B0D4_4E88_93A0_EBC15DE390B7) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_0371B407_2614_4CCD_AB57_025177DBB1B4) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_70749A39_E60E_4301_B190_E982EF3F8160) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_700F0788_588F_4328_A7F1_A81BF2DCE986) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_0720D5A0_2037_4631_894B_A5B1D66D7ADB) },
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
