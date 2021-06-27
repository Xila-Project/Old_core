#include "Core/Core.hpp"

#include "esp_partition.h"

uint32_t Xila_Class::Flash_Class::Get_Sketch_Free_Space()
{
    const esp_partition_t* Partition = esp_ota_get_next_update_partition(NULL);
    if (!Partition)
    {
        return 0;
    }
    return Partition->size;
}

String Xila_Class::Flash_Class::Get_Sketch_MD5()
{
    static String result;
    if (result.length()) {
        return result;
    }
    uint32_t lengthLeft = Get_Sketch_Size();

    const esp_partition_t *running = esp_ota_get_running_partition();
    if (!running) {
        log_e("Partition could not be found");

        return String();
    }
    const size_t bufSize = SPI_FLASH_SEC_SIZE;
    std::unique_ptr<uint8_t[]> buf(new uint8_t[bufSize]);
    uint32_t offset = 0;
    if(!buf.get()) {
        log_e("Not enough memory to allocate buffer");

        return String();
    }
    MD5Builder md5;
    md5.begin();
    while( lengthLeft > 0) {
        size_t readBytes = (lengthLeft < bufSize) ? lengthLeft : bufSize;
        if (!ESP.flashRead(running->address + offset, reinterpret_cast<uint32_t*>(buf.get()), (readBytes + 3) & ~3)) {
            log_e("Could not read buffer from flash");

            return String();
        }
        md5.add(buf.get(), readBytes);
        lengthLeft -= readBytes;
        offset += readBytes;
    }
    md5.calculate();
    result = md5.toString();
    return result;
}

uint32_t Xila_Class::Flash_Class::Sketch_Size(sketchSize_t Response)
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

uint32_t Xila_Class::Flash_Class::Get_Size()
{
    esp_image_header_t fhdr;
    if (Read(0x1000, (uint32_t *)&fhdr, sizeof(esp_image_header_t)) && fhdr.magic != ESP_IMAGE_HEADER_MAGIC)
    {
        return 0;
    }
    return Magic_Size(fhdr.spi_size);
}

uint32_t Xila_Class::Flash_Class::Get_Speed()
{
    esp_image_header_t fhdr;
    if (Read(0x1000, (uint32_t *)&fhdr, sizeof(esp_image_header_t)) && fhdr.magic != ESP_IMAGE_HEADER_MAGIC)
    {
        return 0;
    }
    return Magic_Speed(fhdr.spi_speed);
}

FlashMode_t Xila_Class::Flash_Class::Get_Mode()
{
    esp_image_header_t fhdr;
    if (Read(0x1000, (uint32_t *)&fhdr, sizeof(esp_image_header_t)) && fhdr.magic != ESP_IMAGE_HEADER_MAGIC)
    {
        return FM_UNKNOWN;
    }
    return Magic_Mode(fhdr.spi_mode);
}

uint32_t Xila_Class::Flash_Class::Magic_Size(uint8_t Byte)
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

uint32_t Xila_Class::Flash_Class::Magic_Speed(uint8_t Byte)
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

FlashMode_t Xila_Class::Flash_Class::Magic_Mode(uint8_t Byte)
{
    FlashMode_t mode = (FlashMode_t)Byte;
    if (mode > FM_SLOW_READ)
    {
        mode = FM_UNKNOWN;
    }
    return mode;
}
