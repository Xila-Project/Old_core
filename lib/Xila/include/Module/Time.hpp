/// @file Time.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 22-02-2023
///
/// @copyright Copyright (c) 2023

#ifndef Xila_Time_Hpp_Included
#define Xila_Time_Hpp_Included

#include "Base_Types.hpp"

namespace Xila_Namespace
{
    /// @brief Class for Time.
    typedef class Time_Class
    {
    public:
        // - Methods
        // - - Constructor / Destructor

        /// @brief Default constructor.
        Time_Class();

        /// @brief Constructor with parameters.
        /// @param Hours Hours of the time (0 - 23).
        /// @param Minutes Minutes of the time (0 - 59).
        /// @param Seconds Seconds of the time (0 - 59).
        /// @param Milliseconds Milliseconds of the time (0 - 999).
        Time_Class(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint16_t Milliseconds);

        // - - Setters

        /// @brief Set the time.
        /// @param Hours Hours of the time (0 - 23).
        /// @param Minutes Minutes of the time (0 - 59).
        /// @param Seconds Seconds of the time (0 - 59).
        /// @param Milliseconds Milliseconds of the time (0 - 999).
        void Set(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint16_t Milliseconds);

        /// @brief Set the hours.
        /// @param Hours Hours of the time (0 - 23).
        void Set_Hours(uint8_t Hours);

        /// @brief Set the minutes.
        /// @param Minutes Minutes of the time (0 - 59).
        void Set_Minutes(uint8_t Minutes);

        /// @brief Set the seconds.
        /// @param Seconds Seconds of the time (0 - 59).
        void Set_Seconds(uint8_t Seconds);

        /// @brief Set the milliseconds.
        /// @param Milliseconds Milliseconds of the time (0 - 999).
        void Set_Milliseconds(uint16_t Milliseconds);

        // - - Getters

        /// @brief Get the hours.
        /// @return `uint8_t` Hours of the time (0 - 23).
        uint8_t Get_Hours();

        /// @brief Get the minutes.
        /// @return `uint8_t` Minutes of the time (0 - 59).
        uint8_t Get_Minutes();

        /// @brief Get the seconds.
        /// @return `uint8_t` Seconds of the time (0 - 59).
        uint8_t Get_Seconds();

        /// @brief Get the milliseconds.
        /// @return `uint16_t` Milliseconds of the time (0 - 999).
        uint16_t Get_Milliseconds();

    protected:
        // - Attributes

        /// @brief Hours of the time (0 - 23).
        uint8_t Hours;

        /// @brief Minutes of the time (0 - 59).
        uint8_t Minutes;

        /// @brief Seconds of the time (0 - 59).
        uint8_t Seconds;

        /// @brief Milliseconds of the time (0 - 999).
        uint16_t Milliseconds;

    } Time_Type;

};

#endif