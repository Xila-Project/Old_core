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



#include "../Module/Module.hpp"

///=============================================================================//
///
/// @brief Flash wrapper class.
///

namespace Xila_Namespace
{
    namespace Flash_Types
    {
        typedef void Partition_Type;
    }

    /// @brief Flash module class.
    typedef class Flash_Class : public Module_Class
    {
    public:   

        // - Methods

        // - - Getters

        /// @brief Get the size the of the flash.
        /// @return Size in bytes.
        Size_Type Get_Size();

        /// @brief Get the flash speed.
        /// @return Speed in hertz.
        QWord_Type Get_Speed();

        /// @brief Get flash chip mode.
        /// @return Flash_Mode_Type
        Natural_Type Get_Mode();

        /// @brief Read data from flash chip. 
        /// @param Offset Offset of the data to read.
        /// @param Data Data buffer pointer.
        /// @param Size Size of the data to read.
        /// @return Result_Type
        Result_Type Read(uint32_t Offset, uint32_t *Data, Size_Type Size);
    
        /// @brief Read data from partition.
        /// @param Partition Partition to read from.
        /// @param Offset Offset of the data to read.
        /// @param Data Data buffer pointer.
        /// @param Size Size of the data to read.
        /// @return Result_Type
        Result_Type Partition_Read(const Flash_Types::Partition_Type *Partition, uint32_t Offset, uint32_t *Data, Size_Type Size);
        
         /// @brief Get the sketch size.
         /// 
         /// @return uint32_t Sketch size in bytes.
        Size_Type Get_Sketch_Size();
        
        /// @brief Get sketch MD5 hash.
        /// @param String MD5 hash.
        /// @return String_Type& String of the hash.
        String_Type& Get_Sketch_MD5(String_Type& String);

        /// @brief Get sketch free space.
        /// @return Free space int bytes.
        Size_Type Get_Sketch_Free_Space();

        /// @brief Find a partition according to the given parameters.
        /// @param Type Partition type.
        /// @param Subtype Partition subtype.
        /// @param Label Partition label.
        /// @param Index Partition index.
        /// @return Flash_Types::Partition_Type* Pointer to the partition.
        const Flash_Types::Partition_Type *Find(Natural_Type Type, Natural_Type Subtype, const char *Label = NULL, Natural_Type Index = 0);

    private:
        // -- Methods
        Result_Type Set_Boot_Partition(uint8_t Partition_Subtype);

        Result_Type Erase_Sector(uint32_t Sector);
        Result_Type Write(uint32_t Offset, uint32_t *Data, Size_Type Size);

        Result_Type Partition_Write(const Flash_Types::Partition_Type *Partition, uint32_t Offset_, uint32_t *Data, Size_Type Size);
        Result_Type Partition_Erase_Range(const Flash_Types::Partition_Type *Partition, uint32_t Offset, Size_Type Size);

        friend class System_Class;
    } Flash_Type;


    /// @brief Flash module instance.
    extern Flash_Type Flash;

}

#endif