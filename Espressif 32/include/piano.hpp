#include "GalaxOS.hpp"

class Piano_Class : public Software_Class
{
private:

    static uint8_t Number_Instance;

    xTaskHandle Socket_Handle;

    uint16_t Socket_Method;

    void Play_Note(uint32_t Frequency, uint8_t Note);

public:
    Piano_Class();
    ~Piano_Class();

    uint8_t Get_Number_Instance();

    void Execute(uint16_t const& Socket_Method_To_Set);
    void Execute(char const& Socket_Method_Char1, char const& Socket_Method_Char2);
    
    friend void Piano_Socket(void *pvParameters);
};

void Piano_Socket(void *pvParameters);