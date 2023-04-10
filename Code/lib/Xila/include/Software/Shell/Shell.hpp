///
/// @file Shell.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila's user interface header file.
/// @version 0.1.0
/// @date 21-05-2020
/// @details Xila user interface software.
///
/// @section License
///
/// Copyright (c) 2020 Alix ANNERAUD
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
/// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
///
/// @copyright Copyright (c) 2021
///

#ifndef Shell_Hpp_Included
#define Shell_Hpp_Included

#include "Xila.hpp"

using namespace Xila;

/// @brief Shell class
///
/// @details Main inter
class Shell_Class : public Software_Type
{
    // - Atributes

    // - - Graphics

    // - - - Overlay

    Style_Type Status_Buttons_Style;
    Object_Type Overlay;
    Button_Type Battery_Button;
    Button_Type WiFi_Button;
    Button_Type Sound_Button;
    Graphics_Types::Label_Type Clock_Label;

    Graphics_Types::Screen_Type Screen; // ! : Must be declared before desk (due to the order of construction) since desk needs screen to create a window.
    Graphics_Types::Keyboard_Type Keyboard;

    /// @brief Desk class
    class Desk_Class
    {
    public:
        // - Methods

        // - - Constructors / destructor
        Desk_Class(Shell_Class *Shell_Pointer);
        ~Desk_Class();

        // - - Others
        void Execute_Instruction(const Instruction_Type &Instruction);

        // - -  Getters
        Color_Type Get_Background_Color() const;
        Color_Type Get_Foreground_Color() const;

        // - - Setters
        void Set_Background_Color(Color_Type Color);
        void Set_Foreground_Color(Color_Type Color);

        // - Attributes
        Graphics_Types::Window_Type Window;

        void Set_Interface();

        void Refresh();

    private:
        // - Attributes

        // - - Parent window
        Object_Type Desk_Grid;
        Object_Type Dock;
        Object_Type Menu_Button;
        Object_Type Dock_List;

        Color_Type Background_Color;
        Color_Type Foreground_Color;

        // - - Shell pointer
        Shell_Class *Shell_Pointer;
    } Desk;

    class Drawer_Class
    {
    public:
        // - Methods
        void Open();
        void Close();
        bool Is_Openned();

        void Set_Interface();

        void Execute_Instruction(const Instruction_Type &Instruction);

        // - Attributes
        Graphics_Types::Window_Type Window;

        Drawer_Class(Shell_Class *Shell_Pointer);
        ~Drawer_Class();

    private:
        // - Methods

        // - - Constructors / destructor

        // - Attributes

        Shell_Class *Shell_Pointer;

    } Drawer;

    /// @brief Login class
    class Login_Class
    {
    public:
        // - Methods
        static void Open(Shell_Class *Shell_Pointer);
        static bool Is_Openned(Shell_Class *Shell_Pointer);
        static void Close(Shell_Class *Shell_Pointer);
        static bool Is_Maximized(Shell_Class *Shell_Pointer);

        void Execute_Instruction(const Instruction_Type &Instruction);

        // - Attributes
        Graphics_Types::Dialog_Type Dialog;

    private:
        // - Methods

        // - - Constructors / destructor
        Login_Class(Shell_Class *Shell_Pointer);
        ~Login_Class();

        // - - Managment

        // - Attributes

        Graphics_Types::Text_Area_Type Name_Input;
        Graphics_Types::Text_Area_Type Password_Input;
        Button_Type Login_Button;
        Graphics_Types::Label_Type Login_Label;

        Shell_Class *Shell_Pointer;
    } *Login_Pointer;

    class Installer_Class
    {
    public:
        // - Methods

        static void Open(Shell_Class *Shell_Pointer);
        static bool Is_Openned(Shell_Class *Shell_Pointer);
        static bool Is_Maximized(Shell_Class *Shell_Pointer);
        static void Close(Shell_Class *Shell_Pointer);

        void Execute_Instruction(const Instruction_Type &Instruction);

        // - Attributes

        Graphics_Types::Dialog_Type Dialog;

    private:
        // - Methods

        // - - Constructor / destructor
        Installer_Class(Shell_Class *Shell_Pointer);
        ~Installer_Class();

        // - Attributes

        Button_Type Setup_Button;
        Button_Type Create_Account_Button;
        Graphics_Types::Text_Area_Type Username_Text_Area;
        Graphics_Types::Text_Area_Type Password_Text_Area;

        Shell_Class *Shell_Pointer;
    } *Installer_Pointer;

    class Power_CLass
    {
    public:
        // - Methods

        static void Open(Shell_Class *Shell_Pointer);
        static bool Is_Openned(Shell_Class *Shell_Pointer);
        static bool Is_Maximized(Shell_Class *Shell_Pointer);
        static void Close(Shell_Class *Shell_Pointer);

        void Execute_Instruction(const Instruction_Type &Instruction);

    private:
        // - Methods

        // - Attributes

        Graphics_Types::Dialog_Type Dialog;

        Shell_Class *Shell_Pointer;

    } *Power_Pointer;

    // - Methods

    // - - Constructors / destructor

    Shell_Class(const Accounts_Types::User_Type *Owner_User);
    ~Shell_Class() override;

    // - - Others

    static void Get_Software_Icon(Object_Type&, const String_Type&);
    void Execute_Instruction(Instruction_Type Instruction);
    void Main_Task_Function() override;
    void Refresh_Overlay();

    /// @brief Check for opened softwares.
    
    // - - Registry
    Result_Type Save_Registry();
    Result_Type Create_Registry();
    Result_Type Load_Registry();

    friend class Shell_Handle_Class;
};

// - Types

static class Shell_Handle_Class : public Software_Handle_Type
{
public:
    Shell_Handle_Class() : Software_Handle_Type("Shell")
    {
    };

    void Create_Instance(const Accounts_Types::User_Type *Owner_User) const override
    {
        new Shell_Class(Owner_User);
    };

} Shell_Handle; 

#endif