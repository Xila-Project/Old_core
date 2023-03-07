///
/// @file WT32-SC01-Plus.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief 
/// @version 0.1.0
/// @date 02-02-2023
///
/// @copyright Copyright (c) 2023
///

#ifdef Xila_Display_Hardware_Wireless_Tag_WT32_SC01_Plus

// - Constants

#define Display_Horizontal_Definition   480
#define Display_Vertical_Definition     320

// - Include header
#include "Core/Display/Display.hpp"

// - Include external library
#define LGFX_USE_V1
#include "LovyanGFX.hpp"

using namespace Xila_Namespace;

class WT32_SC01_Plus_Driver_Class : public lgfx::LGFX_Device {
  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Bus_Parallel8 _bus_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Touch_FT5x06 _touch_instance;

public:
  WT32_SC01_Plus_Driver_Class(void) {
    {
      auto cfg = _bus_instance.config();
      cfg.freq_write = 40000000;
      cfg.pin_wr = 47;
      cfg.pin_rd = -1;
      cfg.pin_rs = 0;
      cfg.pin_d0 = 9;
      cfg.pin_d1 = 46;
      cfg.pin_d2 = 3;
      cfg.pin_d3 = 8;
      cfg.pin_d4 = 18;
      cfg.pin_d5 = 17;
      cfg.pin_d6 = 16;
      cfg.pin_d7 = 15;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _panel_instance.config();
      cfg.pin_cs = -1;
      cfg.pin_rst = 4;
      cfg.pin_busy = -1;
      cfg.memory_width = 320;
      cfg.memory_height = 480;
      cfg.panel_width = 320;
      cfg.panel_height = 480;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = true;
      cfg.invert = true;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = true;

      _panel_instance.config(cfg);
    }

    {
      auto cfg = _light_instance.config();
      cfg.pin_bl = 45;
      cfg.invert = false;
      cfg.freq = 44100;
      cfg.pwm_channel = 7;

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);
    }

    {
      auto cfg = _touch_instance.config();
      cfg.i2c_port = 1;
      cfg.i2c_addr = 0x38;
      cfg.pin_sda = 6;
      cfg.pin_scl = 5;
      cfg.freq = 400000;
      cfg.x_min = 0;
      cfg.x_max = 320;
      cfg.y_min = 0;
      cfg.y_max = 480;

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance);
    }

    setPanel(&_panel_instance);
  }
} Driver;

Result_Type Display_Class::Initialize()
{
    if (!Driver.init())
    {
        return Result_Type::Error;
    }

    if (Driver.width() < Driver.height())
    {
        Driver.setRotation(Driver.getRotation() ^ 1);
    }

    //Driver.setTextSize((std::max(Driver.width(), Driver.height()) + 255) >> 8);
//
    //// Calibration
    //if (Driver.touch())
    //{
    //    if (Driver.width() < Driver.height())
    //    {
    //        Driver.setRotation(Driver.getRotation() ^ 1);
    //    }
    //    // 画面に案内文章を描画します。
    //    Driver.setTextDatum(textdatum_t::middle_center);
    //    Driver.drawString("touch the arrow marker.", Driver.width() >> 1, Driver.height() >> 1);
    //    Driver.setTextDatum(textdatum_t::top_left);
//
    //    // タッチを使用する場合、キャリブレーションを行います。画面の四隅に表示される矢印の先端を順にタッチしてください。
    //    std::uint16_t fg = TFT_WHITE;
    //    std::uint16_t bg = TFT_BLACK;
    //    if (Driver.isEPD())
    //    {
    //        std::swap(fg, bg);
    //    }
    //    Driver.calibrateTouch(nullptr, fg, bg, std::max(Driver.width(), Driver.height()) >> 3);
    //}
//
    return Result_Type::Success;
}

void Display_Class::Sleep()
{
    Driver.sleep();
}

void Display_Class::Wake_Up()
{
    Driver.wakeup();
}

void Display_Class::Set_Brightness(uint8_t Brightness)
{
    Driver.setBrightness(Brightness);
    this->Brightness = Brightness;
}

uint8_t Display_Class::Get_Brightness()
{
    return Brightness;
}

void Display_Class::Output_Flush(lv_disp_drv_t *Display_Driver_Interface, const lv_area_t *Area, lv_color_t *Buffer)
{
    static uint32_t Width, Height;

    Width = (Area->x2 - Area->x1 + 1);
    Height = (Area->y2 - Area->y1 + 1);

    Driver.startWrite();
    Driver.setAddrWindow(Area->x1, Area->y1, Width, Height);
    // tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    Driver.writePixels((lgfx::rgb565_t *)&Buffer->full, Width * Height);
    Driver.endWrite();

    lv_disp_flush_ready(Display_Driver_Interface);
}

uint16_t Display_Class::Get_Horizontal_Definition()
{
    return Driver.width();
}

uint16_t Display_Class::Get_Vertical_Definition()
{
    return Driver.height();
}

void Display_Class::Input_Read(lv_indev_drv_t *Input_Device_Driver_Interface, lv_indev_data_t *Data)
{
    static int32_t Input_X, Input_Y;

    if (Driver.getTouch(&Input_X, &Input_Y))
    {
        Data->state = LV_INDEV_STATE_PR;
        /*Set the coordinates*/
        Data->point.x = Input_X;
        Data->point.y = Input_Y;
    }
    else
    {
        Data->state = LV_INDEV_STATE_REL;
    }
}

void Display_Class::Calibrate()
{
    Driver.setTextSize((std::max(Driver.width(), Driver.height()) + 255) >> 8);

    // Calibration
    if (Driver.touch())
    {
        if (Driver.width() < Driver.height())
        {
            Driver.setRotation(Driver.getRotation() ^ 1);
        }
        // 画面に案内文章を描画します。
        Driver.setTextDatum(textdatum_t::middle_center);
        Driver.drawString("Touch the arrow marker.", Driver.width() >> 1, Driver.height() >> 1);
        Driver.setTextDatum(textdatum_t::top_left);

        // タッチを使用する場合、キャリブレーションを行います。画面の四隅に表示される矢印の先端を順にタッチしてください。
        std::uint16_t fg = TFT_WHITE;
        std::uint16_t bg = TFT_BLACK;
        if (Driver.isEPD())
        {
            std::swap(fg, bg);
        }
        Driver.calibrateTouch(nullptr, fg, bg, std::max(Driver.width(), Driver.height()) >> 3);
    }
}

#endif