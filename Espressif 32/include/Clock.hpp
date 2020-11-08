#ifndef CLOCK_HPP_INCLUDED
#define CLOCK_HPP_INCLUDEd

#include "GalaxOS.hpp"

class Clock_Class : public Software_Class
{
    private:

        static void Main_Task(void*);

        static Clock_Class* Instance_Pointer;

        const char Days[7][10] = {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"
        };

        const char Months[12][10]
        {
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
        };


    public:
        static Software_Class* Load();

        enum Picture
        {
            Clock_32 = 38
        };

        Clock_Class();
        ~Clock_Class();

};

Software_Handle_Class Clock_Handle("Clock", Clock_Class::Clock_32, Clock_Class::Load);

#endif