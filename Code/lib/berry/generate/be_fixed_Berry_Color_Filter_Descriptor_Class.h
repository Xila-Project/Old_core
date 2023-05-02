#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Filter_Descriptor_Class_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_Color_Filter_Descriptor_Class_Initialize_Graphics_TypesColor_Filter_Descriptor_Class) },
    { be_const_key(_p, 4), be_const_var(0) },
    { be_const_key(deinit, 1), be_const_ctype_func(Berry_Color_Filter_Descriptor_Class_Deinitialize_void) },
    { be_const_key(Set_Callback, -1), be_const_ctype_func(Berry_Color_Filter_Descriptor_Class_Set_Callback_void_Graphics_TypesColor_Filter_Descriptor_ClassCallback_Type) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Color_Filter_Descriptor_Class_Get_Pointer_void) },
};

static be_define_const_map(
    Berry_Color_Filter_Descriptor_Class_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Filter_Descriptor_Class,
    1,
    NULL,
    Color_Filter_Descriptor_Type
);
