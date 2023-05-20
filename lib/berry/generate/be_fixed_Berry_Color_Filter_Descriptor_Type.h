#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Filter_Descriptor_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Filter_Descriptor_Class_Deinitialize_CDFA5179_BF70_4871_965A_39961FD8D16F) },
};

static be_define_const_map(
    Berry_Color_Filter_Descriptor_Type_map,
    2
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Filter_Descriptor_Type,
    1,
    NULL,
    Color_Filter_Descriptor_Type
);
