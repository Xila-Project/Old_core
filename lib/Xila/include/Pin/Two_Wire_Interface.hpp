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

            Result_Type Begin(int8_t SDA_Pin = -1, int8_t SCL_Pin = -1, uint32_t Frequency = 0, int16_t Slave_Address = -1);
            Result_Type End();

            void Begin_Transmission(uint16_t Address);

            Result_Type End_Transmission(bool Send_Stop = true);

            Size_Type Request_From(uint16_t Address, Size_Type Size, bool Send_Stop = true);

            int Available() override;
            int Peek() override;
            int Read() override;
            Size_Type Read_Bytes(Byte_Type *Buffer, Size_Type Length) override;
            String_Type &Read_String(String_Type &String) override;

            void Flush() override;
            Size_Type Write(Byte_Type Data) override;
            Size_Type Write_Bytes(const Byte_Type *Data, Size_Type Size) override;

            Size_Type Slave_Write(const Byte_Type *Data, Size_Type Size);

            // - - Getters

            uint16_t Get_Timeout();
            uint32_t Get_Clock_Frequency();

            // - - Setters

            void Set_Timeout(uint16_t Timeout);
            void Set_Clock_Frequency(uint32_t Frequency);
            Result_Type Set_Pins(int SDA_Pin, int SCL_Pin);

        protected:
            Two_Wire_Class(TwoWire &Wire);

            TwoWire &Wire;

            friend class Pin_Type;
        } Two_Wire_Type;

    }
}

#endif