#ifndef TEXT_EDITOR_HPP_INCLUDED
#define TEXT_EDITOR_HPP_INCLUDED

#include "Xila.hpp"

class Text_Editor_Class : public Xila_Class::Software
{
protected:
    static Text_Editor_Class *Instance_Pointer;

    File File_To_Edit;

    uint8_t Mode;

    uint32_t Offset;

    static void Main_Task(void *);

    void Open_File(File File_To_Open);

    void Refresh_Interface();

    void Print_Line();

    void Scan();

    void Set_Variable(Xila_Class::Adress, uint8_t, const void *);

public:
    Text_Editor_Class();
    ~Text_Editor_Class();

    enum Mode
    {
        Windows = 0x0D,
        Unix,
        MacOS,
        Undefined
    };

    enum Image
    {
        Icon_32 = Xila.Display.Text_Editor_Images
    };

    static Xila_Class::Software *Load();
};

Xila_Class::Software_Handle Text_Editor_Handle("Text Editor", Text_Editor_Class::Icon_32, Text_Editor_Class::Load);

#endif