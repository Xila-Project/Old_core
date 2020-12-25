#ifndef TEXT_EDITOR_HPP_INCLUDED
#define TEXT_EDITOR_HPP_INCLUDED

#include "Xila.hpp"

class Text_Editor_Class : public Software_Class
{
protected:
    static Text_Editor_Class *Instance_Pointer;

    static void Main_Task(void *);

    File File_To_Edit;

    uint8_t Mode;

    uint32_t Offset;

    void Open_File(File File_To_Open);

    void Refresh_Text();

    void Print_Line();

    void Scan();

    void Set_Variable(const void*, uint8_t, uint8_t, uint8_t = 0);

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

    enum Picture
    {
        Text_Editor_32 = 49
    };

    static Software_Class *Load();
};

Software_Handle_Class Text_Editor_Handle("Text Editor", Text_Editor_Class::Text_Editor_32, Text_Editor_Class::Load);

#endif