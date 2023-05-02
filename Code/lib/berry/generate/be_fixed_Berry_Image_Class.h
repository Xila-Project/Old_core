#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Class_map) {
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_void) },
    { be_const_key(Set_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_void_Graphics_TypesCoordinate_Type) },
    { be_const_key(Create, 13), be_const_ctype_func(Berry_Image_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Set_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_void_Graphics_TypesImage_ClassSize_Mode_Type) },
    { be_const_key(Set_Source, -1), be_const_ctype_func(Berry_Image_Class_Set_Source_void_void) },
    { be_const_key(Set_Zoom, 3), be_const_ctype_func(Berry_Image_Class_Set_Zoom_void_uint16_t) },
    { be_const_key(Get_Angle, 14), be_const_ctype_func(Berry_Image_Class_Get_Angle_void) },
    { be_const_key(Set_Pivot, 6), be_const_ctype_func(Berry_Image_Class_Set_Pivot_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_void_Graphics_TypesObject_ClassPoint_Type) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Image_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_void) },
    { be_const_key(Get_Zoom, 2), be_const_ctype_func(Berry_Image_Class_Get_Zoom_void) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_Graphics_TypesImage_Class) },
    { be_const_key(Set_Angle, -1), be_const_ctype_func(Berry_Image_Class_Set_Angle_void_int16_t) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_void) },
    { be_const_key(Get_Antialias, 0), be_const_ctype_func(Berry_Image_Class_Get_Antialias_void) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_void_Graphics_TypesCoordinate_Type) },
    { be_const_key(Set_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Set_Antialias_void_bool) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Image_Class_Deinitialize_void) },
    { be_const_key(Get_Size_Mode, 9), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_void) },
};

static be_define_const_map(
    Berry_Image_Class_map,
    21
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Image_Class,
    1,
    NULL,
    Image_Type
);
