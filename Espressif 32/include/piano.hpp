#include "Xila.hpp"

class Piano_Class : public Software_Class
{
private:

    static Piano_Class* Instance_Pointer;

    int16_t Offset;
    uint8_t Current_Note;
    uint32_t Duration;
    bool MIDI_Output;

    const uint16_t Note_Frequency[24] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988};

    void Play_Note(uint8_t);

public:

    Piano_Class();
    ~Piano_Class();

    static Software_Class* Load();

    enum Picture
    {
        Piano_32 = 5,
    };
    
    static void Main_Task(void *pvParameters);
};

Software_Handle_Class Piano_Handle("Piano", Piano_Class::Piano_32, Piano_Class::Load);