#include "Arduino.h"


class Piano_Class
{
private:

public:
    Piano_Class();
    ~Piano_Class();

    uint8_t Get_Number_Instance();

    void Set_Socket_Method(uint16_t const& Socket_Method_To_Set);
    void Set_Socket_Method(char const& Socket_Method_Char1, char const& Socket_Method_Char2);
    
    xTaskHandle Socket_Handle;

};

void iGOS_Socket(void *pvParameters);