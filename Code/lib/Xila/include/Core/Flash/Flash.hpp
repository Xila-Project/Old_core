///
/// @file Flash.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 24-06-2021
///
/// @copyright Copyright (c) 2021
///


#ifndef Flash_Hpp_Included
#define Flash_Hpp_Included

#include "Arduino.h"

#include "Esp.h"
#include "rom/spi_flash.h"
#include "esp_sleep.h"
#include "esp_spi_flash.h"
#include <memory>
#include <soc/soc.h>
#include <soc/efuse_reg.h>
#include <esp_partition.h>
extern "C"
{
#include "esp_ota_ops.h"
#include "esp_image_format.h"
}
#include <MD5Builder.h>

#include "../Module.hpp"

///=============================================================================//
///
/// @brief Flash wrapper class.
///
class Flash_Class : public Module_Class
{
public:
    // -- Methods
    uint32_t Get_Size();
    uint32_t Get_Speed();
    FlashMode_t Get_Mode();

    Result_Type Read(uint32_t Offset, uint32_t *Data, size_t Size);

    Result_Type Partition_Read(const esp_partition_t *Partition, uint32_t Offset, uint32_t *Data, size_t Size);

    uint32_t Get_Sketch_Size();
    String Get_Sketch_MD5();
    uint32_t Get_Sketch_Free_Space();

private:
    // -- Methods
    Result_Type Set_Boot_Partition(const uint8_t Partition_Number);

    Result_Type Erase_Sector(uint32_t Sector);
    Result_Type Write(uint32_t Offset, uint32_t *Data, size_t Size);

    Result_Type Partition_Write(const esp_partition_t *Partition, uint32_t Offset_, uint32_t *Data, size_t Size);
    Result_Type Partition_Erase_Range(const esp_partition_t *Partition, uint32_t Offset, size_t Size);

    static uint32_t Sketch_Size(sketchSize_t Response);
    uint32_t Magic_Size(uint8_t Byte);
    uint32_t Magic_Speed(uint8_t Byte);
    FlashMode_t Magic_Mode(uint8_t Byte);

    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;
};

#endif