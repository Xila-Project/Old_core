/// @file Flash.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021

#include "Core/Flash/Flash.hpp"

#include "esp_partition.h"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Flash_Types;

Flash_Type Xila_Namespace::Flash;

uint32_t Xila_Namespace::Flash_Class::Get_Sketch_Size()
{
    return Sketch_Size(SKETCH_SIZE_TOTAL);
}

Result_Type Xila_Namespace::Flash_Class::Read(uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (spi_flash_read(Offset, (uint32_t *)Data, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Partition_Read(const esp_partition_t *Partition, uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (esp_partition_read(Partition, Offset, Data, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Erase_Sector(uint32_t Sector)
{
    if (spi_flash_erase_sector(Sector) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Write(uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (spi_flash_write(Offset, (uint32_t *)Data, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Partition_Erase_Range(const esp_partition_t *Partition, uint32_t Offset, size_t Size)
{
    if (esp_partition_erase_range(Partition, Offset, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Partition_Write(const esp_partition_t *Partition, uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (esp_partition_write(Partition, Offset, Data, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Set_Boot_Partition(Partition_Subtype_Type Partition_Subtype)
{
    if (Partition_Subtype > Xila_Partition)
    {
        return Result_Type::Error;
    }
    if (esp_ota_set_boot_partition(esp_partition_find_first(ESP_PARTITION_TYPE_APP, (esp_partition_subtype_t)Partition_Subtype, NULL)) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}





uint32_t Xila_Namespace::Flash_Class::Get_Sketch_Free_Space()
{
    const esp_partition_t *Partition = esp_ota_get_next_update_partition(NULL);
    if (!Partition)
    {
        return 0;
    }
    return Partition->size;
}





String_Type& Xila_Namespace::Flash_Class::Get_Sketch_MD5(String_Type& String)
{
    String = ESP.getSketchMD5().c_str();
    return String;
}

uint32_t Xila_Namespace::Flash_Class::Sketch_Size(sketchSize_t Response)
{
    esp_image_metadata_t data;
    const esp_partition_t *running = esp_ota_get_running_partition();
    if (!running)
        return 0;
    const esp_partition_pos_t running_pos = {
        .offset = running->address,
        .size = running->size,
    };
    data.start_addr = running_pos.offset;
    esp_image_verify(ESP_IMAGE_VERIFY, &running_pos, &data);
    if (Response)
    {
        return running_pos.size - data.image_len;
    }
    else
    {
        return data.image_len;
    }
}

uint32_t Xila_Namespace::Flash_Class::Get_Size()
{
    esp_image_header_t fhdr;
    if ((Read(0x1000, (uint32_t *)&fhdr, sizeof(esp_image_header_t)) == Result_Type::Success) && (fhdr.magic != ESP_IMAGE_HEADER_MAGIC))
    {
        return 0;
    }
    return Magic_Size(fhdr.spi_size);
}

uint32_t Xila_Namespace::Flash_Class::Get_Speed()
{
    esp_image_header_t fhdr;
    if ((Read(0x1000, (uint32_t *)&fhdr, sizeof(esp_image_header_t)) == Result_Type::Success) && (fhdr.magic != ESP_IMAGE_HEADER_MAGIC))
    {
        return 0;
    }
    return Magic_Speed(fhdr.spi_speed);
}

FlashMode_t Xila_Namespace::Flash_Class::Get_Mode()
{
    esp_image_header_t fhdr;
    if ((Read(0x1000, (uint32_t *)&fhdr, sizeof(esp_image_header_t)) == Result_Type::Success) && (fhdr.magic != ESP_IMAGE_HEADER_MAGIC))
    {
        return FM_UNKNOWN;
    }
    return Magic_Mode(fhdr.spi_mode);
}

uint32_t Xila_Namespace::Flash_Class::Magic_Size(uint8_t Byte)
{
    switch (Byte & 0x0F)
    {
    case 0x0: // 8 MBit (1MB)
        return (1024 * 1024);
    case 0x1: // 16 MBit (2MB)
        return (2 * 1024 * 1024);
    case 0x2: // 32 MBit (4MB)
        return (4 * 1024 * 1024);
    case 0x3: // 64 MBit (8MB)
        return (8 * 1024 * 1024);
    case 0x4: // 128 MBit (16MB)
        return (16 * 1024 * 1024);
    default: // fail?
        return 0;
    }
}

uint32_t Xila_Namespace::Flash_Class::Magic_Speed(uint8_t Byte)
{
    switch (Byte & 0x0F)
    {
    case 0x0: // 40 MHz
        return (40 * 1000 * 1000);
    case 0x1: // 26 MHz
        return (26 * 1000 * 1000);
    case 0x2: // 20 MHz
        return (20 * 1000 * 1000);
    case 0xf: // 80 MHz
        return (80 * 1000 * 1000);
    default: // fail?
        return 0;
    }
}

FlashMode_t Xila_Namespace::Flash_Class::Magic_Mode(uint8_t Byte)
{
    FlashMode_t mode = (FlashMode_t)Byte;
    if (mode > FM_SLOW_READ)
    {
        mode = FM_UNKNOWN;
    }
    return mode;
}
