#ifndef SIMON_HPP_INCLUDED
#define SIMON_HPP_INCLUDED

#include "Xila.hpp"

#define MAXIMUM_LEVEL 256

#define Simon_Registry_Path Software_Directory_Path "SIMON/REGISTRY.XRF"

class Simon_Class : public Software_Class
{
private:
    
    enum Colors
    {
        Red,
        Blue,
        Green,
        Yellow
    };
    
    static Simon_Class *Instance_Pointer;

    void Load_Registry();
    void Save_Registry();

    void Show_Scores();

    void Generate_Sequence();
    void Show_Sequence();

    void Reset();

    void Press(uint8_t);

    void Sort_Scores();

    void Game_Over();
    void Win();

public:
    uint16_t Speed;
    uint8_t Current_Level[2];
    uint8_t Sequence[MAXIMUM_LEVEL];

    uint8_t Highest_Score[8];

    static void Main_Task(void *);

    static Software_Class* Load();

    Simon_Class();
    ~Simon_Class();

    enum Images
    {
        Icon_32 = Xila.Simon,

    };

    enum Pages
    {

    };
};

Software_Handle_Class Simon_Handle("Simon", Simon_Class::Icon_32, Simon_Class::Load);

#endif