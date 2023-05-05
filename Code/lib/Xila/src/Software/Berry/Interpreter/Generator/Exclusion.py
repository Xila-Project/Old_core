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
"void Xila_Namespace::Graphics_Types::Table_Class::Set_Cell_Value_Format(uint16_t Row, uint16_t Column, char const * Formated_Value, ...)" # Berry does not support variadic functions
]

def Is_Function_Excluded(Function):
    Function_Signature_String = str(Function)

    for F in Functions:
        if Function_Signature_String.startswith(F):
            return True

    return False