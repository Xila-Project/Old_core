///
/// @file Informations.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 04-03-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/System/System.hpp"

using namespace Xila_Namespace;

// - Methods

// - - Getters

/// @brief Return number of chip cores.
///
/// @return uint32_t Chip cores.
uint32_t System_Class::Get_Chip_Cores()
{
    return ESP.getChipCores();
}

/// @brief Return chip revision.
///
/// @return uint8_t Chip revision.
uint8_t System_Class::Get_Chip_Revision()
{
    return ESP.getChipRevision();
}

///
/// @brief Return chip model.
///
/// @return const char* Chip model.
const char *System_Class::Get_Chip_Model()
{
    return ESP.getChipModel();
}

/// @brief Return CPU frequency.
///
/// @return uint32_t CPU frequency in MHz.
uint32_t System_Class::Get_CPU_Frequency()
{
    return getCpuFrequencyMhz();
}

/// @brief Return eFuse MAC.
///
/// @return uint64_t eFuse MAC.
uint64_t System_Class::Get_eFuse_MAC()
{
    return ESP.getEfuseMac();
}

/// @brief Return device name.
///
/// @return const char* Device name.
void System_Class::Get_Device_Name(String_Class &Device_Name)
{
    Device_Name = this->Device_Name;
}

// - - Setters

/// @brief
/// @param Device_Name
void System_Class::Set_Device_Name(const String_Class &Device_Name)
{
    this->Device_Name = Device_Name;
}