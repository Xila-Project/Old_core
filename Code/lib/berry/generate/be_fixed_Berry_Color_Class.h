#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Class_map) {
    { be_const_key(Set_To_Black, -1), be_const_ctype_func(Berry_Color_Class_Set_To_Black_void) },
    { be_const_key(Get_RGB_32_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_32_Bits_void) },
    { be_const_key(Set_HSV, -1), be_const_ctype_func(Berry_Color_Class_Set_HSV_void_uint16_t_uint8_t_uint8_t) },
    { be_const_key(Get_RGB_16_Bits, 14), be_const_ctype_func(Berry_Color_Class_Get_RGB_16_Bits_void) },
    { be_const_key(Change_Lightness, -1), be_const_ctype_func(Berry_Color_Class_Change_Lightness_void_Graphics_TypesOpacity_Type) },
    { be_const_key(Set_Darker, 12), be_const_ctype_func(Berry_Color_Class_Set_Darker_void_Graphics_TypesOpacity_Type) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Lighter, 5), be_const_ctype_func(Berry_Color_Class_Set_Lighter_void_Graphics_TypesOpacity_Type) },
    { be_const_key(Get_LVGL_Color, 11), be_const_ctype_func(Berry_Color_Class_Get_LVGL_Color_void) },
    { be_const_key(Get_RGB_8_Bits, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_8_Bits_void) },
    { be_const_key(Get_LVGL_HSV_Color, -1), be_const_ctype_func(Berry_Color_Class_Get_LVGL_HSV_Color_void) },
    { be_const_key(Set_LVGL_Color, -1), be_const_ctype_func(Berry_Color_Class_Set_LVGL_Color_void_lv_color_t) },
    { be_const_key(Get_HSV, 1), be_const_ctype_func(Berry_Color_Class_Get_HSV_void_uint16_t_uint8_t_uint8_t) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Color_Class_Initialize_Graphics_TypesColor_Class) },
    { be_const_key(Set_RGB, -1), be_const_ctype_func(Berry_Color_Class_Set_RGB_void_uint32_t_bool) },
    { be_const_key(Get_Brightness, -1), be_const_ctype_func(Berry_Color_Class_Get_Brightness_void) },
    { be_const_key(Set_To_White, 18), be_const_ctype_func(Berry_Color_Class_Set_To_White_void) },
    { be_const_key(Get_RGB_1_Bit, -1), be_const_ctype_func(Berry_Color_Class_Get_RGB_1_Bit_void) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Class_Deinitialize_void) },
};

static be_define_const_map(
    Berry_Color_Class_map,
    19
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Class,
    1,
    NULL,
    Color_Type
);
