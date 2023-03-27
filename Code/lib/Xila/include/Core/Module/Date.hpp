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

        /// @brief Default constructor.
        Date_Class();

        /// @brief Constructor with parameters.
        /// @param Day Day of the date (1 - 31).
        /// @param Month Month of the date (1 - 12).
        /// @param Year Year of the date (0 - 65 535).
        Date_Class(uint8_t Day, uint8_t Month, uint16_t Year);

        /// @brief Copy constructor.
        Date_Class(const Date_Class &Date);

        // - - Setters

        /// @brief Set the date.
        /// @param Day Day of the date (1 - 31).
        /// @param Month Month of the date (1 - 12).
        /// @param Year Year of the date (0 - 65 535).
        void Set(uint8_t Day, uint8_t Month, uint16_t Year);

        /// @brief Set the day of the date.
        void Set_Day(uint8_t Day);

        /// @brief Set the month of the date.
        void Set_Month(uint8_t Month);

        /// @brief Set the year of the date.
        void Set_Year(uint16_t Year);

        // - - Getters

        /// @brief Get the day of the date.
        uint8_t Get_Day();

        /// @brief Get the month of the date.
        uint8_t Get_Month();

        /// @brief Get the year of the date.
        uint16_t Get_Year();

        bool Is_Valid();

        /// @brief Check if the date is valid.
        /// @param Day Day of the date (1 - 31).
        /// @param Month Month of the date (1 - 12).
        /// @param Year Year of the date (0 - 65 535).
        /// @return True if the date is valid, false otherwise.
        static bool Is_Valid(uint8_t Day, uint8_t Month, uint16_t Year);

        // - - Operators

        // - - - Comparison

        /// @brief Comparison operator.
        /// @param Date Date to compare.
        /// @return True if the dates are equal, false otherwise.
        bool operator==(const Date_Class &Date);

        /// @brief Comparison operator.
        /// @param Date Date to compare.
        /// @return True if the dates are not equal, false otherwise.
        bool operator!=(const Date_Class &Date);

        /// @brief More than operator.
        /// @param Date Date to compare.
        /// @return True if the date is more than the other, false otherwise.
        bool operator>(const Date_Class &Date);

        /// @brief Less than operator.
        /// @param Date Date to compare.
        /// @return True if the date is less than the other, false otherwise.
        bool operator<(const Date_Class &Date);

        /// @brief More than or equal operator.
        /// @param Date Date to compare.
        /// @return True if the date is more than or equal to the other, false otherwise.
        bool operator>=(const Date_Class &Date);

        /// @brief Less than or equal operator.
        /// @param Date Date to compare.
        /// @return True if the date is less than or equal to the other, false otherwise.
        bool operator<=(const Date_Class &Date);

        // - - - Arithmetic

        /// @brief Addition operator.
        /// @param Date Date to add.
        /// @return The sum of the dates.
        /// Date_Class operator+(const Date_Class &Date);

        /// @brief Substraction operator.
        /// @param Date Date to substract.
        /// @return The difference of the dates.
        /// Date_Class operator-(const Date_Class &Date);
        
        /// @brief Addition operator.
        /// @param Date Date to add.
        /// @return The sum of the dates.
        /// Date_Class operator+=(const Date_Class &Date);

        /// @brief Substraction operator.
        /// @param Date Date to substract.
        /// @return The difference of the dates.
        /// Date_Class operator-=(const Date_Class &Date);


    protected:
        // - Attributes
        Byte_Type Day, Month;
        Word_Type Year;
    } Date_Type;


};

#endif