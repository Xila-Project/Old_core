#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Class_map) {
    { be_const_key(Move, -1), be_const_ctype_func(Berry_Area_Class_Move_void_Graphics_TypesArea_ClassCoordinate_Type_Graphics_TypesArea_ClassCoordinate_Type) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_void_Graphics_TypesArea_ClassCoordinate_Type) },
    { be_const_key(Align, 7), be_const_ctype_func(Berry_Area_Class_Align_void_Graphics_TypesArea_Class_Graphics_TypesArea_ClassAlignment_Type_Graphics_TypesArea_ClassCoordinate_Type_Graphics_TypesArea_ClassCoordinate_Type) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_void) },
    { be_const_key(Increase, -1), be_const_ctype_func(Berry_Area_Class_Increase_void_Graphics_TypesArea_ClassCoordinate_Type_Graphics_TypesArea_ClassCoordinate_Type) },
    { be_const_key(Get_Height, -1), be_const_ctype_func(Berry_Area_Class_Get_Height_void) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Area_Class_Initialize_Graphics_TypesArea_Class) },
    { be_const_key(_p, 9), be_const_var(0) },
    { be_const_key(Get_LVGL_Area, -1), be_const_ctype_func(Berry_Area_Class_Get_LVGL_Area_void) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_void) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_void_Graphics_TypesArea_ClassCoordinate_Type) },
    { be_const_key(Set, 2), be_const_ctype_func(Berry_Area_Class_Set_void_Graphics_TypesArea_ClassCoordinate_Type_Graphics_TypesArea_ClassCoordinate_Type_Graphics_TypesArea_ClassCoordinate_Type_Graphics_TypesArea_ClassCoordinate_Type) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Area_Class_Deinitialize_void) },
};

static be_define_const_map(
    Berry_Area_Class_map,
    13
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Area_Class,
    1,
    NULL,
    Area_Type
);
