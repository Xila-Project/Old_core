/// @file Instruction.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 25-02-2023
///
/// @copyright Copyright (c) 2023

#ifndef Instruction_Hpp_Included
#define Instruction_Hpp_Included

#include "Base_Types.hpp"

namespace Xila_Namespace
{
    typedef class Graphics_Class Graphics_Type;

    // - Forward declarations

    class Module_Class;

    namespace Graphics_Types { typedef class Object_Class Object_Type; };

    namespace Graphics_Types
    {
        enum class Event_Code_Type : Byte_Type;
    };

    namespace Softwares_Types
    {
        enum class Event_Code_Type : Byte_Type;
    };

    namespace Power_Types
    {
        enum class Event_Code_Type : Byte_Type;
    };

    /// @brief Xila instruction type.
    typedef class Instruction_Class
    {
    public:
        // - Types

        /// @brief Graphics instruction arguments.
        typedef class Graphics_Class
        {
        public:
            // - Methods
            // - - Constructor
            Graphics_Class();

            // - - Getters

            /// @brief Get the code of a graphics event.
            /// @return `Graphics_Types::Event_Code_Type`.
            Graphics_Types::Event_Code_Type Get_Code() const;

            /// @brief Get the original target of a graphics event.
            /// @return Target of the instruction.
            Graphics_Types::Object_Type Get_Target() const;
            
            /// @brief Get the current target of a graphics event.
            /// @return Current target of the instruction.
            Graphics_Types::Object_Type Get_Current_Target() const;
        private:
            // - - Setters

            /// @brief Set the code of a graphics event.
            /// @param Code Code to set.
            void Set_Code(Graphics_Types::Event_Code_Type Code);

            /// @brief Set the original target of a graphics event.
            /// @param Object Target to set.
            void Set_Target_Pointer(Graphics_Types::Object_Type Object);

            /// @brief Set the current target of a graphics event.
            /// @param Object Current target to set.
            void Set_Current_Target_Pointer(Graphics_Types::Object_Type Object);

            // - Attributes
            Graphics_Types::Event_Code_Type Code;

            void* Target_Pointer;
            void* Current_Target_Pointer;

            friend class Xila_Namespace::Graphics_Class;
        } Graphics_Type;

        /// @brief Software instruction arguments.
        typedef class Softwares_Class
        {
        public:
            // - Methods
            // - - Constructors
            inline Softwares_Class() {}
            // - - Setter
            /// @brief Set the code of a software event.
            /// @param Code Code to set.
            inline void Set_Code(Softwares_Types::Event_Code_Type Code) { this->Code = Code; }
            // - - Getter
            /// @brief Get the code of a software event.
            /// @return `Softwares_Types::Event_Code_Type`.
            inline Softwares_Types::Event_Code_Type Get_Code() const { return Code; }

        private:
            // - Attributes
            Softwares_Types::Event_Code_Type Code;
        } Softwares_Type;

        typedef class Power_Class
        {
        public:
            inline Power_Class() {}
            // - - Setter
            /// @brief Set the code of a power event.
            /// @param Code Code to set.
            inline void Set_Code(Power_Types::Event_Code_Type Code) { this->Code = Code; }
            // - - Getter
            /// @brief Get the code of a power event.
            /// @return `Power_Types::Event_Code_Type`.
            inline Power_Types::Event_Code_Type Get_Code() const { return Code; }

        private:
            Power_Types::Event_Code_Type Code;
        } Power_Type;

        /// @brief Custom instruction arguments.
        typedef class Custom_Class
        {
        public:
            inline Custom_Class() : Code(0) {} 
            inline Custom_Class(uint8_t Code) : Code(Code) {}
            // - - Setter
            /// @brief Set the code of a custom event.
            /// @param Code Code to set.
            inline void Set_Code(uint16_t Code) { this->Code = Code; }
            
            /// @brief Set the data of a custom event.
            /// @param Data Data to set.
            inline void Set_Data(void *Data) { this->Data = Data; }
            // - - Getter
            inline uint16_t Get_Code() const { return Code; }
            inline void *Get_Data() const { return Data; }

        private:
            // - Attributes
            uint16_t Code;
            void *Data;
        } Custom_Type;

        // - Arguments anonymous union.

        /// @brief Instruction union of arguments (according to the sender)
        union
        {
            /// @brief Graphics instruction arguments.
            Graphics_Type Graphics;

            /// @brief Software instruction arguments.
            Softwares_Type Softwares;

            /// @brief Power instruction arguments.
            Power_Type Power;

            /// @brief Custom instruction arguments.
            Custom_Type Custom;
        };

        // - Methods

        // - - Constructors
        Instruction_Class();
        Instruction_Class(Module_Class *Sender, Module_Class *Receiver);
        ~Instruction_Class();

        // - - Getters

        /// @brief Get the sender of the instruction.
        /// @return `Module_Type` pointer.
        Module_Type *Get_Sender() const;

        /// @brief Get the receiver of the instruction.
        /// @return `Module_Type` pointer.
        Module_Type *Get_Receiver() const;

        // - - Setters

        /// @brief Set the sender of the instruction.
        /// @param Sender Sender to set.
        void Set_Sender(Module_Type *Sender);

        /// @brief Set the receiver of the instruction.
        /// @param Receiver Receiver to set.
        void Set_Receiver(Module_Type *Receiver);

    private:
        // - Attributes
        Module_Type *Sender;
        Module_Type *Receiver;

    } Instruction_Type;
}

#endif