#ifndef IP_Address_Hpp_Included
#define IP_Address_Hpp_Included

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

            /// @brief Constructor to choose between IPv4 or IPv6 address.
            /// @param Is_IPv4 : true for IPv4, false for IPv6.
            IP_Address_Class(bool Is_IPv4);

            /// @brief Constructor to create an IP v4 address.
            /// @param Address : 32 bits integer representing the IP address.
            IP_Address_Class(uint32_t Address);

            /// @brief Constructor to create an IP v4 or v6 address.
            /// @param Address : Pointer to an array of 4 or 16 bytes representing the IP address.
            IP_Address_Class(const uint8_t *Address, bool Is_IPv4 = true);

            /// @brief Constructor to create an IP v4 address.
            /// @param Byte_1 First byte of the IP address.
            /// @param Byte_2 Second byte of the IP address.
            /// @param Byte_3 Third byte of the IP address.
            /// @param Byte_4 Fourth byte of the IP address.
            IP_Address_Class(uint8_t Byte_1, uint8_t Byte_2, uint8_t Byte_3, uint8_t Byte_4);

            /// @brief Constructor to create from an Arduino IPAddress object.
            /// @param IP_Address : IPAddress object.
            IP_Address_Class(const IPAddress &IP_Address);

            /// @brief Constructor to create from an Arduino IPv6Address object.
            /// @param IP_Address : IPv6Address object.
            IP_Address_Class(const IPv6Address &IP_Address);

            // - - Operators

            /// @brief Conversion operator to a 32 bits integer.
            operator uint32_t() const;

            /// @brief Conversion operator to an Arduino IPAddress object.
            operator IPAddress() const;

            /// @brief Conversion operator to an Arduino IPv6Address object.
            operator IPv6Address() const;

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

        private:
            // - Attributes

            /// @brief A boolean to know if the IP address is IPv4 or IPv6.
            bool Is_IPv4;

            /// @brief A union to store the IP address.
            union
            {
                uint32_t DWord;
                uint8_t Bytes[16];
            } Address;

        } IP_Address_Type;
    }
}

#endif