/// @file File_Explorer.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 18-05-2023
///
/// @copyright Copyright (c) 2023

#include "Graphics/File_Explorer.hpp"
#include "Graphics/Graphics.hpp"
#include "Log/Log.hpp"
#include "Drive/Drive.hpp"

// - Namespaces

using namespace Xila_Namespace;
using namespace Graphics_Types;

// - Attributes

const Class_Type File_Explorer_Class::Class = {
    .base_class = &lv_obj_class,
    .constructor_cb = lv_obj_class.constructor_cb,
    .destructor_cb = lv_obj_class.destructor_cb,
    .event_cb = lv_obj_class.event_cb,
    .width_def = lv_obj_class.width_def,
    .height_def = lv_obj_class.height_def,
    .editable = lv_obj_class.editable,
    .group_def = lv_obj_class.group_def,
    .instance_size = sizeof(lv_obj_t),
};

// - Methods

// - - Constructors / Destructors

File_Explorer_Class::File_Explorer_Class() : Object_Class()
{
}

File_Explorer_Class::File_Explorer_Class(const Object_Class &Object_To_Copy)
{
    if (Object_To_Copy.Is_Valid() && Object_To_Copy.Get_User_Data() && Object_To_Copy.Is_Valid() && Set_Pointer(Object_To_Copy))
        Data = static_cast<Data_Type *>(Object_To_Copy.Get_User_Data());
}

// - - Manipulation

void File_Explorer_Class::Create(Object_Type Parent_Object)
{
    if (!Parent_Object.Is_Valid())
        return;

    {
        auto Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_obj_create(Parent_Object);

        if (!this->Get_Pointer())
            return;

        this->LVGL_Object_Pointer->class_p = &File_Explorer_Class::Class;

        this->Set_Flex_Flow(Flex_Flow_Type::Column_Wrap);
    }

    Data = new Data_Type;
    Set_User_Data(Data);
    Data->Path = "/";
    Data->Selection_State = false;
}

void File_Explorer_Class::Delete(bool Asynchronous)
{
    if (!this->Is_Valid())
        return;

    auto Semaphore = Graphics.Take_Semaphore_Auto();
    
    if (Asynchronous)
        lv_obj_del_async(this->Get_Pointer());
    else
        lv_obj_del(this->Get_Pointer());
    
    this->Clear_Pointer();
    delete Data;
    Data = NULL;
}

void File_Explorer_Class::Set_Path(const char *Path)
{
    if (!this->Is_Valid() || !Data)
        return;

    Data->Path = Path;
    Refresh();
}

const char *File_Explorer_Class::Get_Path()
{
    if (!this->Is_Valid() || !Data)
        return NULL;

    return (const char *)Data->Path;
}

void File_Explorer_Class::Refresh()
{

    if (!this->Is_Valid() || !Data)
        return;

    Drive_Types::File_Type Folder = Drive.Open(Data->Path);

    if ((!Folder) || (!Folder.Is_Directory()))
    {
        Data->Path = "/";
        Refresh();
        return;
    }

    const uint8_t Item_Count = Folder.Get_Items_Count();

    Graphics_Types::Checkbox_Type Checkbox;
    // - If there are not enough checkboxes, create more
    {
        while (this->Get_Children_Count() < Item_Count)
        {
            Checkbox.Create(*this);
            Checkbox.Set_Alignment(Alignment_Type::Out_Left_Middle);
            Checkbox.Add_Event(Event_Callback, Graphics_Types::Event_Code_Type::Clicked, this);
            Checkbox.Add_Event(Event_Callback, Graphics_Types::Event_Code_Type::Long_Pressed, this);
            Checkbox.Set_Style_Opacity(Opacity_Type::Transparent, LV_PART_INDICATOR);
            Checkbox.Clear_Pointer();
        }
    }

    Folder.Rewind_Directory();

    {
        Static_String_Type<32> Item_Name;
        Drive_Types::File_Type Item;

        const Size_Type Children_Count = this->Get_Children_Count();

        for (uint8_t i = 0; i < Children_Count; i++)
        {
            Item = Folder.Open_Next_File();

            if (!Item)
                break;

            Checkbox = this->Get_Child(i);
            Checkbox.Clear_Flag(Flag_Type::Hidden);

            if (Item.Is_Directory())
                Item_Name = LV_SYMBOL_DIRECTORY;
            else
                Item_Name = LV_SYMBOL_FILE;

            Item_Name += " ";
            Item_Name += Item.Get_Name();

            Checkbox.Set_Text((const char *)Item_Name);

            Checkbox.Clear_Pointer();
            Item.Close();
        }
    }

    Folder.Close();

    // - Hide remaining unused checkboxes instead of deleting them to avoid memory fragmentation.
    const Size_Type New_Children_Count = this->Get_Children_Count();
    for (uint8_t i = Item_Count; i < New_Children_Count; i++)
    {
        Checkbox = this->Get_Child(i);
        Checkbox.Add_Flag(Flag_Type::Hidden);
    }
}

void File_Explorer_Class::Go_Parent_Folder()
{
    Log_Verbose("Shell", "Going to parent folder.");

    if (!this->Is_Valid() || !Data)
        return;

    for (uint8_t i = Data->Path.Get_Length() - 1; i > 0; i--)
    {
        Log_Verbose("Shell", "Character: %s", (const char *)Data->Path);
        Log_Verbose("Shell", "Index: %d", i);

        if (Data->Path.Get_Character(i) == '/')
        {
            Data->Path.Set_Character(i, '\0');

            Log_Verbose("Shell", "New path: %s", (const char *)Data->Path);
            break;
        }
        else
        {
            Data->Path.Set_Character(i, '\0');
        }
    }

    Refresh();
}

void File_Explorer_Class::Event_Callback(lv_event_t *Event)
{
    static Object_Type Ignore_Clicked;

    using namespace Graphics_Types;

    auto Semaphore = Graphics.Take_Semaphore_Auto();

    File_Explorer_Type *File_Explorer = static_cast<File_Explorer_Type *>(lv_event_get_user_data(Event));

    if (!File_Explorer || !File_Explorer->Is_Valid() || !File_Explorer->Get_User_Data())
        return;

    Checkbox_Type Current_Target(lv_event_get_current_target(Event));

    if (!Current_Target.Is_Valid())
        return;

    Log_Verbose("File explo", "Code : %d", lv_event_get_code(Event));

    switch (lv_event_get_code(Event))
    {
    case LV_EVENT_CLICKED:
        if (Current_Target.Get_Parent() == *File_Explorer)
        {
            if (Current_Target == Ignore_Clicked)
            {
                Log_Trace();
                Ignore_Clicked.Clear_Pointer();
            }
            else
            {
                Log_Trace();
                Static_String_Type<256> New_Path = File_Explorer->Data->Path;

                if (New_Path != "/")
                    New_Path += "/";

                New_Path += &(Current_Target.Get_Text()[sizeof(LV_SYMBOL_DIRECTORY)]);

                // - Check the new path is valid and is a folder.
                Drive_Types::File_Type Item = Drive.Open(New_Path);
                if (!Item || !Item.Is_Directory())
                {
                    if (!Item.Is_Directory())
                        File_Explorer->Data->Focused_Name = &(Current_Target.Get_Text()[sizeof(LV_SYMBOL_DIRECTORY)]);
                    Item.Close();
                    return;
                }
                Item.Close();

                // - Update the path and refresh the file explorer.
                File_Explorer->Data->Path = New_Path;
                File_Explorer->Data->Focused_Name = "";
                if (File_Explorer->Get_Selection_State())
                {
                    File_Explorer->Clear_Selection();
                    File_Explorer->Set_Selection_State(false);
                }
                File_Explorer->Refresh();
            }
        }
        Log_Trace();
        break;
    case LV_EVENT_LONG_PRESSED:
        if (Current_Target.Get_Parent() == *File_Explorer)
        {
            Log_Verbose("File explorer", "Long pressed");
            if (!File_Explorer->Get_Selection_State())
                File_Explorer->Set_Selection_State(true);

            Current_Target.Add_State(State_Type::Checked);
            Ignore_Clicked = Current_Target;
        }
        Log_Trace();
        break;
    }

    File_Explorer->Send_Event(Event_Code_Type::Value_Changed);
}

bool File_Explorer_Class::Get_Selection_State()
{
    if (!this->Is_Valid() || !Data)
        return false;

    return Data->Selection_State;
}

void File_Explorer_Class::Set_Selection_State(bool Enabled)
{
    if (!this->Is_Valid() || !Data)
        return;

    if (Data->Selection_State == Enabled)
        return;

    Data->Selection_State = Enabled;

    const Size_Type Children_Count = this->Get_Children_Count();
    for (Size_Type i = 0; i < Children_Count; i++)
    {
        Graphics_Types::Object_Type Checkbox = this->Get_Child(i);
        if (!Enabled)
            Checkbox.Set_Style_Opacity(Opacity_Type::Transparent, LV_PART_INDICATOR);
        else
            Checkbox.Set_Style_Opacity(Opacity_Type::Cover, LV_PART_INDICATOR);
    }
}

void File_Explorer_Class::Clear_Selection()
{
    if (!this->Is_Valid() || !Data)
        return;

    const Size_Type Children_Count = this->Get_Children_Count();
    for (Size_Type i = 0; i < Children_Count; i++)
    {
        Checkbox_Type Checkbox = this->Get_Child(i);
        if (Checkbox)
            Checkbox.Clear_State(State_Type::Checked);
    }
}

Size_Type File_Explorer_Class::Get_Selected_Count()
{
    if (!this->Is_Valid() || !Data)
        return 0;

    if (!Get_Selection_State())
        return 0;

    const Size_Type Children_Count = this->Get_Children_Count();
    Size_Type Selected_Count = 0;

    for (Size_Type i = 0; i < Children_Count; i++)
    {
        Object_Type Checkbox = this->Get_Child(i);
        if (Checkbox.Has_State(State_Type::Checked))
            Selected_Count++;
    }
    return Selected_Count;
}

const char *File_Explorer_Class::Get_Selected_Name(Size_Type Index)
{
    if (!this->Is_Valid() || !Data)
        return nullptr;

    if (!Get_Selection_State())
        return nullptr;

    const Size_Type Children_Count = this->Get_Children_Count();
    Size_Type Selected_Count = 0;

    for (Size_Type i = 0; i < Children_Count; i++)
    {
        Checkbox_Type Checkbox = this->Get_Child(i);
        if (Checkbox && Checkbox.Has_State(State_Type::Checked))
        {
            if (Selected_Count == Index)
                return Checkbox.Get_Text();
            Selected_Count++;
        }
    }
    return NULL;
}

const char *File_Explorer_Class::Get_Focused_Name()
{
    if (!this->Is_Valid() || !Data)
        return nullptr;

    return Data->Focused_Name;
}
