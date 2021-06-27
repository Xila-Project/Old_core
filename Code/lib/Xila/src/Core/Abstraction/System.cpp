#include "Core/Core.hpp"

uint8_t Xila_Class::System_Class::Get_Chip_Revision()
{
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    return chip_info.revision;
}

const char *Xila_Class::System_Class::Get_Chip_Model()
{
    uint32_t chip_ver = REG_GET_FIELD(EFUSE_BLK0_RDATA3_REG, EFUSE_RD_CHIP_VER_PKG);
    uint32_t pkg_ver = chip_ver & 0x7;
    switch (pkg_ver)
    {
    case EFUSE_RD_CHIP_VER_PKG_ESP32D0WDQ6:
        return "ESP32-D0WDQ6";
    case EFUSE_RD_CHIP_VER_PKG_ESP32D0WDQ5:
        return "ESP32-D0WDQ5";
    case EFUSE_RD_CHIP_VER_PKG_ESP32D2WDQ5:
        return "ESP32-D2WDQ5";
    case EFUSE_RD_CHIP_VER_PKG_ESP32PICOD2:
        return "ESP32-PICO-D2";
    case EFUSE_RD_CHIP_VER_PKG_ESP32PICOD4:
        return "ESP32-PICO-D4";
    default:
        return "Unknown";
    }
}

uint32_t Xila_Class::System_Class::Get_Chip_Cores()
{
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    return chip_info.cores;
}
