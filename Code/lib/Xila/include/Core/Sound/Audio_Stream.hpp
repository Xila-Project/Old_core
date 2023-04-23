/// @file Audio_Stream.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 17-04-2023
///
/// @copyright Copyright (c) 2023

#ifndef Audio_Stream_Hpp_Included
#define Audio_Stream_Hpp_Included

#include "../Module/Module.hpp"

// Forward declaration
class AudioStream;

namespace Xila_Namespace
{
    namespace Audio_Types
    {
        enum class Communication_Type
        {
            Undefined,
            Transmit,
            Receive,
            Receive_Transmit
        };

        /// @brief Generic audio stream class.
        typedef class Audio_Stream_Class : public Stream
        {
        public:
            // - Methods

            // - - Constructor / destructor

            Audio_Stream_Class();
            virtual ~Audio_Stream_Class();

            virtual Result_Type Begin() {}
            virtual void End() {}

            // - - Stream methods override
            virtual size_t readBytes(uint8_t *, size_t) override;
            virtual size_t write(const uint8_t *, size_t) override;
            virtual size_t write(uint8_t) override;
            virtual int available() override;

            // - -
            bool Is_Valid();

            // - - Manipulation

            virtual size_t Read_Bytes(uint8_t*, Size_Type);
            virtual size_t Write(const uint8_t*, Size_Type);
            virtual size_t Write(uint8_t);
            virtual int Available();

            virtual int Available_For_Write();
            virtual void Write_Silence(Size_Type);
            virtual void Flush();

            // - - Operators

            operator bool() const { return available() > 0; }

        protected:
            inline Result_Type Set_Pointer(AudioStream *Pointer)
            {
                if (Audio_Stream_Pointer != NULL || Pointer == NULL)
                    return Result_Type::Error;
                Audio_Stream_Pointer = Pointer;
                return Result_Type::Success;
            }

            inline AudioStream *Get_Pointer() const { return static_cast<AudioStream *>(Audio_Stream_Pointer); }

        private:
            // - Attributes
            void *Audio_Stream_Pointer;
        } Audio_Stream_Type;

    }
}

#endif