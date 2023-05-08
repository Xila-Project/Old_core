/// @file QRCode.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 23-03-2023
///
/// @copyright Copyright (c) 2023
///

#if LV_USE_QRCODE != 0

#include "Core/Graphics/QRCode.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type& Class = lv_qrcode_class;

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
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_qrcode_create(Parent_Object, nullptr, 0);
    }
}

void QRCode_Class::Create(Object_Type Parent_Object, const void *Data, Size_Type Length, Coordinate_Type Size, Color_Type Dark_Color, Color_Type Light_Color)
{
    if (Parent_Object)
    {
        this->Create(Parent_Object);

        if (Size != 0)
            this->Set_Size(Size);

        this->Set_Dark_Color(Dark_Color);

        this->Set_Light_Color(Light_Color);

        if (Data != nullptr && Length != 0)
            this->Update(Data, Length);
    }
}

void QRCode_Class::Update(const void* Data, Size_Type Length)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_qrcode_update(this->LVGL_Object_Pointer);
}

// - - Setters

void QRCode_Class::Set_Size(Coordinate_Type Size)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_qrcode_set_size(this->LVGL_Object_Pointer, Size);
}

void QRCode_Class::Set_Dark_Color(Color_Type Color)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_qrcode_set_dark_color(this->LVGL_Object_Pointer, Color);
}

void QRCode_Class::Set_Light_Color(Color_Type Color)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_qrcode_set_light_color(this->LVGL_Object_Pointer, Color);
}

#endif // LV_USE_QRCODE != 0