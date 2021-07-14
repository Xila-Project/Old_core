#ifndef SIMON_HPP_INCLUDED
#define SIMON_HPP_INCLUDED

#include "Xila.hpp"

#define Maximum_Level 255
#define Minimum_Speed 120

#define Simon_Registry_Path Software_Directory_Path "/Simon/Registry.xrf"

class Simon_Class : public Xila_Class::Software
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

    void Sort_Scores();

    void Generate_Sequence();
    void Show_Sequence();

    void Reset();

    void Press(uint8_t);

    void Refresh_Interface();

    void Game_Over();
    void Win();



public:
    uint16_t Speed;
    uint8_t Current_Level[2];
    uint8_t Sequence[Maximum_Level];

    uint8_t Scores[8] = {0};

    static void Main_Task(void *);

    static Xila_Class::Software* Load();

    Simon_Class();
    ~Simon_Class();

    enum Images
    {
        Icon_32 = Xila.Display.Simon_Images

    };

    enum Pages
    {

    };
};

Xila_Class::Software_Handle Simon_Handle("Simon", Simon_Class::Icon_32, Simon_Class::Load);

#endif