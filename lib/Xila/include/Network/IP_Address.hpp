#ifndef Xila_Network_IP_Address_Hpp_Included
#define Xila_Network_IP_Address_Hpp_Included

#include "../Module/String.hpp"

class IPv6Address;
class IPAddress;

namespace Xila_Namespace
{
    namespace Network_Types
    {
        typedef class IP_Address_Class
        {
        public:
            // - Methods

            // - - Constructors / Destructors

            /// @brief Default constructor.
            IP_Address_Class();

            /// @brief Constructor to create an IP v4 address.
            /// @param Address : 32 bits integer representing the IP address.
            explicit IP_Address_Class(DWord_Type Address);

            /// @brief Constructor to create an IP v4 or v6 address.
            /// @param Address : Pointer to an array of 4 or 16 bytes representing the IP address.
            explicit IP_Address_Class(const uint8_t *Address, bool Is_IPv4);

            /// @brief Constructor to create an IP v4 or v6 address from a char array.
            /// @param Address : Pointer to a char array representing the IP address.
            explicit IP_Address_Class(const String_Type& String);

            /// @brief Constructor to create an IP v4 address.
            /// @param Byte_1 First byte of the IP address.
            /// @param Byte_2 Second byte of the IP address.
            /// @param Byte_3 Third byte of the IP address.
            /// @param Byte_4 Fourth byte of the IP address.
            explicit IP_Address_Class(uint8_t Byte_1, uint8_t Byte_2, uint8_t Byte_3, uint8_t Byte_4);

            /// @brief Constructor to create from an Arduino IPAddress object.
            /// @param IP_Address : IPAddress object.
            explicit IP_Address_Class(const IPAddress &IP_Address);

            /// @brief Constructor to create from an Arduino IPv6Address object.
            /// @param IP_Address : IPv6Address object.
            explicit IP_Address_Class(const IPv6Address &IP_Address);

            // - - Operators

            /// @brief Conversion operator to a 32 bits integer.
            explicit operator uint32_t() const;

            /// @brief Conversion operator to an Arduino IPAddress object.
            explicit operator IPAddress() const;

            /// @brief Conversion operator to an Arduino IPv6Address object.
            explicit operator IPv6Address() const;

            /// @brief Comparison operator.
            /// @param IP_Address : IP address to compare to.
            /// @return `true` if the IP addresses are equal, `false` otherwise.
            bool operator==(const IP_Address_Class &IP_Address) const;

            /// @brief Comparison operator.
            /// @param Address : Pointer to an array of 4  bytes representing the IP v4 address to compare to.
            /// @return `true` if the IP addresses are equal, `false` otherwise.
            bool operator==(const uint8_t *Address) const;

            /// @brief Access operator.
            /// @param Index : Index of the byte to access.
            /// @return The byte at the given index.
            uint8_t operator[](uint8_t Index) const;

            /// @brief Access operator (reference).
            /// @param Index : Index of the byte to access.
            /// @return The reference to the byte at the given index.
            uint8_t &operator[](uint8_t Index);

            /// @brief Assignment operator.
            /// @param IP_Address : An array of 4 bytes representing the IP v4 address.
            /// @return Reference to the assigned IP address.
            IP_Address_Class &operator=(const uint8_t *Address);

            /// @brief Assignment operator.
            /// @param Address : An unsigned 32 bits integer representing the IP address.
            /// @return Reference to the assigned IP address.
            IP_Address_Class &operator=(uint32_t Address);

            // - - Conversion

            /// @brief Convert the IP address to a string.
            /// @param String : String to store the IP address.
            String_Type& To(String_Type &String) const;

            // - - Getters

            /// @brief Get the IP address version.
            /// @return `true` for IPv4, `false` for IPv6.
            bool Is_IP_v4() const;

            // - - Setters

            /// @brief Set the IP address version.
            /// @param Is_IPv4 : `true` for IPv4, `false` for IPv6.
            void Set_IP_Version(bool Is_IPv4);

            /// @brief Parse a string to an IP v4 address.
            /// @param String String to parse.
            /// @param Address Pointer to an array of 4 bytes to store the IP address. 
            /// @return `Result_Type::Success` if the string has been parsed successfully, `Result_Type::Error` otherwise.
            static Result_Type Parse_IP_v4(const String_Type& String, uint32_t& Address);

            /// @brief Parse a string to an IP v6 address.
            /// @param String String to parse.
            /// @param Address Pointer to an array of 16 bytes to store the IP address.
            /// @return `Result_Type::Success` if the string has been parsed successfully, `Result_Type::Error` otherwise.
            static Result_Type Parse_IP_v6(const String_Type& String, uint16_t& Address);

        private:
            // - Attributes

            /// @brief A boolean to know if the IP address is IPv4 or IPv6.
            bool Is_IPv4;

            /// @brief A union to store the IP address.
            union
            {
                DWord_Type DWord;
                Word_Type Words[8];
                Byte_Type Bytes[16];
            };

        } IP_Address_Type;
    }
}

#endif