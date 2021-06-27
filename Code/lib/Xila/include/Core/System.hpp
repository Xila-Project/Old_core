///
/// @file System.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 29-03-2021
///
/// @copyright Copyright (c) 2021
///

inline uint32_t Xila_Class::System_Class::Random() const
{
    return esp_random();
}

inline uint32_t Xila_Class::System_Class::Random(uint32_t Upper_Bound) const
{
    uint32_t x = esp_random();
    uint64_t m = uint64_t(x) * uint64_t(Upper_Bound);
    uint32_t l = uint32_t(m);
    if (l < Upper_Bound)
    {
        uint32_t t = -Upper_Bound;
        if (t >= Upper_Bound)
        {
            t -= Upper_Bound;
            if (t >= Upper_Bound)
                t %= Upper_Bound;
        }
        while (l < t)
        {
            x = esp_random();
            m = uint64_t(x) * uint64_t(Upper_Bound);
            l = uint32_t(m);
        }
    }
    return m >> 32;
}

inline uint32_t Xila_Class::System_Class::Random(uint32_t Lower_Bound, uint32_t Upper_Bound) const
{
    if (Lower_Bound >= Upper_Bound)
    {
        return Lower_Bound;
    }
    long diff = Upper_Bound - Lower_Bound;
    return Random(diff) + Lower_Bound;
}

inline uint32_t Xila_Class::System_Class::Get_CPU_Frequency()
{
    return getCpuFrequencyMhz();
}

inline const char* Xila_Class::System_Class::Get_SDK_Version()
{
    return esp_get_idf_version();
}

inline uint64_t Xila_Class::System_Class::Get_eFuse_MAC()
{
    uint64_t _chipmacid = 0LL;
    esp_efuse_mac_get_default((uint8_t*) (&_chipmacid));
    return _chipmacid;
}

