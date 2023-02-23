///
 /// @file Time.hpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 22-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

 #ifndef Time_Hpp_Included
#define Time_Hpp_Included

#include "Base_Types.hpp"

namespace Xila_Namespace
{
    /// @brief Class for Time.
    typedef class Time_Class
    {
    public:
        // - Methods
        // - - Constructor / Destructor
        Time_Class();
        Time_Class(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint16_t Milliseconds);

        // - - Setters
        void Set(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint16_t Milliseconds);
        void Set_Hours(uint8_t Hours);
        void Set_Minutes(uint8_t Minutes);
        void Set_Seconds(uint8_t Seconds);
        void Set_Milliseconds(uint16_t Milliseconds);

        // - - Getters
        uint8_t Get_Hours();
        uint8_t Get_Minutes();
        uint8_t Get_Seconds();
        uint16_t Get_Milliseconds();
    
    protected:
        // - Attributes

        uint8_t Hours;
        uint8_t Minutes;
        uint8_t Seconds;
        uint16_t Milliseconds;

    } Time_Type;


};

#endif