#include "Arduino.h"


class Piano_Class
{
private:

    static uint8_t Number_Instance;

    xTaskHandle Socket_Handle;

    uint16_t Socket_Method;

    void Play_Note();

public:
    Piano_Class();
    ~Piano_Class();

    uint8_t Get_Number_Instance();

    void Execute(uint16_t const& Socket_Method_To_Set);
    void Execute(char const& Socket_Method_Char1, char const& Socket_Method_Char2);
    
    xTaskHandle Socket_Handle;

};

void Piano_Socket(void *pvParameters);