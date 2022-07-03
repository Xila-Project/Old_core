///
/// @file System.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 29-03-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef SYSTEM_HPP_INCLUDED
#define SYSTEM_HPP_INCLUDED

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

#endif