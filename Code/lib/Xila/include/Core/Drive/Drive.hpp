///
/// @file Drive.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 22-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Drive_Hpp_Included
#define Drive_Hpp_Included

#include "../Module/Module.hpp"

#include "File.hpp"

// TODO : create own FS management.

#ifdef Arduino
#include "FS.h"
#endif

namespace Xila_Namespace
{

    namespace Drive_Types
    {
      

        /// @brief Drive types.
        enum class Drive_Type_Type
        {
            None,  ///< None (nothing connected).
            MMC,   ///< MMC type.
            SD_SC, ///< SD type.
            SD_HC, ///< SD HC type.
            Unknow ///< Unknow type.
        };
    
    }

    typedef class Drive_Class : public Module_Class
    {
    public:
        // - Methods
        // - - Drive informations

        /// @brief Get the drive size.
        /// @return Drive size in bytes.
        uint64_t Get_Size();

        /// @brief Get the drive type.
        /// @return Drive type.
        Drive_Types::Drive_Type_Type Get_Type();

        /// @brief Get the current partition size.
        /// @return Partition size in bytes.
        uint64_t Get_Total_Size();

        /// @brief Get the current partition used size.
        /// @return Partition used size in bytes.
        uint64_t Get_Used_Size();

        // - - File system management

        /// @brief Check if a file exists.
        /// @param Path Path of the file.
        /// @return `true` if the file exists, `false` otherwise.
        bool Exists(const char *Path);

        /// @brief Create a directory.
        /// @param Path Path of the directory.
        /// @return `true` if the directory was created, `false` otherwise.
        Result_Type Make_Directory(const char *Path);

        /// @brief Remove a directory.
        /// @param Path Path of the directory.
        /// @return `true` if the directory was removed, `false` otherwise.
        Result_Type Remove_Directory(const char *Path);

        /// @brief Remove a directory.
        /// @param Path Path of the directory.
        /// @param Recursive `true` to remove the directory recursively, `false` otherwise.
        /// @return `true` if the directory was removed, `false` otherwise.
        Result_Type Remove_Directory(const char *Path, bool Recursive);

        /// @brief Remove an item.
        /// @param Path Path of the item.
        /// @return `true` if the item was removed, `false` otherwise.
        Result_Type Remove(const char *Path);

        /// @brief Open a file / folder.
        /// @param Path Path of the file / folder.
        /// @param Write Open the file in write mode.
        /// @param Append Open the file in append mode.
        /// @return `File_Class` object of the file / folder.
        Drive_Types::File_Type Open(const char *Path, bool Write = false, bool Append = false, bool Create = true);

        /// @brief Remove a file / folder.
        /// @param Path Path of the file / folder.
        /// @return `true` if the file / folder was removed, `false` otherwise.
        Result_Type Remove_File(const char *Path);

        /// @brief Rename a file / folder.
        /// @param Path_From Path of the file / folder to rename.
        /// @param Path_To New path of the file / folder.
        /// @return `true` if the file / folder was renamed, `false` otherwise.
        Result_Type Rename(const char *Path_From, const char *Path_To);

        /// @brief Copy a file / folder.
        /// @param Path_From Path of the file / folder to copy.
        /// @param Path_To Path of the destination file / folder.
        /// @return `true` if the file / folder was copied, `false` otherwise.
        Result_Type Copy(Drive_Types::File_Type &Origin_File, Drive_Types::File_Type &Destination_File);

        /// @brief Copy a file / folder.
        /// @param Path_From Path of the file / folder to copy.
        /// @param Path_To Path of the destination file / folder.
        /// @return `true` if the file / folder was copied, `false` otherwise.
        Result_Type Copy(const char *Path_From, const char *Path_To);

        Result_Type Cut(Drive_Types::File_Type &Origin_File, Drive_Types::File_Type &Destination_File);
        Result_Type Cut(const char *Path_From, const char *Path_To);

        void End();

        Result_Type Start();

    } Drive_Type;

    extern Drive_Type Drive;
}

#endif