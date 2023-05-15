///
/// @file Graphics.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Graphics.hpp"
#include "Core/Display/Display.hpp"
#include "Core/Core.hpp"
#include "Core/Log/Log.hpp"

#include "lvgl.h"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

const char Symbol_Class::Audio[4] = LV_SYMBOL_AUDIO;
const char Symbol_Class::Video[4] = LV_SYMBOL_VIDEO;
const char Symbol_Class::List[4] = LV_SYMBOL_LIST;
const char Symbol_Class::Ok[4] = LV_SYMBOL_OK;
const char Symbol_Class::Close[4] = LV_SYMBOL_CLOSE;
const char Symbol_Class::Power[4] = LV_SYMBOL_POWER;
const char Symbol_Class::Settings[4] = LV_SYMBOL_SETTINGS;
const char Symbol_Class::Home[4] = LV_SYMBOL_HOME;
const char Symbol_Class::Download[4] = LV_SYMBOL_DOWNLOAD;
const char Symbol_Class::Drive[4] = LV_SYMBOL_DRIVE;
const char Symbol_Class::Refresh[4] = LV_SYMBOL_REFRESH;
const char Symbol_Class::Mute[4] = LV_SYMBOL_MUTE;
const char Symbol_Class::Volume_Medium[4] = LV_SYMBOL_VOLUME_MID;
const char Symbol_Class::Volume_Maximum[4] = LV_SYMBOL_VOLUME_MAX;
const char Symbol_Class::Image[4] = LV_SYMBOL_IMAGE;
const char Symbol_Class::Tint[4] = LV_SYMBOL_TINT;
const char Symbol_Class::Previous[4] = LV_SYMBOL_PREV;
const char Symbol_Class::Play[4] = LV_SYMBOL_PLAY;
const char Symbol_Class::Pause[4] = LV_SYMBOL_PAUSE;
const char Symbol_Class::Stop[4] = LV_SYMBOL_STOP;
const char Symbol_Class::Next[4] = LV_SYMBOL_NEXT;
const char Symbol_Class::Eject[4] = LV_SYMBOL_EJECT;
const char Symbol_Class::Left[4] = LV_SYMBOL_LEFT;
const char Symbol_Class::Right[4] = LV_SYMBOL_RIGHT;
const char Symbol_Class::Plus[4] = LV_SYMBOL_PLUS;
const char Symbol_Class::Minus[4] = LV_SYMBOL_MINUS;
const char Symbol_Class::Eye_Open[4] = LV_SYMBOL_EYE_OPEN;
const char Symbol_Class::Eye_Close[4] = LV_SYMBOL_EYE_CLOSE;
const char Symbol_Class::Warning[4] = LV_SYMBOL_WARNING;
const char Symbol_Class::Shuffle[4] = LV_SYMBOL_SHUFFLE;
const char Symbol_Class::Up[4] = LV_SYMBOL_UP;
const char Symbol_Class::Down[4] = LV_SYMBOL_DOWN;
const char Symbol_Class::Loop[4] = LV_SYMBOL_LOOP;
const char Symbol_Class::Directory[4] = LV_SYMBOL_DIRECTORY;
const char Symbol_Class::Upload[4] = LV_SYMBOL_UPLOAD;
const char Symbol_Class::Call[4] = LV_SYMBOL_CALL;
const char Symbol_Class::Cut[4] = LV_SYMBOL_CUT;


Graphics_Type Xila_Namespace::Graphics;

Graphics_Class::Graphics_Class() : Task(this)
{
}

Result_Type Graphics_Class::Start()
{
    lv_init();

    if (!lv_is_initialized())
        return Result_Type::Error;

    // - Set draw buffer
    lv_disp_draw_buf_init(&Draw_Buffer_Descriptor, Draw_Buffer, NULL, Display.Get_Horizontal_Definition() * 10);

    // - Set screen driver interface
    lv_disp_drv_init(&Screen_Driver_Interface);
    Screen_Driver_Interface.hor_res = Display.Get_Horizontal_Definition();
    Screen_Driver_Interface.ver_res = Display.Get_Vertical_Definition();
    Screen_Driver_Interface.flush_cb = Display_Class::Output_Flush;
    Screen_Driver_Interface.draw_buf = &Draw_Buffer_Descriptor;
    lv_disp_drv_register(&Screen_Driver_Interface);

    // - Set touch pad driver interface
    lv_indev_drv_init(&Input_Device_Driver_Interface);
    Input_Device_Driver_Interface.type = LV_INDEV_TYPE_POINTER;
    Input_Device_Driver_Interface.read_cb = Display_Class::Input_Read;
    lv_indev_drv_register(&Input_Device_Driver_Interface);

    // - Set file system driver

    // - Initialize semaphore

    if (Semaphore.Create(Semaphore_Type::Type_Type::Recursive_Mutex) != Result_Type::Success)
    {
        return Result_Type::Error;
    }

    // - Initialize the default theme

    {
        auto Semaphore = Take_Semaphore_Auto();
        Theme = lv_theme_default_get();
    }

    //   if (Load_Registry() != Result_Type::Success)
    //   {
    //       if (Create_Registry() != Result_Type::Success)
    //           return Result_Type::Error;
    //   }

    // - Create task
    Task.Create(Task_Start_Function, "Graphics task", 8 * 1024, this, Task_Priority_Type::System);

    return Result_Type::Success;
}

Result_Type Graphics_Class::Stop()
{

    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
#if LV_MEM_CUSTOM == 0
        lv_deinit();
#endif
    }

    Task.Delete();

    return Result_Type::Success;
}

void Graphics_Class::Task_Start_Function(void *Instance_Pointer)
{
    ((Graphics_Class *)Instance_Pointer)->Task_Function();
}

void Graphics_Class::Task_Function()
{
    while (true)
    {
        this->Take_Semaphore();
        lv_timer_handler();
        this->Give_Semaphore();
        lv_tick_inc(6);
        while (Instruction_Available())
            Execute_Instruction(Get_Instruction());

        Task.Delay(6);
    }
}

void Graphics_Class::Execute_Instruction(Instruction_Type Instruction)
{
    // TODO : Move this in shell instead
    if (Instruction.Get_Sender() == this)
    {
        switch (Instruction.Graphics.Get_Code())
        {
        case Event_Code_Type::Minimize:
        {

            Window_Type Window = Instruction.Graphics.Get_Target();
            if (Window.Is_Valid())
                Window.Set_State(Window_State_Type::Minimized);
            break;
        }
        case Event_Code_Type::Close:
        {
            Window_Type Window = Instruction.Graphics.Get_Target();
            if (Window.Is_Valid())
                Softwares.Close(const_cast<Softwares_Types::Software_Type *>(Window.Get_Owner_Software()));
            break;
        }
        }
    }
}

void Graphics_Class::Event_Handler(lv_event_t *Event)
{
    static Instruction_Type Instruction;
    Instruction.Set_Sender(&Graphics);

    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        Instruction.Set_Receiver((Module_Class *)lv_event_get_user_data(Event));
        Instruction.Graphics.Set_Code(static_cast<Event_Code_Type>(lv_event_get_code(Event)));
        Instruction.Graphics.Set_Target_Pointer(Object_Type(lv_event_get_target(Event)));
        Instruction.Graphics.Set_Current_Target_Pointer(Object_Type(lv_event_get_current_target(Event)));
    }

    Instruction.Get_Receiver()->Send_Instruction(Instruction);
}

const char *Graphics_Class::Get_Symbol(Symbol_Code_Type Symbol)
{
    switch (Symbol)
    {
    case Symbol_Code_Type::Audio:
        return Symbol_Type::Audio;
    case Symbol_Code_Type::Video:
        return Symbol_Type::Video;
    case Symbol_Code_Type::List:
        return Symbol_Type::List;
    case Symbol_Code_Type::Ok:
        return Symbol_Type::Ok;
    case Symbol_Code_Type::Close:
        return Symbol_Type::Close;
    case Symbol_Code_Type::Power:
        return Symbol_Type::Power;
    case Symbol_Code_Type::Settings:
        return Symbol_Type::Settings;
    case Symbol_Code_Type::Home:
        return Symbol_Type::Home;
    case Symbol_Code_Type::Download:
        return Symbol_Type::Download;
    case Symbol_Code_Type::Drive:
        return Symbol_Type::Drive;
    case Symbol_Code_Type::Refresh:
        return Symbol_Type::Refresh;
    case Symbol_Code_Type::Mute:
        return Symbol_Type::Mute;
    case Symbol_Code_Type::Volume_Medium:
        return Symbol_Type::Volume_Medium;
    case Symbol_Code_Type::Volume_Maximum:
        return Symbol_Type::Volume_Maximum;
    case Symbol_Code_Type::Image:
        return Symbol_Type::Image;
    case Symbol_Code_Type::Tint:
        return Symbol_Type::Tint;
    case Symbol_Code_Type::Previous:
        return Symbol_Type::Previous;
    case Symbol_Code_Type::Play:
        return Symbol_Type::Play;
    case Symbol_Code_Type::Pause:
        return Symbol_Type::Pause;
    case Symbol_Code_Type::Stop:
        return Symbol_Type::Stop;
    case Symbol_Code_Type::Next:
        return Symbol_Type::Next;
    case Symbol_Code_Type::Eject:
        return Symbol_Type::Eject;
    case Symbol_Code_Type::Left:
        return Symbol_Type::Left;
    case Symbol_Code_Type::Right:
        return Symbol_Type::Right;
    case Symbol_Code_Type::Plus:
        return Symbol_Type::Plus;
    case Symbol_Code_Type::Minus:
        return Symbol_Type::Minus;
    case Symbol_Code_Type::Eye_Open:
        return Symbol_Type::Eye_Open;
    case Symbol_Code_Type::Eye_Close:
        return Symbol_Type::Eye_Close;
    case Symbol_Code_Type::Warning:
        return Symbol_Type::Warning;
    case Symbol_Code_Type::Shuffle:
        return Symbol_Type::Shuffle;
    case Symbol_Code_Type::Up:
        return Symbol_Type::Up;
    case Symbol_Code_Type::Down:
        return Symbol_Type::Down;
    case Symbol_Code_Type::Loop:
        return Symbol_Type::Loop;
    case Symbol_Code_Type::Directory:
        return Symbol_Type::Directory;
    case Symbol_Code_Type::Upload:
        return Symbol_Type::Upload;
    case Symbol_Code_Type::Call:
        return Symbol_Type::Call;
    }
        return Symbol_Type::Cut;
}

Object_Type Graphics_Class::Get_Top_Layer()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return Object_Type(lv_layer_top());
}

Color_Type Graphics_Class::Get_Theme_Primary_Color()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return Color_Type(Theme->color_primary);
}

Color_Type Graphics_Class::Get_Theme_Secondary_Color()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return Color_Type(Theme->color_secondary);
}

bool Graphics_Class::Get_Theme_Dark_Mode()
{
    return (Theme->flags & 1) == 1;
}

void Graphics_Class::Set_Theme_Primary_Color(Color_Type Color)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    Theme = lv_theme_default_init(NULL, Color.Get_LVGL_Color(), Get_Theme_Secondary_Color().Get_LVGL_Color(), Get_Theme_Dark_Mode(), LV_FONT_DEFAULT);
}

void Graphics_Class::Set_Theme_Secondary_Color(Color_Type Color)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    Theme = lv_theme_default_init(NULL, Get_Theme_Primary_Color().Get_LVGL_Color(), Color.Get_LVGL_Color(), Get_Theme_Dark_Mode(), LV_FONT_DEFAULT);
}

void Graphics_Class::Set_Theme_Dark_Mode(bool Enabled)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    Theme = lv_theme_default_init(NULL, Get_Theme_Primary_Color().Get_LVGL_Color(), Get_Theme_Secondary_Color().Get_LVGL_Color(), Enabled, LV_FONT_DEFAULT);
}

Coordinate_Type Graphics_Class::Get_Percentage(Coordinate_Type Coordinate)
{
    return Percentage(Coordinate);
}

/*

// -- File system callbacks

void *Display_Class::File_System_Open(lv_fs_drv_t *Driver, const char *Path, lv_fs_mode_t Mode)
{
    File File_To_Open;
    if (Mode == LV_FS_MODE_WR)
    {
        File_To_Open = Drive.Open(Path, FILE_WRITE);
    }
    else
    {
        File_To_Open = Drive.Open(Path, FILE_WRITE);
    }

    if (!File_To_Open)
    {
        return NULL;
    }

    return File_To_Open;
}

static lv_fs_res_t Display_Class::File_System_Close(lv_fs_drv_t *Driver, void *File_Pointer)
{
    *(File *)File_Pointer.Close();
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
        File_To_Seek.Seek(Position, SeekSet);
        break;

    case LV_FS_SEEK_CUR:
        File_To_Seek.Seek(Position, SeekCur);
        break;

    case LV_FS_SEEK_END:
        File_To_Seek.Seek(Position, SeekEnd);
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
    File File_To_Open = Drive.Open(Path);
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
{ Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_FS_RES_NOT_IMP;
}

static lv_fs_res_t Display_Class::File_System_Close_Directory(lv_fs_drv_t *Driver, void *Directory_Pointer)
{
    File File_Pointer = *(File *)Directory_Pointer;
    File_Pointer.Close();
    return LV_FS_RES_OK;
}*/