#include "be_constobj.h"

static be_define_const_map_slots(Berry_Canvas_Class_map) {
    { be_const_key(Vertical_Blur, -1), be_const_ctype_func(Berry_Canvas_Class_Vertical_Blur_void_Graphics_TypesArea_Type_uint16_t) },
    { be_const_key(Draw_Image, -1), be_const_ctype_func(Berry_Canvas_Class_Draw_Image_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_void_Graphics_TypesCanvas_ClassDraw_Image_Descriptor_Type) },
    { be_const_key(Transform, -1), be_const_ctype_func(Berry_Canvas_Class_Transform_void_Graphics_TypesCanvas_ClassImage_Descriptor_Type_int16_t_uint16_t_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_int32_t_int32_t_bool) },
    { be_const_key(Draw_Rectangle, -1), be_const_ctype_func(Berry_Canvas_Class_Draw_Rectangle_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCanvas_ClassDraw_Rectangle_Descriptor_Type) },
    { be_const_key(Copy_Buffer, -1), be_const_ctype_func(Berry_Canvas_Class_Copy_Buffer_void_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type) },
    { be_const_key(Horizontal_Blur, -1), be_const_ctype_func(Berry_Canvas_Class_Horizontal_Blur_void_Graphics_TypesArea_Type_uint16_t) },
    { be_const_key(Set_Buffer, -1), be_const_ctype_func(Berry_Canvas_Class_Set_Buffer_void_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesImage_ClassColor_Format_Type) },
    { be_const_key(Create, 18), be_const_ctype_func(Berry_Canvas_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(Set_Pixel_Opacity, 2), be_const_ctype_func(Berry_Canvas_Class_Set_Pixel_Opacity_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesOpacity_Type) },
    { be_const_key(Set_Pixel, -1), be_const_ctype_func(Berry_Canvas_Class_Set_Pixel_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesObject_ClassColor_Type) },
    { be_const_key(Draw_Polygon, -1), be_const_ctype_func(Berry_Canvas_Class_Draw_Polygon_void_Graphics_TypesObject_ClassPoint_Type_uint32_t_Graphics_TypesCanvas_ClassDraw_Rectangle_Descriptor_Type) },
    { be_const_key(Get_Pixel, -1), be_const_ctype_func(Berry_Canvas_Class_Get_Pixel_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type) },
    { be_const_key(Get_Image, 17), be_const_ctype_func(Berry_Canvas_Class_Get_Image_void) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Canvas_Class_Initialize_Graphics_TypesCanvas_Class) },
    { be_const_key(Draw_Arc, -1), be_const_ctype_func(Berry_Canvas_Class_Draw_Arc_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_int32_t_int32_t_Graphics_TypesCanvas_ClassDraw_Arc_Descriptor_Type) },
    { be_const_key(Draw_Text, -1), be_const_ctype_func(Berry_Canvas_Class_Draw_Text_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCanvas_ClassDraw_Label_Descriptor_Type_char) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Canvas_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Draw_Line, 21), be_const_ctype_func(Berry_Canvas_Class_Draw_Line_void_Graphics_TypesObject_ClassPoint_Type_uint32_t_Graphics_TypesCanvas_ClassDraw_Line_Descriptor_Type) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Canvas_Class_Deinitialize_void) },
    { be_const_key(Set_Palette, 7), be_const_ctype_func(Berry_Canvas_Class_Set_Palette_void_uint8_t_Graphics_TypesObject_ClassColor_Type) },
    { be_const_key(Fill_Background, 22), be_const_ctype_func(Berry_Canvas_Class_Fill_Background_void_Graphics_TypesObject_ClassColor_Type_Graphics_TypesOpacity_Type) },
    { be_const_key(Set_Pixel_Color, -1), be_const_ctype_func(Berry_Canvas_Class_Set_Pixel_Color_void_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Graphics_TypesObject_ClassColor_Type) },
};

static be_define_const_map(
    Berry_Canvas_Class_map,
    23
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Canvas_Class,
    1,
    NULL,
    Canvas_Type
);
