/// @file UART.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 12-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Serial_Hpp_Included
#define Serial_Hpp_Included

#include "Arduino.h"
#include "../Module/Stream.hpp"

namespace Xila_Namespace
{
    namespace Pin_Types
    {
        /// @brief Serial configuration type.
        enum class Serial_Configuration_Type
        {
            Data_5_Bits = SERIAL_5N1,                         ///< 5 bits data, no parity, 1 stop bit.
            Data_6_Bits = SERIAL_6N1,                         ///< 6 bits data, no parity, 1 stop bit.
            Data_7_Bits = SERIAL_7N1,                         ///< 7 bits data, no parity, 1 stop bit.
            Data_8_Bits = SERIAL_8N1,                         ///< 8 bits data, no parity, 1 stop bit.
            Data_5_Bits_2_Stop_Bits = SERIAL_5N2,             ///< 5 bits data, no parity, 2 stop bits.
            Data_6_Bits_2_Stop_Bits = SERIAL_6N2,             ///< 6 bits data, no parity, 2 stop bits.
            Data_7_Bits_2_Stop_Bits = SERIAL_7N2,             ///< 7 bits data, no parity, 2 stop bits.
            Data_8_Bits_2_Stop_Bits = SERIAL_8N2,             ///< 8 bits data, no parity, 2 stop bits.
            Data_5_Bits_Even_Parity = SERIAL_5E1,             ///< 5 bits data, even parity, 1 stop bit.
            Data_6_Bits_Even_Parity = SERIAL_6E1,             ///< 6 bits data, even parity, 1 stop bit.
            Data_7_Bits_Even_Parity = SERIAL_7E1,             ///< 7 bits data, even parity, 1 stop bit.
            Data_8_Bits_Even_Parity = SERIAL_8E1,             ///< 8 bits data, even parity, 1 stop bit.
            Data_5_Bits_Even_Parity_2_Stop_Bits = SERIAL_5E2, ///< 5 bits data, even parity, 2 stop bits.
            Data_6_Bits_Even_Parity_2_Stop_Bits = SERIAL_6E2, ///< 6 bits data, even parity, 2 stop bits.
            Data_7_Bits_Even_Parity_2_Stop_Bits = SERIAL_7E2, ///< 7 bits data, even parity, 2 stop bits.
            Data_8_Bits_Even_Parity_2_Stop_Bits = SERIAL_8E2, ///< 8 bits data, even parity, 2 stop bits.
            Data_5_Bits_Odd_Parity = SERIAL_5O1,              ///< 5 bits data, odd parity, 1 stop bit.
            Data_6_Bits_Odd_Parity = SERIAL_6O1,              ///< 6 bits data, odd parity, 1 stop bit.
            Data_7_Bits_Odd_Parity = SERIAL_7O1,              ///< 7 bits data, odd parity, 1 stop bit.
            Data_8_Bits_Odd_Parity = SERIAL_8O1,              ///< 8 bits data, odd parity, 1 stop bit.
            Data_5_Bits_Odd_Parity_2_Stop_Bits = SERIAL_5O2,  ///< 5 bits data, odd parity, 2 stop bits.
            Data_6_Bits_Odd_Parity_2_Stop_Bits = SERIAL_6O2,  ///< 6 bits data, odd parity, 2 stop bits.
            Data_7_Bits_Odd_Parity_2_Stop_Bits = SERIAL_7O2,  ///< 7 bits data, odd parity, 2 stop bits.
            Data_8_Bits_Odd_Parity_2_Stop_Bits = SERIAL_8O2,  ///< 8 bits data, odd parity, 2 stop bits.
        };

        /// @brief Serial mode type.
        enum class Serial_Mode_Type : uint8_t
        {
            Regular = MODE_UART,                                  ///< Regular asynchronous serial communication.
            RS485_Half_Duplex = MODE_RS485_HALF_DUPLEX,           ///< RS485 half duplex communication.
            IRDA = MODE_IRDA,                                     ///< IrDA communication.
            RS485_Collision_Detect = MODE_RS485_COLLISION_DETECT, ///< RS485 collision detect communication.
            RS485_Custom = MODE_RS485_APP_CTRL                    ///< RS485 custom communication.
        };

        typedef class Serial_Class : public Xila_Namespace::Stream_Type
        {
        public:
            // - Methods
            Serial_Class() = default;

            /// @brief Begin serial communication.
            /// @param Baud_Rate Baud rate.
            /// @param Configuration Serial configuration.
            /// @param Receive_Pin Receive pin.
            /// @param Transmit_Pin Transmit pin.
            /// @param Invert Invert signal.
            /// @param Timeout Timeout.
            void Begin(unsigned long Baud_Rate, Serial_Configuration_Type Configuration = Serial_Configuration_Type::Data_8_Bits, int8_t Receive_Pin = -1, int8_t Transmit_Pin = -1, bool Invert = false, unsigned long Timeout = 20000);
            
            /// @brief End serial communication.
            void End();

            /// @brief Check if serial is available.
            /// @return true if serial is available, false otherwise.
            int Available() override;

            /// @brief Peek next byte.
            /// @return Next byte or -1 if no byte is available.
            int Peek() override;

            /// @brief Read next byte.
            /// @return Next byte or -1 if no byte is available.
            int Read() override;

            /// @brief Read bytes.
            /// @param Buffer Buffer to store bytes.
            /// @param Length Number of bytes to read.
            /// @return Number of bytes read.
            Size_Type Read_Bytes(Byte_Type *Buffer, Size_Type Length) override;
            
            /// @brief Read string.
            /// @param String String to store.
            /// @return String.
            String_Type &Read_String(String_Type &String) override;

            /// @brief Available bytes for write.
            /// @return Number of bytes available for write.
            int Available_For_Write() override;

            /// @brief Flush serial.
            void Flush() override;

            /// @brief Write byte.
            /// @param Byte Byte to write.
            /// @return Number of bytes written.
            Size_Type Write(Byte_Type Byte) override;

            /// @brief Write bytes.
            /// @param Buffer Buffer to write.
            /// @param Length Number of bytes to write.
            /// @return Number of bytes written.
            Size_Type Write_Bytes(const Byte_Type *Buffer, Size_Type Length) override;
            
            /// @brief Write string.
            /// @param String String to write.
            /// @return Number of bytes written.
            Size_Type Write_String(const char *String) override;

            // - - Setters

            /// @brief Set baud rate.
            /// @param Baud_Rate Baud rate.
            void Set_Baud_Rate(unsigned long Baud_Rate);

            /// @brief Set serial pins.
            /// @param Receive_Pin Receive pin.
            /// @param Transmit_Pin Transmit pin.
            /// @param CTS_Pin CTS pin.
            /// @param RTS_Pin RTS pin.
            /// @return Result_Type
            Result_Type Set_Pins(int8_t Receive_Pin, int8_t Transmit_Pin, int8_t CTS_Pin = -1, int8_t RTS_Pin = -1);

            /// @brief Set hardware flow control.
            /// @param State Enable or disable hardware flow control.
            /// @param RTS_Enable Enable or disable RTS.
            /// @param CTS_Enable Enable or disable CTS.
            /// @param Threshold Threshold.
            /// @return Result_Type
            Result_Type Set_Hardware_Flow_Control(bool State, bool RTS_Enable = false, bool CTS_Enable = false, int8_t Threshold = 64);
            
            /// @brief Set serial mode.
            /// @param Mode Serial mode.
            /// @return Result_Type
            Result_Type Set_Mode(Serial_Mode_Type Mode);

            /// @brief Set receive buffer size.
            /// @param Size Size of the receive buffer in bytes.
            /// @return Result_Type
            Result_Type Set_Receive_Buffer_Size(Size_Type Size);

            /// @brief Set transmit buffer size.
            /// @param Size Size of the transmit buffer in bytes.
            /// @return Result_Type
            Result_Type Set_Transmit_Buffer_Size(Size_Type Size);

            /// @brief Set receive signal inversion.
            /// @param State Enable or disable receive signal inversion.
            void Set_Receive_Invert(bool State);

            // - - Getters

            /// @brief Get baud rate.
            /// @return Baud rate.
            uint32_t Get_Baud_Rate();

            // - - Operators

            operator bool() const;

        protected:
            Serial_Class(HardwareSerial &Serial);

            HardwareSerial &Serial;

            friend class Pin_Type;

        } Serial_Type;
    }
}

#endif