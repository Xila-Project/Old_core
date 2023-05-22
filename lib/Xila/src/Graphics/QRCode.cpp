/// @file QRCode.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 23-03-2023
///
/// @copyright Copyright (c) 2023
///

#if LV_USE_QRCODE != 0

#include "Graphics/QRCode.hpp"
#include "Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Class = lv_qrcode_class;

// - Methods

// - - Constructor / destructor

QRCode_Class::QRCode_Class() : Object_Class()
{
}

QRCode_Class::QRCode_Class(const Object_Class &Object)
{
    this->Set_Pointer(Object);
}

QRCode_Class::~QRCode_Class()
{
}

// - - Manipulation

void QRCode_Class::Create(Object_Type Parent_Object)
{
    if (!Parent_Object)
        return;

    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    this->LVGL_Object_Pointer = lv_qrcode_create(Parent_Object, 32, Color_Type::Black.Get_LVGL_Color(), Color_Type::White.Get_LVGL_Color());
}

void QRCode_Class::Create(Object_Type Parent_Object, const void *Data, Size_Type Length, Coordinate_Type Size, Color_Type Dark_Color, Color_Type Light_Color)
{
    if (!Parent_Object)
        return;

    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    this->LVGL_Object_Pointer = lv_qrcode_create(Parent_Object, Size, Dark_Color.Get_LVGL_Color(), Light_Color.Get_LVGL_Color());

    if (Data && (Length != 0))
        this->Update(Data, Length);
}

void QRCode_Class::Update(const void *Data, Size_Type Length)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_qrcode_update(Get_Pointer(), Data, Length);
}

#endif // LV_USE_QRCODE != 0