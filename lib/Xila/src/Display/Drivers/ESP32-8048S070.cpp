/// @file ESP32-8048S070.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief This code is sourced from https://github.com/wegi1/ESP32-8048S070-7INCH-LCD/tree/main repository.
/// @version 0.1.0
/// @date 13-07-2023
///
/// @copyright Copyright (c) 2023

#ifdef Xila_Display_Hardware_ESP32_8048S070

#define Display_Horizontal_Definition 800
#define Display_Vertical_Definition 480

#define Display_Blacklight_Pin 2

#include "Display/Display.hpp"

#include <Arduino_GFX_Library.h>
#include <TAMC_GT911.h>

using namespace Xila_Namespace;

TAMC_GT911 Touch = TAMC_GT911(19, 20, -1, 38, max(800, 0), max(480, 0));

Arduino_ESP32RGBPanel* rgbpanel = new Arduino_ESP32RGBPanel(
    41 /* DE */, 40 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
    14 /* R0 */, 21 /* R1 */, 47 /* R2 */, 48 /* R3 */, 45 /* R4 */,
    9 /* G0 */, 46 /* G1 */, 3 /* G2 */, 8 /* G3 */, 16 /* G4 */, 1 /* G5 */,
    15 /* B0 */, 7 /* B1 */, 6 /* B2 */, 5 /* B3 */, 4 /* B4 */,
    0 /* hsync_polarity */, 180 /* hsync_front_porch */, 30 /* hsync_pulse_width */, 16 /* hsync_back_porch */,
    0 /* vsync_polarity */, 12 /* vsync_front_porch */, 13 /* vsync_pulse_width */, 10 /* vsync_back_porch */, 1, 16000000);


 //   0 /* hsync_polarity */, 180 /* hsync_front_porch */, 30 /* hsync_pulse_width */, 16 /* hsync_back_porch */,
 //   0 /* vsync_polarity */, 12 /* vsync_front_porch */, 13 /* vsync_pulse_width */, 10 /* vsync_back_porch */, 1, 16000000);


Arduino_RGB_Display* Gfx = new Arduino_RGB_Display(
    800 /* width */, 480 /* height */, rgbpanel);

Result_Type Display_Class::Initialize()
{
    // - Display

    Gfx->begin();

    // - Blacklight

    
    ledcSetup(0, 300, 8);
    ledcAttachPin(Display_Blacklight_Pin, 0);
    ledcWrite(0, 255); /* Screen brightness can be modified by adjusting this parameter. (0-255) */

    // - Touch

    pinMode(38, OUTPUT);
    digitalWrite(38, LOW);
    Task_Type::Delay_Static(10);
    digitalWrite(38, HIGH);
    Task_Type::Delay_Static(10);

    Touch.begin();
    Touch.setRotation(ROTATION_NORMAL);

    return Result_Type::Success;
}

void Display_Class::Sleep()
{
    ledcWrite(0, 0);
}

void Display_Class::Wake_Up()
{
    ledcWrite(0, 255);
}

void Display_Class::Set_Brightness(uint8_t Brightness)
{
    ledcWrite(0, Brightness);

    this->Brightness = Brightness;
}

uint8_t Display_Class::Get_Brightness()
{
    return Brightness;
}

void Display_Class::Output_Flush(lv_disp_drv_t *Display_Driver_Interface, const lv_area_t *Area, lv_color_t *Buffer)
{
    uint32_t Width = (Area->x2 - Area->x1 + 1);
    uint32_t Height = (Area->y2 - Area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
    Gfx->draw16bitBeRGBBitmap(Area->x1, Area->y1, (uint16_t *)&Buffer->full, Width, Height);
#else
    Gfx->draw16bitRGBBitmap(Area->x1, Area->y1, (uint16_t *)&Buffer->full, Width, Height);
#endif

    lv_disp_flush_ready(Display_Driver_Interface);
}

uint16_t Display_Class::Get_Horizontal_Definition()
{
    return Display_Horizontal_Definition;
}

uint16_t Display_Class::Get_Vertical_Definition()
{
    return Display_Vertical_Definition;
}

void Display_Class::Input_Read(lv_indev_drv_t *Input_Device_Driver_Interface, lv_indev_data_t *Data)
{
    Touch.read();
    if (Touch.isTouched)
    {
        Data->state = LV_INDEV_STATE_PR;

        Data->point.x = map(Touch.points[0].x, 800, 0, 0, Display_Horizontal_Definition - 1);
        Data->point.y = map(Touch.points[0].y, 480, 0, 0, Display_Vertical_Definition - 1);
    }
    else
    {
        Data->state = LV_INDEV_STATE_REL;
    }
}

void Display_Class::Calibrate()
{
    //    Driver.setTextSize((std::max(Driver.width(), Driver.height()) + 255) >> 8);
    //
    //    // Calibration
    //    if (Driver.touch())
    //    {
    //        if (Driver.width() < Driver.height())
    //        {
    //            Driver.setRotation(Driver.getRotation() ^ 1);
    //        }
    //        // 画面に案内文章を描画します。
    //        Driver.setTextDatum(textdatum_t::middle_center);
    //        Driver.drawString("Touch the arrow marker.", Driver.width() >> 1, Driver.height() >> 1);
    //        Driver.setTextDatum(textdatum_t::top_left);
    //
    //        // タッチを使用する場合、キャリブレーションを行います。画面の四隅に表示される矢印の先端を順にタッチしてください。
    //        std::uint16_t fg = TFT_WHITE;
    //        std::uint16_t bg = TFT_BLACK;
    //        if (Driver.isEPD())
    //        {
    //            std::swap(fg, bg);
    //        }
    //        Driver.calibrateTouch(nullptr, fg, bg, std::max(Driver.width(), Driver.height()) >> 3);
    //    }
}

#endif