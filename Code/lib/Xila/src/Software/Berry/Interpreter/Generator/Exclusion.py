Classes = ["Graphics_Types::Animation_Class", "Graphics_Types::Symbol_Class", "Canvas_Class", "Communication_Types::WiFi_Class"
]

def Is_Class_Excluded(Class):
    Class_Declaration_String = str(Class).replace(" ", "")

    for C in Classes:
        if C.replace(" ", "") in Class_Declaration_String:
            return True

    return False

Functions = [

# - Graphics
# - - Object
"void Xila_Namespace::Graphics_Types::Object_Class::Add_Event(lv_event_cb_t Event_Callback",
"void Xila_Namespace::Graphics_Types::Object_Class::Set_User_Data(void * User_Data)",
"void Xila_Namespace::Graphics_Types::Object_Class::Set_Style_Arc_Image_Source(void const * Image_Source, Xila_Namespace::Graphics_Types::Object_Class::Style_Selector_Type Style_Selector)",
"void Xila_Namespace::Graphics_Types::Object_Class::Set_Style_Background_Image_Source(void const * Image_Source, Xila_Namespace::Graphics_Types::Object_Class::Style_Selector_Type Style_Selector)",
# - - Table
"void Xila_Namespace::Graphics_Types::Table_Class::Get_Selected_Cell(uint16_t & Row, uint16_t & Column)", # Berry mapping does not support references (have to be done manually)
# - - Text Area
"void Xila_Namespace::Graphics_Types::Canvas_Class::Copy_Buffer(void const * Buffer_To_Copy, Xila_Namespace::Graphics_Types::Coordinate_Type X, Xila_Namespace::Graphics_Types::Coordinate_Type Y, Xila_Namespace::Graphics_Types::Coordinate_Type Width, Xila_Namespace::Graphics_Types::Coordinate_Type Height)",

"void Xila_Namespace::Graphics_Types::Canvas_Class::Draw_Image(Xila_Namespace::Graphics_Types::Coordinate_Type X, Xila_Namespace::Graphics_Types::Coordinate_Type Y, void const * Source, Xila_Namespace::Graphics_Types::Canvas_Class::Draw_Image_Descriptor_Type const * Draw_Image_Descriptor)",
"void Xila_Namespace::Graphics_Types::Canvas_Class::Set_Buffer(void * Buffer, Xila_Namespace::Graphics_Types::Coordinate_Type Width, Xila_Namespace::Graphics_Types::Coordinate_Type Height, Xila_Namespace::Graphics_Types::Image_Class::Color_Format_Type Color_Format)",
"void Xila_Namespace::Graphics_Types::Image_Class::Set_Source(void const * Source)",
"void Xila_Namespace::Graphics_Types::Style_Class::Set_Arc_Image_Source(void const * Image_Source)",
"void Xila_Namespace::Graphics_Types::Style_Class::Set_Background_Image_Source(void const * Image_Source)",
"void Xila_Namespace::Graphics_Types::Color_Filter_Descriptor_Class::Set_Callback(Xila_Namespace::Graphics_Types::Color_Filter_Descriptor_Class::Callback_Type Callback)",
"void Xila_Namespace::Graphics_Types::Color_Class::Get_HSV(uint16_t & Hue, uint8_t & Saturation, uint8_t & Value)",
"static bool Xila_Namespace::Graphics_Types::Animation_Class::Custom_Delete(void * Variable, Xila_Namespace::Graphics_Types::Execution_Callback_Type Execution_Callback)",
"static bool Xila_Namespace::Graphics_Types::Animation_Class::Delete(void * Variable, Xila_Namespace::Graphics_Types::Execution_Callback_Type Execution_Callback)",
"static Xila_Namespace::Graphics_Types::Animation_Class Xila_Namespace::Graphics_Types::Animation_Class::Get(void * Variable, Xila_Namespace::Graphics_Types::Execution_Callback_Type Execution_Callback)",
"static Xila_Namespace::Graphics_Types::Animation_Class Xila_Namespace::Graphics_Types::Animation_Class::Custom_Get(void * Variable, Xila_Namespace::Graphics_Types::Execution_Callback_Type Execution_Callback)",
"void Xila_Namespace::Graphics_Types::Animation_Class::Set_Execution_Callback(Xila_Namespace::Graphics_Types::Execution_Callback_Type Execution_Callback)",
"void Xila_Namespace::Graphics_Types::Animation_Class::Set_Get_Value_Callback(Xila_Namespace::Graphics_Types::Get_Value_Callback_Type Get_Value_Callback)",
"void Xila_Namespace::Graphics_Types::Animation_Class::Set_Path_Callback(Xila_Namespace::Graphics_Types::Path_Callback_Type Execution_Callback)",
"void Xila_Namespace::Graphics_Types::Animation_Class::Set_Ready_Callback(Xila_Namespace::Graphics_Types::Ready_Callback_Type Ready_Callback)",
"void Xila_Namespace::Graphics_Types::Animation_Class::Set_Start_Callback(Xila_Namespace::Graphics_Types::Start_Callback_Type Start_Callback)",
"void Xila_Namespace::Graphics_Types::Animation_Class::Set_User_Data(void * User_Data)",
"void Xila_Namespace::Graphics_Types::Animation_Class::Set_Variable(void * Variable)",
"Task_Start_Function",
"Set_Pointer(",
"Get_Pointer(",
"Has_Class(",
"Check_Class(",
"Get_Class(",
"Set_Style_Background_Gradient",
"Get_LVGL_Color(",
"Calendar_Class::Set_Highlighted_Dates(",
"Calendar_Class::Set_Days_Names(",
"Object_Class::Set_Style_Text_Font(",
"Object_Class::Get_Style_Color_Filter_Descriptor(",
"Object_Class::Set_Style_Transition(",
"Keyboard_Class::Get_Map_Array(",
"Line_Class::Set_Points(",
"Window_Class::Event_Callback(",
"Keyboard_Class::Set_Map(",
"Style_Class::Set_Text_Font(",
"Style_Class::Set_Transition(",
"Color_Class::Set_LVGL_Color(",
"Color_Class::Get_LVGL_HSV_Color()",
"Button_Matrix_Class::Set_Map(",
"Button_Matrix_Class::Set_Control_Map(",
"Button_Matrix_Class::Get_Map()",
"Button_Class::Create(Xila_Namespace::Graphics_Types::Object_Class Parent_Object, char const* Label_Text",
"Button_Class::Create(Object_Class Parent_Object, const char*Label_Text",
"Area_Class::Set(",
"Style_Class::Set_Background_Gradient(",
"Graphics_Class::Event_Handler(",
"Graphics_Class::Take_Semaphore_Auto(",
"Xila_Namespace::Graphics_Types::Object_Class const &Object_To_Copy",
"void Xila_Namespace::Graphics_Types::Label_Class::Create(Xila_Namespace::Graphics_Types::Object_Class Parent_Object, char const *Text",
"void Xila_Namespace::Pin_Class::Attach_Interrupt(uint8_t Pin, void (*)( void * ) Function_Pointer, void * Argument, Xila_Namespace::Pin_Types::Interrupt_Mode_Type Mode)",
"void Xila_Namespace::Clipboard_Class::Copy(void const * Data, Xila_Namespace::Size_Type Data_Size)",
"Xila_Namespace::Result_Type Xila_Namespace::Flash_Class::Partition_Read(esp_partition_t const *Partition, uint32_t Offset, uint32_t *Data, size_t Size)",
"Decoder_Class(audio_tools::AudioDecoder &Decoder)",
"Xila_Namespace::Sound_Types::Stream_Class::Stream_Class(audio_tools::AudioStream & Stream)",
"void Xila_Namespace::Communication_Types::HTTPS_Client_Class::Collect_Headers(char const * * Header_Keys, Xila_Namespace::Size_Type Header_Keys_Count)",
"static void Xila_Namespace::Graphics_Types::File_Explorer_Class::Event_Callback(lv_event_t * Event)"
]

def Is_Function_Excluded(Function):
    Function_Signature_String = str(Function).replace(" ", "")

    for F in Functions:
        if F.replace(" ", "") in Function_Signature_String:
            return True

    return False