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

#define Class Xila_Class::Display_Class

// -- Constructors

///
/// @brief Construct a new Xila_Class::Display_Class::Display_Class object
///
Class::Display_Class()
    : Nextion_Class(),
      State(true),
      Brightness(Default_Display_Brightness),
      Receive_Pin(Default_Display_Receive_Pin),
      Standby_Time(Default_Display_Standby_Time),
      Transmit_Pin(Default_Display_Transmit_Pin),
      Current_Address(0)
{
    Baud_Rate = Default_Display_Baud_Rate;
}

///
/// @brief Destroy the Xila_Class::Display_Class::Display_Class object
///
Class::~Display_Class()
{
}

// -- Object's base class

Class::Object_Class::Object_Class(Object_Class &Parent_Object)
{
    this.LVGL_Object_Pointer = lv_obj_create(Parent_Object.Get_Pointer());
}

Class::Object_Class::~Object_Class()
{
    Delete();
}

LVGL_Object_Type Class::Object_Class::operator=(const Object_Class Parent_Object){
    Parent_Object.set}

IRAM_ATTR void Class::Object_Class::Event_Handler(Class::Event_Type Event)
{

    Xila.Software_Management.Send_Instruction(Xila.Software_Management.);
}

Class::Arc_Class::Arc_Class(Object_Class &Parent_Object)
{
    this.LVGL_Object_Pointer = lv_arc_create(Parent_Object.Get_Pointer());
}

Class::Bar_Class::Bar_Class(Object_Class Parent_Object);
{
    this.LVGL_Object_Pointer = lv_bar_create(Parent_Object.Get_Pointer());
}

Class::Button_Class::Button_Class(Object_Class &Parent_Object)
{
    this.LVGL_Object_Pointer = lv_btn_create(Parent_Object.Get_Pointer());
}

Class::Button_Matrix_Class::Button_Matrix_Class(Object_Class &Parent_Object)
{
    LVGL_Object_Type = lv_btnmatrix_create(Parent_Object.Get_Pointer());
}

Class::Canvas_Class::Canvas_Class(Object_Class &Parent_Object)
{
    LVGL_Object_Pointer = lv_canvas_create(Parent_Object.Get_Pointer());
}

Class::Checkbox_Class::Checkbox_Class(Object_Class &Parent_Object)
{
    LVGL_Object_Pointer = lv_checkbox_create(Parent_Object.Get_Pointer());
}


Class::Dropdown_List::Dropdown_List(Object_Class &Parent_Object)
{
    LVGL_Object_Pointer = lv_dropdown_create(Parent_Object.Get_Pointer());
}

Class::Image_Class::Image_Class(Object_Class& Parent_Object)
{
    LVGL_Object_Pointer = lv_image_create(Parent_Object.Get_Pointer());
}

Class::Label_Class::Label_Class(Object_Class& Parent_Object)
{
    LVGL_Object_Pointer = lv_label_create(Parent_Object.Get_Pointer());
}

Class::Line_Class::Line_Class(Object_Class& Parent_Object)
{
    LVGL_Object_Pointer = lv_line_create(Parent_Object.Get_Pointer());
}

Class::Roller_Class::Roller_Class(Object_Class& Parent_Object)
{
    LVGL_Object_Pointer = lv_roller_create(Parent_Object.Get_Pointer());
}

Class::Slider_Class::Slider_Class(Object_Class &Parent_Object)
{
    LVGL_Object_Pointer = lv_slider_create(Parent_Object.Get_Pointer());
}

Class::Switch_Class::Switch_Class(Object_Class &Parent_Object)
{
    LVGL_Object_Pointer = lv_switch_create(Parent_Object.Get_Pointer());
}

Class::Table_Class::Table_Class(const Object_Class &Parent_Object)
{
    LVGL_Object_Pointer = lv_table_create(Parent_Object.Get_Pointer());
}

Class::Text_Area_Class::Text_Area_Class(const Object_Class& Parent_Object)
{
    LVGL_Object_Pointer = lv_textarea_create(Parent_Object.Get_Pointer());
}

Object_Type Class::Load()
{
    Object_Type Window = Create();

    Type
}

Class::Tabs_Class::Tabs_Class(Parent_Object &Parent_Object)
{
    LVGL_Object_Pointer = lv_tabview_create(Parent_Object.Get_Pointer());
}

Xila_Class::Event Class::Compile_Page(File Page_File)
{
    // Stream& input;

    if (!Page_File)
    {
        return Error;
    }

    DynamicJsonDocument Page_File_Registry(Page_File.size());

    if (deserializeJson(Page_File_Registry, Page_File) != DeserializationError::Ok)
    {
        return Error;
    }

    for (JsonObject Object : doc["Objects"].as<JsonArray>())
    {

        int Object_Type = Object["Type"];         // 0, 1
        const char *Object_Name = Object["Name"]; // "Button 1", "Button 2"

        const char *Parent = Object["Parent"]; // "Page 1", "Page 2"

        int Object_Position_Align = Object["Position"]["Align"];
        int Object_Position_X = Object["Position"]["X"];
        int Object_Position_Y = Object["Position"]["Y"];

        // Size
        int Object_Width = Object["Size"]["Width"];   // 0, 1
        int Object_Height = Object["Size"]["Height"]; // 0, 1

        // Style
        uint16_t Background_Color = Object["Style"]["Background Color"];
        uint16_t Text_Color = Object["Style"]["Text Color"];
        uint16_t

            const char *Object_Instructions_Click = Object["Instructions"]["Click"]; // "BUT1", "BUT2"
        const char *Object_Instructions_Hover = Object["Instructions"]["Hover"];     // "BUT'", "BUT'"
    }
}

///
/// @brief
///
/// @return Xila_Class::Event
Xila_Class::Event Class::Load_Page(File Page_File, Object *Object_Array, uint16_t Object_Array_Size)
{
    if (!Page_File)
    {
        return Error;
    }

    if (Compile_Page(Page_File) != Error))
        {
            return Error;
        }

    return Success;
}

// -- Load display driver

Xila_Class::Event Class::Initialize_File_System()
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
Xila_Class::Event Class::Load_Registry()
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
/// @return Xila_Class::Event
Xila_Class::Event Class::Save_Registry()
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
void Class::Incoming_String_Data_From_Display(const char *Received_Data, uint8_t Size)
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
void Class::Incoming_Numeric_Data_From_Display(uint32_t Received_Data)
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
void Class::Incoming_Event_From_Display(uint8_t Event_Code)
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

void * Class::File_System_Open(lv_fs_drv_t * Driver, const char * Path, lv_fs_mode_t Mode)
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

static lv_fs_res_t Class::File_System_Close(lv_fs_drv_t * Driver, void * File_Pointer)
{
    *(File*)File_Pointer.close();
    return LV_FS_RES_OK;
}

static lv_fs_res_t Class::File_System_Read(lv_fs_drv_t * Driver, void * File_Pointer, void * Buffer, uint32_t Bytes_To_Read, uint32_t * Bytes_Read)
{
    File File_To_Read = *(File*)File_Pointer;
    
    if (!File_To_Read)
    {
        return LV_FS_RES_FS_ERR;
    }

    *Bytes_Read = File_To_Read.read((uint8_t*)Buffer, Bytes_To_Read);
    return LV_FS_RES_OK;
}

static lv_fs_res_t Class::File_System_Write(lv_fs_drv_t * Driver, void * File_Pointer, const void * Buffer, uint32_t Bytes_To_Write, uint32_t * Bytes_Written)
{
    File File_To_Write = *(File*)File_Pointer;
    
    if (!File_To_Write)
    {
        return LV_FS_RES_FS_ERR;
    }

    *Bytes_Written = File_To_Write.write((uint8_t*)Buffer, Bytes_To_Write);
    return LV_FS_RES_OK;
}

static lv_fs_res_t Class::File_System_Set_Position(lv_fs_drv_t * Driver, void * File_Pointer, uint32_t Position, lv_fs_whence_t Whence)
{
    File File_To_Seek = *(File*)File_Pointer;

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

static lv_fs_res_t Class::File_System_Get_Position(lv_fs_drv_t * Driver, void * File_Pointer, uint32_t  * Position)
{
    File File_To_Get_Position = *(File*)File_Pointer;

    if (!File_To_Get_Position)
    {
        return LV_FS_RES_FS_ERR;
    }

    *Position = File_To_Get_Position.position();
    return LV_FS_RES_OK;
}

static void* Class::File_System_Open_Directory(lv_fs_drv_t * Driver, const char * Path)
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

static lv_fs_res_t Class::File_System_Directory_Read(lv_fs_drv_t * Driver, void * Directory_Pointer, char * File_Name)
{
    return LV_FS_RES_NOT_IMP;
}

static lv_fs_res_t Class::File_System_Close_Directory(lv_fs_drv_t * Driver, void * Directory_Pointer)
{
    File File_Pointer = *(File*)Directory_Pointer;
    File_Pointer.close();
    return LV_FS_RES_OK;
}