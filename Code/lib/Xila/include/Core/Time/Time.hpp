///
/// @file Time.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 29-03-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Time_Hpp_Included
#define Time_Hpp_Included

#include "../Module.hpp"

// -- Time library
#include "time.h"

namespace Xila_Namespace
{
    class Time_Class : public Module_Class
    {
    public:
        // -- Methods
        tm Get_Time();
        void Synchronize();

        uint32_t Get_Cycle_Count();
        uint32_t Milliseconds() const;
        int64_t Microseconds() const;

        // -- Time constructor / destructor

        Time_Class();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

    protected:
        // -- Attributes

        ///
        /// @brief GMT offset in seconds.
        ///
        int32_t GMT_Offset;

        ///
        /// @brief Daylight offset in seconds.
        ///
        int16_t Daylight_Offset;

        ///
        /// @brief Current time structure.
        ///
        tm Current_Time;

        ///
        /// @brief Current unix time in seconds.
        ///
        time_t Now;

        ///
        /// @brief NTP server name.
        ///
        char NTP_Server[32];

        // -- Methods
        Result::Type Load_Registry();
        Result::Type Save_Registry();
    };
}

#endif