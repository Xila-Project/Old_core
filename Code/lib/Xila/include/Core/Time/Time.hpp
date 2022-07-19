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

class Time_Class {

    //==============================================================================//

    ///
    /// @brief
    ///
    class Time_Class
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
        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

};

#ifndef TIME_HPP_INCLUDED
#define TIME_HPP_INCLUDED

inline uint32_t Xila_Class::Time_Class::Milliseconds() const
{
  return (uint32_t)(esp_timer_get_time() / 1000ULL);
}

inline int64_t Xila_Class::Time_Class::Microseconds() const
{
  return esp_timer_get_time();
}

#endif