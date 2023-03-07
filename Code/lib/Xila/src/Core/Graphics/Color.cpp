///
/// @file Color.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 09-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Color.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;

// - Color palette definition.

const Color_Type Color_Class::White(255, 255, 255);
const Color_Type Color_Class::Black(0, 0, 0);
const Color_Type Color_Class::Red[10] = {
    Color_Type(0xFF, 0xEB, 0xEE),
    Color_Type(0xFF, 0xCD, 0xD2),
    Color_Type(0xEF, 0x9A, 0x9A),
    Color_Type(0xE5, 0x73, 0x73),
    Color_Type(0xEF, 0x53, 0x50),
    Color_Type(0xF4, 0x43, 0x36),
    Color_Type(0xE5, 0x39, 0x35),
    Color_Type(0xD3, 0x2F, 0x2F),
    Color_Type(0xC6, 0x28, 0x28),
    Color_Type(0xB7, 0x1C, 0x1C)};
const Color_Type Color_Class::Pink[10] = {
    Color_Type(0xFC, 0xE4, 0xEC),
    Color_Type(0xF8, 0xBB, 0xD0),
    Color_Type(0xF4, 0x8F, 0xB1),
    Color_Type(0xF0, 0x62, 0x92),
    Color_Type(0xEC, 0x40, 0x7A),
    Color_Type(0xE9, 0x1E, 0x63),
    Color_Type(0xD8, 0x1B, 0x60),
    Color_Type(0xC7, 0x1B, 0x5B),
    Color_Type(0xAD, 0x14, 0x57),
    Color_Type(0x88, 0x0E, 0x4F)};
const Color_Type Color_Class::Purple[10] = {
    Color_Type(0xF3, 0xE5, 0xF5),
    Color_Type(0xE1, 0xBE, 0xE7),
    Color_Type(0xCE, 0x93, 0xD8),
    Color_Type(0xBA, 0x68, 0xC8),
    Color_Type(0xAB, 0x47, 0xBC),
    Color_Type(0x9C, 0x27, 0xB0),
    Color_Type(0x8E, 0x24, 0xAA),
    Color_Type(0x7B, 0x1F, 0xA2),
    Color_Type(0x6A, 0x1B, 0x9A),
    Color_Type(0x4A, 0x14, 0x8C)};
const Color_Type Color_Class::Deep_Purple[10] = {
    Color_Type(0xED, 0xE7, 0xF6),
    Color_Type(0xD1, 0xC4, 0xE9),
    Color_Type(0xB3, 0x9D, 0xDB),
    Color_Type(0x95, 0x75, 0xCD),
    Color_Type(0x7E, 0x57, 0xC2),
    Color_Type(0x67, 0x3A, 0xB7),
    Color_Type(0x5E, 0x35, 0xB1),
    Color_Type(0x51, 0x2D, 0xA8),
    Color_Type(0x45, 0x27, 0xA0),
    Color_Type(0x31, 0x1B, 0x92)};
const Color_Type Color_Class::Indigo[10] = {
    Color_Type(0xE8, 0xEA, 0xF6),
    Color_Type(0xC5, 0xCA, 0xE9),
    Color_Type(0x9F, 0xA8, 0xDA),
    Color_Type(0x79, 0x86, 0xCB),
    Color_Type(0x5C, 0x6B, 0xC0),
    Color_Type(0x3F, 0x51, 0xB5),
    Color_Type(0x39, 0x4F, 0xB1),
    Color_Type(0x30, 0x47, 0xA1),
    Color_Type(0x28, 0x3F, 0x91),
    Color_Type(0x1A, 0x23, 0x7E)};
const Color_Type Color_Class::Blue[10] = {
    Color_Type(0xE3, 0xF2, 0xFD),
    Color_Type(0xBB, 0xDE, 0xFB),
    Color_Type(0x90, 0xCA, 0xF9),
    Color_Type(0x64, 0xB5, 0xF6),
    Color_Type(0x42, 0xA5, 0xF5),
    Color_Type(0x21, 0x96, 0xF3),
    Color_Type(0x1E, 0x88, 0xE5),
    Color_Type(0x19, 0x76, 0xD2),
    Color_Type(0x15, 0x65, 0xC0),
    Color_Type(0x0D, 0x47, 0xA1)};
const Color_Type Color_Class::Light_Blue[10] = {
    Color_Type(0xE1, 0xF5, 0xFE),
    Color_Type(0xB3, 0xE5, 0xFC),
    Color_Type(0x81, 0xD4, 0xFA),
    Color_Type(0x4F, 0xC3, 0xF7),
    Color_Type(0x29, 0xB6, 0xF6),
    Color_Type(0x03, 0xA9, 0xF4),
    Color_Type(0x3, 0x9B, 0xE5),
    Color_Type(0x02, 0x88, 0xD1),
    Color_Type(0x02, 0x77, 0xBD),
    Color_Type(0x01, 0x57, 0x9B)};
const Color_Type Color_Class::Cyan[10] = {
    Color_Type(0xE0, 0xF7, 0xFA),
    Color_Type(0xB2, 0xEB, 0xF2),
    Color_Type(0x80, 0xDE, 0xEA),
    Color_Type(0x4D, 0xD0, 0xE1),
    Color_Type(0x26, 0xC6, 0xDA),
    Color_Type(0x00, 0xBC, 0xD4),
    Color_Type(0x00, 0xAC, 0xC1),
    Color_Type(0x00, 0x97, 0xA7),
    Color_Type(0x00, 0x83, 0x8F),
    Color_Type(0x00, 0x60, 0x64)};
const Color_Type Color_Class::Teal[10] = {
    Color_Type(0xE0, 0xF2, 0xF1),
    Color_Type(0xB2, 0xDF, 0xDB),
    Color_Type(0x80, 0xCB, 0xC4),
    Color_Type(0x4D, 0xB6, 0xAC),
    Color_Type(0x26, 0xA6, 0x9A),
    Color_Type(0x00, 0x96, 0x88),
    Color_Type(0x00, 0x89, 0x7B),
    Color_Type(0x00, 0x79, 0x6B),
    Color_Type(0x00, 0x69, 0x5C),
    Color_Type(0x00, 0x4D, 0x40)};
const Color_Type Color_Class::Green[10] = {
    Color_Type(0xE8, 0xF5, 0xE9),
    Color_Type(0xC8, 0xE6, 0xC9),
    Color_Type(0xA5, 0xD6, 0xA7),
    Color_Type(0x81, 0xC7, 0x84),
    Color_Type(0x66, 0xBB, 0x6A),
    Color_Type(0x4C, 0xAF, 0x50),
    Color_Type(0x43, 0xA0, 0x47),
    Color_Type(0x38, 0x8E, 0x3C),
    Color_Type(0x2E, 0x7D, 0x32),
    Color_Type(0x1B, 0x5E, 0x20)};
const Color_Type Color_Class::Light_Green[10] = {
    Color_Type(0xF1, 0xF8, 0xE9),
    Color_Type(0xDC, 0xED, 0xC8),
    Color_Type(0xC5, 0xE1, 0xA5),
    Color_Type(0xAE, 0xD5, 0x81),
    Color_Type(0x9C, 0xCC, 0x65),
    Color_Type(0x8B, 0xC3, 0x4A),
    Color_Type(0x7C, 0xB3, 0x42),
    Color_Type(0x68, 0x9F, 0x38),
    Color_Type(0x55, 0x8B, 0x2F),
    Color_Type(0x33, 0x69, 0x1E)};
const Color_Type Color_Class::Lime[10] = {
    Color_Type(0xF9, 0xFB, 0xE7),
    Color_Type(0xF0, 0xF4, 0xC3),
    Color_Type(0xE6, 0xEE, 0x9C),
    Color_Type(0xDC, 0xE7, 0x75),
    Color_Type(0xD4, 0xE1, 0x57),
    Color_Type(0xCD, 0xDC, 0x39),
    Color_Type(0xC0, 0xCA, 0x33),
    Color_Type(0xAF, 0xB4, 0x2B),
    Color_Type(0x9E, 0x9D, 0x24),
    Color_Type(0x82, 0x77, 0x17)};
const Color_Type Color_Class::Yellow[10] = {
    Color_Type(0xFF, 0xFD, 0xE7),
    Color_Type(0xFF, 0xF9, 0xC4),
    Color_Type(0xFF, 0xF5, 0x9D),
    Color_Type(0xFF, 0xF1, 0x76),
    Color_Type(0xFF, 0xEE, 0x58),
    Color_Type(0xFF, 0xEB, 0x3B),
    Color_Type(0xFD, 0xD8, 0x35),
    Color_Type(0xFB, 0xC0, 0x2D),
    Color_Type(0xF9, 0xA8, 0x25),
    Color_Type(0xF5, 0x7F, 0x17)};
const Color_Type Color_Class::Amber[10] = {
    Color_Type(0xFF, 0xF8, 0xE1),
    Color_Type(0xFF, 0xEC, 0xB3),
    Color_Type(0xFF, 0xE0, 0x82),
    Color_Type(0xFF, 0xD5, 0x4F),
    Color_Type(0xFF, 0xCA, 0x28),
    Color_Type(0xFF, 0xC1, 0x07),
    Color_Type(0xFF, 0xB3, 0x00),
    Color_Type(0xFF, 0xA0, 0x00),
    Color_Type(0xFF, 0x8F, 0x00),
    Color_Type(0xFF, 0x6F, 0x00)};
const Color_Type Color_Class::Orange[10] = {
    Color_Type(0xFF, 0xF3, 0xE0),
    Color_Type(0xFF, 0xE0, 0xB2),
    Color_Type(0xFF, 0xCC, 0x80),
    Color_Type(0xFF, 0xB7, 0x4D),
    Color_Type(0xFF, 0xA7, 0x26),
    Color_Type(0xFF, 0x98, 0x00),
    Color_Type(0xFB, 0x8C, 0x00),
    Color_Type(0xF5, 0x7C, 0x00),
    Color_Type(0xEF, 0x6C, 0x00),
    Color_Type(0xE6, 0x51, 0x00)};
const Color_Type Color_Class::Deep_Orange[10] = {
    Color_Type(0xFB, 0xE9, 0xE7),
    Color_Type(0xFF, 0xCC, 0xBC),
    Color_Type(0xFF, 0xAB, 0x91),
    Color_Type(0xFF, 0x8A, 0x65),
    Color_Type(0xFF, 0x70, 0x43),
    Color_Type(0xFF, 0x57, 0x22),
    Color_Type(0xF4, 0x51, 0x1E),
    Color_Type(0xE6, 0x4A, 0x19),
    Color_Type(0xD8, 0x43, 0x15),
    Color_Type(0xBF, 0x36, 0x0C)};
const Color_Type Color_Class::Brown[10] = {
    Color_Type(0xEF, 0xEB, 0xE9),
    Color_Type(0xD7, 0xCC, 0xC8),
    Color_Type(0xBC, 0xAA, 0xA4),
    Color_Type(0xA1, 0x88, 0x7F),
    Color_Type(0x8D, 0x6E, 0x63),
    Color_Type(0x79, 0x55, 0x48),
    Color_Type(0x6D, 0x4C, 0x41),
    Color_Type(0x5D, 0x40, 0x37),
    Color_Type(0x4E, 0x34, 0x2E),
    Color_Type(0x3E, 0x27, 0x23)};
const Color_Type Color_Class::Grey[10] = {
    Color_Type(0xFA, 0xFA, 0xFA),
    Color_Type(0xF5, 0xF5, 0xF5),
    Color_Type(0xEE, 0xEE, 0xEE),
    Color_Type(0xE0, 0xE0, 0xE0),
    Color_Type(0xBD, 0xBD, 0xBD),
    Color_Type(0x9E, 0x9E, 0x9E),
    Color_Type(0x75, 0x75, 0x75),
    Color_Type(0x61, 0x61, 0x61),
    Color_Type(0x42, 0x42, 0x42),
    Color_Type(0x21, 0x21, 0x21)};
const Color_Type Color_Class::Blue_Grey[10] = {
    Color_Type(0xEC, 0xEF, 0xF1),
    Color_Type(0xCF, 0xD8, 0xDC),
    Color_Type(0xB0, 0xBE, 0xC5),
    Color_Type(0x90, 0xA4, 0xAE),
    Color_Type(0x78, 0x90, 0x9C),
    Color_Type(0x60, 0x7D, 0x8B),
    Color_Type(0x54, 0x6E, 0x7A),
    Color_Type(0x45, 0x5A, 0x64),
    Color_Type(0x37, 0x47, 0x4F),
    Color_Type(0x26, 0x32, 0x38)};

const Color_Type Color_Class::Xila_Red(0xe00000);
const Color_Type Color_Class::Xila_Green(0x80c020);
const Color_Type Color_Class::Xila_Blue(0x20a0a0);
const Color_Type Color_Class::Xila_Yellow(0xffb000);

// - Constructors.

Color_Class::Color_Class()
{
}

Color_Class::Color_Class(lv_color_t LVGL_Color)
{
    Set_LVGL_Color(LVGL_Color);
}

Color_Class::Color_Class(uint8_t Red, uint8_t Green, uint8_t Blue, bool HSV)
{
    if (HSV)
    {
        Set_HSV(Red, Green, Blue);
    }
    else
    {
        Set_RGB(Red, Green, Blue);
    }
}

Color_Class::Color_Class(uint32_t Hex, bool Hex_3)
{
    Set_RGB(Hex, Hex_3);
}

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Color_Filter_Descriptor_Class::Set_Callback(Callback_Type Callback)
{
    Graphics.Take_Semaphore_Auto();
    lv_color_filter_dsc_init(Get_Pointer(), Callback);
}

void Color_Class::Change_Lightness(Opacity_Type Opacity)
{
    Graphics.Take_Semaphore_Auto();
    LVGL_Color = lv_color_change_lightness(LVGL_Color, static_cast<lv_opa_t>(Opacity));
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Color_Class::Set_LVGL_Color(lv_color_t LVGL_Color)
{
    this->LVGL_Color = LVGL_Color;
}

void Color_Class::Set_RGB(uint8_t Red, uint8_t Green, uint8_t Blue)
{
    Graphics.Take_Semaphore_Auto();
    LVGL_Color = lv_color_make(Red, Green, Blue);
}

void Color_Class::Set_RGB(uint32_t Hex, bool Hex_3)
{
    Graphics.Take_Semaphore_Auto();
    if (Hex_3)
    {
        LVGL_Color = lv_color_hex3(Hex);
    }
    else
    {
        LVGL_Color = lv_color_hex(Hex);
    }
}

void Color_Class::Set_HSV(uint16_t Hue, uint8_t Saturation, uint8_t Value)
{
    Graphics.Take_Semaphore_Auto();
    LVGL_Color = lv_color_hsv_to_rgb(Hue, Saturation, Value);
}

void Color_Class::Set_To_Black()
{
    Graphics.Take_Semaphore_Auto();
    LVGL_Color = lv_color_black();
}

void Color_Class::Set_To_White()
{
    Graphics.Take_Semaphore_Auto();
    LVGL_Color = lv_color_white();
}

void Color_Class::Set_Darker(Opacity_Type Opacity)
{
    Graphics.Take_Semaphore_Auto();
    LVGL_Color = lv_color_darken(LVGL_Color, static_cast<lv_opa_t>(Opacity));
}

void Color_Class::Set_Lighter(Opacity_Type Opacity)
{
    Graphics.Take_Semaphore_Auto();
    LVGL_Color = lv_color_lighten(LVGL_Color, static_cast<lv_opa_t>(Opacity));
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

lv_color_filter_dsc_t *Color_Filter_Descriptor_Class::Get_Pointer()
{
    return &LVGL_Color_Filter_Descriptor;
}

uint8_t Color_Class::Get_Brightness() const
{
    Graphics.Take_Semaphore_Auto();
    return lv_color_brightness(LVGL_Color);
}

lv_color_t Color_Class::Get_LVGL_Color() const
{
    return LVGL_Color;
}

lv_color_hsv_t Color_Class::Get_LVGL_HSV_Color() const
{
    Graphics.Take_Semaphore_Auto();
    return lv_color_to_hsv(LVGL_Color);
}

void Color_Class::Get_HSV(uint16_t &Hue, uint8_t &Saturation, uint8_t &Value) const
{
    Graphics.Take_Semaphore_Auto();
    lv_color_hsv_t HSV_Color = lv_color_to_hsv(LVGL_Color);
    Hue = HSV_Color.h;
    Saturation = HSV_Color.s;
    Value = HSV_Color.v;
}

uint8_t Color_Class::Get_RGB_1_Bit() const
{
    Graphics.Take_Semaphore_Auto();
    return lv_color_to1(LVGL_Color);
}

uint8_t Color_Class::Get_RGB_8_Bits() const
{
    Graphics.Take_Semaphore_Auto();
    return lv_color_to8(LVGL_Color);
}

uint16_t Color_Class::Get_RGB_16_Bits() const
{
    Graphics.Take_Semaphore_Auto();
    return lv_color_to16(LVGL_Color);
}

uint32_t Color_Class::Get_RGB_32_Bits() const
{
    Graphics.Take_Semaphore_Auto();
    return lv_color_to32(LVGL_Color);
}

// - Operators.

Color_Type::operator uint32_t() const
{
    return Get_RGB_32_Bits();
}