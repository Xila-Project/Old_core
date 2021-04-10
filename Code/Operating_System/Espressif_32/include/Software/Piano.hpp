///
 /// @file Piano.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief Piano software header file.
 /// @version 0.1.0
 /// @date 08-04-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 

#include "Xila.hpp"

#define Piano_File(name) Software_Directory_Path "/Internet/" name

class Piano_Class : public Software_Class
{
private:

    static Piano_Class* Instance_Pointer;

    int16_t Offset;
    uint8_t Note_ID;
    uint16_t Current_Note;
    uint32_t Duration;
    bool MIDI_Output;

    const uint16_t Note_Frequency[24] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988};

    char Temporary_String[8];

    void Press_Key(uint8_t);
    void Release_Key();
    void Refresh_Interface();

    void Load_Registry();
    void Save_Registry();

public:

    Piano_Class();
    ~Piano_Class();

    static Software_Class* Load();

    enum Image
    {
        Icon_32 = Xila.Display.Piano_Images,
    };
    
    static void Main_Task(void *pvParameters);
};

Software_Handle_Class Piano_Handle("Piano", Piano_Class::Icon_32, Piano_Class::Load);