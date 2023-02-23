///
/// @file Date.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 22-02-2023
///
/// @copyright Copyright (c) 2023
///

#ifndef Date_Hpp_Included
#define Date_Hpp_Included

#include "Base_Types.hpp"

namespace Xila_Namespace
{
    /// @brief Class for Date.
    typedef class Date_Class
    {
    public:
        // - Methods
        // - - Constructors / Destructors
        Date_Class();
        Date_Class(uint8_t Day, uint8_t Month, uint16_t Year);

        // - - Setters
        void Set(uint8_t Day, uint8_t Month, uint16_t Year);
        void Set_Day(uint8_t Day);
        void Set_Month(uint8_t Month);
        void Set_Year(uint16_t Year);

        // - - Getters
        uint8_t Get_Day();
        uint8_t Get_Month();
        uint16_t Get_Year();

    protected:
        // - Attributes
        uint8_t Day;
        uint8_t Month;
        uint16_t Year;
    } Date_Type;


};

#endif