///
/// @file Display.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

// -- Constructors

///
/// @brief Construct a new Xila_Class::Display_Class::Display_Class object
///
Display_Class::Display_Class()
    : Nextion_Class(),
      State(true),

{
    Baud_Rate = Default_Display_Baud_Rate;
}

///
/// @brief Destroy the Xila_Class::Display_Display_Class::Display_Class object
///
Display_Class::~Display_Class()
{
}

// -- Object's base class

uint16_t Display_Display_Class::Get_Horizontal_Definition()
{
    return Display_Horizontal_Definition;
}

uint16_t Display_Display_Class::Get_Vertical_Definition()
{
    return Display_Vertical_Definition;
}

// -- Load display driver

Result_Type Display_Class::Initialize_File_System()
{
    lv_fs_drv_init(&File_System_Driver);

    File_System_Driver.letter = '';
    File_System_Driver.open_cb = File_System_Open;
    File_System_Driver.close_cb = File_System_Close;
    File_System_Driver.read_cb = File_System_Read;
    File_System_Driver.write_cb = File_System_Write;
    File_System_Driver.seek_cb = File_System_Set_Position;
    File_System_Driver.tell_cb = File_System_Get_Position;

    File_System_Driver.dir_close_cb = File_System_Close_Directory;
    File_System_Driver.dir_read_cb = File_System_Directory_Read;
    File_System_Driver.dir_open_cb = File_System_Open_Directory;

    lv_fs_drv_register(&File_System_Driver);

    return Xila_Success;
}

///
/// @brief Load display registry
///
/// @return Xila_Class::Success or Xila_Class::Error
Result_Type Display_Class::Load_Registry()
{
    File Temporary_File = Xila.Drive.Open(Registry("Display"));
    DynamicJsonDocument Display_Registry(256);
    if (deserializeJson(Display_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        Log_Error("Failed to load display registry.");
        return Error;
    }
    Temporary_File.close();
    if (strcmp("Display", Display_Registry["Registry"] | "") != 0)
    {
        Log_Error("Failed to load display registry.");
        return Error;
    }
    Standby_Time = Display_Registry["Standby Time"] | Default_Display_Standby_Time;
    Receive_Pin = Display_Registry["Receive Pin"] | Default_Display_Receive_Pin;
    Transmit_Pin = Display_Registry["Transmit Pin"] | Default_Display_Transmit_Pin;
    Baud_Rate = Display_Registry["Baud Rate"] | Default_Display_Baud_Rate;
    Brightness = Display_Registry["Brightness"] | Default_Display_Brightness;
    return Success;
}

///
/// @brief Save display registry
///
/// @return Result_Type
Result_Type Display_Class::Save_Registry()
{
    File Temporary_File = Xila.Drive.Open(Registry("Display"), FILE_WRITE);
    DynamicJsonDocument Display_Registry(256);
    Display_Registry["Registry"] = "Display";
    Display_Registry["Brightness"] = Brightness;
    Display_Registry["Receive Pin"] = Receive_Pin;
    Display_Registry["Transmit Pin"] = Transmit_Pin;
    Display_Registry["Standby Time"] = Standby_Time;
    Display_Registry["Baud Rate"] = Baud_Rate;
    if (serializeJson(Display_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        Log_Error("Failed to save display registry.");
        return Error;
    }
    Temporary_File.close();
    return Success;
}

///
/// @brief Callback function for display incoming string data
///
/// @param Received_Data String received data
/// @param Size Size in bytes of received data
void Display_Class::Incoming_String_Data_From_Display(const char *Received_Data, uint8_t Size)
{
    while (Xila.Software_Management.Openned[0] == NULL)
    {
        Xila.Task.Delay(20);
    }
    switch (Received_Data[0])
    {
    case Xila.Display.Instruction:
        Xila.Software_Management.Openned[0]->Send_Instruction(Instruction(Received_Data[1], Received_Data[2]));
        break;
    case Xila.Display.Variable_String:
        Xila.Software_Management.Openned[0]->Set_Variable(Address(Received_Data[1], Received_Data[2]), Variable_String, Received_Data + 3);
        Xila.Display.Current_Address = '\0';
        break;
    case Xila.Display.Variable_Long:
        Xila.Display.Current_Address = Address(Received_Data[1], Received_Data[2]);
        break;
    default:
        // error handle
        break;
    }
}

///
/// @brief Callback function for display incoming numeric data
///
/// @param Received_Data Received numeric data from the display
void Display_Class::Incoming_Numeric_Data_From_Display(uint32_t Received_Data)
{
    if (Xila.Display.Current_Address != '\0')
    {
        Xila.Software_Management.Openned[0]->Set_Variable(Xila.Display.Current_Address, Xila.Display.Variable_Long, &Received_Data);
        Xila.Display.Current_Address = '\0';
    }
}

///
/// @brief Callback function for display incoming event
///
/// @param Event_Code Event code
void Display_Class::Incoming_Event_From_Display(uint8_t Event_Code)
{
    switch (Event_Code)
    {
    case Current_Page_Number:
        Xila.System.Refresh_Header();
        break;
    case Serial_Buffer_Overflow:
        break;
    case Auto_Entered_Sleep_Mode:
        Xila.Display.Set_State(false);
        break;
    case Auto_Wake_From_Sleep_Mode:
        Xila.Display.Set_State(true);
        Xila.System.Refresh_Header();
        break;
    default:
        break;
    }
}

// -- File system callbacks

void *Display_Class::File_System_Open(lv_fs_drv_t *Driver, const char *Path, lv_fs_mode_t Mode)
{
    File File_To_Open;
    if (Mode == LV_FS_MODE_WR)
    {
        File_To_Open = Xila.Drive.Open(Path, FILE_WRITE);
    }
    else
    {
        File_To_Open = Xila.Drive.Open(Path, FILE_WRITE);
    }

    if (!File_To_Open)
    {
        return NULL;
    }

    return File_To_Open;
}

static lv_fs_res_t Display_Class::File_System_Close(lv_fs_drv_t *Driver, void *File_Pointer)
{
    *(File *)File_Pointer.close();
    return LV_FS_RES_OK;
}

static lv_fs_res_t Display_Class::File_System_Read(lv_fs_drv_t *Driver, void *File_Pointer, void *Buffer, uint32_t Bytes_To_Read, uint32_t *Bytes_Read)
{
    File File_To_Read = *(File *)File_Pointer;

    if (!File_To_Read)
    {
        return LV_FS_RES_FS_ERR;
    }

    *Bytes_Read = File_To_Read.read((uint8_t *)Buffer, Bytes_To_Read);
    return LV_FS_RES_OK;
}

static lv_fs_res_t Display_Class::File_System_Write(lv_fs_drv_t *Driver, void *File_Pointer, const void *Buffer, uint32_t Bytes_To_Write, uint32_t *Bytes_Written)
{
    File File_To_Write = *(File *)File_Pointer;

    if (!File_To_Write)
    {
        return LV_FS_RES_FS_ERR;
    }

    *Bytes_Written = File_To_Write.write((uint8_t *)Buffer, Bytes_To_Write);
    return LV_FS_RES_OK;
}

static lv_fs_res_t Display_Class::File_System_Set_Position(lv_fs_drv_t *Driver, void *File_Pointer, uint32_t Position, lv_fs_whence_t Whence)
{
    File File_To_Seek = *(File *)File_Pointer;

    if (!File_To_Seek)
    {
        return LV_FS_RES_FS_ERR;
    }

    switch (Whence)
    {
    case LV_FS_SEEK_SET:
        File_To_Seek.seek(Position, SeekSet);
        break;

    case LV_FS_SEEK_CUR:
        File_To_Seek.seek(Position, SeekCur);
        break;

    case LV_FS_SEEK_END:
        File_To_Seek.seek(Position, SeekEnd);
        break;

    default:
        break;
    }

    return LV_FS_RES_OK;
}

static lv_fs_res_t Display_Class::File_System_Get_Position(lv_fs_drv_t *Driver, void *File_Pointer, uint32_t *Position)
{
    File File_To_Get_Position = *(File *)File_Pointer;

    if (!File_To_Get_Position)
    {
        return LV_FS_RES_FS_ERR;
    }

    *Position = File_To_Get_Position.position();
    return LV_FS_RES_OK;
}

static void *Display_Class::File_System_Open_Directory(lv_fs_drv_t *Driver, const char *Path)
{
    File File_To_Open = Xila.Drive.Open(Path);
    if (!File_To_Open)
    {
        return LV_FS_RES_FS_ERR;
    }
    else if (!File_To_Open.isDirectory())
    {
        return LV_FS_RES_NOT_EX;
    }
    return &File_To_Open;
}

static lv_fs_res_t Display_Class::File_System_Directory_Read(lv_fs_drv_t *Driver, void *Directory_Pointer, char *File_Name)
{
    return LV_FS_RES_NOT_IMP;
}

static lv_fs_res_t Display_Class::File_System_Close_Directory(lv_fs_drv_t *Driver, void *Directory_Pointer)
{
    File File_Pointer = *(File *)Directory_Pointer;
    File_Pointer.close();
    return LV_FS_RES_OK;
}

void Calibrate()
{
    tft.setTextSize((std::max(tft.width(), tft.height()) + 255) >> 8);

    // Calibration
    if (tft.touch())
    {
        if (tft.width() < tft.height())
        {
            tft.setRotation(tft.getRotation() ^ 1);
        }
        // 画面に案内文章を描画します。
        tft.setTextDatum(textdatum_t::middle_center);
        tft.drawString("touch the arrow marker.", tft.width() >> 1, tft.height() >> 1);
        tft.setTextDatum(textdatum_t::top_left);

        // タッチを使用する場合、キャリブレーションを行います。画面の四隅に表示される矢印の先端を順にタッチしてください。
        std::uint16_t fg = TFT_WHITE;
        std::uint16_t bg = TFT_BLACK;
        if (tft.isEPD())
        {
            std::swap(fg, bg);
        }
        tft.calibrateTouch(nullptr, fg, bg, std::max(tft.width(), tft.height()) >> 3);
    }
};

void Initialize()
{
    tft.init();
};

IRAM_ATTR void Flush(lv_disp_drv_t *Display_Driver_Interface, const lv_area_t *Area, lv_color_t *Buffer)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    // tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
    tft.endWrite();

    lv_disp_flush_ready(disp);
};

IRAM_ATTR void Touchpad_Read(lv_index_drv_t *Input_Device_Driver_Interface, lv_index_data_t *Data)
{
    if (tft.getTouch(&Touch_Pad_X, &Touch_Pad_Y))
    {
        data->state = LV_INDEV_STATE_PR;
        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
};