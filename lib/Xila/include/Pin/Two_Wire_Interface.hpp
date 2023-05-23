/// @file Wire.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 12-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Wire_Hpp_Included
#define Wire_Hpp_Included

#include "../Module/Stream.hpp"
#include "../Module/Base_Types.hpp"
#include "Wire.h"

namespace Xila_Namespace
{
    namespace Pin_Types
    {
        typedef class Two_Wire_Class : public Xila_Namespace::Stream_Type
        {
        public:
            Two_Wire_Class() = default;

            /// @brief Begin the I2C communication.
            /// @param SDA_Pin SDA pin.
            /// @param SCL_Pin SCL pin.
            /// @param Frequency Frequency of the I2C communication.
            /// @param Slave_Address Slave address.
            /// @return Result_Type.
            Result_Type Begin(int8_t SDA_Pin = -1, int8_t SCL_Pin = -1, uint32_t Frequency = 0, int16_t Slave_Address = -1);
            
            /// @brief End the I2C communication.
            /// @return Result_Type.
            Result_Type End();


            /// @brief Begin a transmission to the slave.
            /// @param Address Slave address.
            void Begin_Transmission(uint16_t Address);

            /// @brief End a transmission to the slave.
            /// @param Send_Stop Send a stop bit.
            /// @return Result_Type.
            Result_Type End_Transmission(bool Send_Stop = true);

            /// @brief Request data from the slave.
            /// @param Address Address of the slave.
            /// @param Size Size of the data to request.
            /// @param Send_Stop Send a stop bit.
            /// @return Size_Type.
            Size_Type Request_From(uint16_t Address, Size_Type Size, bool Send_Stop = true);

            /// @brief Check available incoming data.
            /// @return Size_Type.
            int Available() override;

            /// @brief Peek the next byte.
            /// @return Byte_Type or -1 if no data is available.
            int Peek() override;

            /// @brief Read the next byte.
            /// @return Byte_Type or -1 if no data is available.
            int Read() override;

            /// @brief Read bytes.
            /// @param Buffer Buffer to store the data.
            /// @param Length Length of the buffer.
            /// @return Size_Type.
            Size_Type Read_Bytes(Byte_Type *Buffer, Size_Type Length) override;
         
            /// @brief Read a string.
            /// @param String String to store the data.
            /// @return String_Type.
            String_Type &Read_String(String_Type &String) override;

            /// @brief Flush the buffer.
            void Flush() override;

            /// @brief Write a byte.
            /// @param Data Byte to write.
            /// @return Size_Type.
            Size_Type Write(Byte_Type Data) override;
          
            /// @brief Write bytes.
            /// @param Data Bytes to write.
            /// @param Size Size of the data.
            /// @return Size_Type.
            Size_Type Write_Bytes(const Byte_Type *Data, Size_Type Size) override;

            /// @brief Same as Write_Bytes.
            Size_Type Slave_Write(const Byte_Type *Data, Size_Type Size);

            // - - Getters

            /// @brief Get the timeout.
            /// @return Timeout value in milliseconds.
            uint16_t Get_Timeout();

            /// @brief Get the clock frequency.
            /// @return Clock frequency in Hertz.
            uint32_t Get_Clock_Frequency();

            // - - Setters

            /// @brief Set the timeout.
            /// @param Timeout Timeout value in milliseconds.
            void Set_Timeout(uint16_t Timeout);

            /// @brief Set the clock frequency.
            /// @param Frequency Clock frequency in Hertz.
            void Set_Clock_Frequency(uint32_t Frequency);

            /// @brief Set the pins used for the I2C communication.
            /// @param SDA_Pin SDA pin.
            /// @param SCL_Pin SCL pin.
            /// @return Result_Type.
            Result_Type Set_Pins(int SDA_Pin, int SCL_Pin);

        protected:
            Two_Wire_Class(TwoWire &Wire);

            TwoWire &Wire;

            friend class Pin_Type;
        } Two_Wire_Type;

    }
}

#endif