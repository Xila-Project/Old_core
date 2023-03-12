#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include "Xila.hpp"
#include "unity.h"

class Unit_Test_Class : public Xila_Class::Software
{
    private:

    static Xila_Class::Task_Function Main_Task(void*);

    static Unit_Test_Class* Instance_Pointer;

    public:

        Unit_Test_Class();
        ~Unit_Test_Class();

        static Xila_Class::Software* Load();
        static void Startup_Function();
        
        

        void Run();

        void Software();
        void Software_Handle();
        void Account();
        void Clipboard();
        void Dialog();
        void Display();
        void Drive();
        void Flash();
        void GPIO();
        void Keyboard();
        void Mathematics();
        void Memory();
        void Power();
        void Software_Management();
        void Sound();
        void System();
        void Task();
        void Time();
        void WiFi();

        
};

extern Unit_Test_Class Unit_Test;

#endif