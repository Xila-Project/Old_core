///
/// @file Keyboard.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 21-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Keyboard_Hpp_Included
#define Keyboard_Hpp_Included

#include "Button_Matrix.hpp"


#include "../Module.hpp"

//==============================================================================//
///
/// @brief Keyboard class
///
class Keyboard_Class : public Module_Class
{
public:
    // -- Keyboard constructor / destructor

    Keyboard_Class();

    ///
    /// @brief Keyboard available layout.
    ///
    enum Layouts
    {
        American, ///< American QWERTY layout.
        German,   ///< German QWERTY layout.
        French,   ///< French AZERTY layout.
        Spanish,  ///< Spanish QWERTY layout.
        Italian,  ///< Italian QWERTY layout.
        English   ///< English QWERTY layout.
    };

    ///
    /// @brief Special keys enumeration.
    ///
    enum Special_Keys
    {
        Tab = 9,
        Enter = 13,
        Backspace = 127,
        Escape = 27,
        Insert = 0,
        Delete = 127,
        Home = 0,
        End = 0,
        Page_Up = 25,
        Page_Down = 26,
        Arrow_Up = 11,
        Arrow_Down = 10,
        Arrow_Left = 8,
        Arrow_Right = 21,
        F1 = 0,
        F2 = 0,
        F3 = 0,
        F4 = 0,
        F5 = 0,
        F6 = 0,
        F7 = 0,
        F8 = 0,
        F9 = 0,
        F10 = 0,
        F11 = 0,
        F12 = 0,
        Scroll = 0,
        Euro_Sign = 0,
        // Custom regional keys
        Inverted_Exclamation = 161,
        Cent_Sign,
        Pound_Sign,
        Currency_Sign,
        Yen_Sign,
        Broken_Bar,
        Secontion_Sign,
        Diaeresis,
        Copyright_Sign,
        Feminine_Ordinal,
        Left_Double_Angle_Quote,
        Not_Sign,
        Hyphen,
        Registered_Sign,
        Macron,
        Degree_Sign,
        Plus_Minus_Sign,
        Superscript_Two,
        Superscript_Three,
        Acute_Accent,
        Micro_Sign,
        Pilcrow_Sign,
        Middle_Dot,
        Cedilla,
        Superscript_One,
        Masculine_Ordinal,
        Right_Double_Angle_Quote,
        Fraction_One_Quarter,
        Fraction_One_Half,
        Fraction_Three_Quarters,
        Inverted_Question_Mark,
        A_Grave,
        A_Acute,
        A_Circumflex,
        A_Tilde,
        A_Diaeresis,
        A_Ring_Above,
        AE,
        C_Cedilla,
        E_Grave,
        E_Acute,
        E_Circumflex,
        E_Diaeresis,
        I_Grave,
        I_Acute,
        I_Circumflex,
        I_Diaeresis,
        Eth,
        N_Tilde,
        O_Grave,
        O_Acute,
        O_Circumflex,
        O_Tilde,
        O_Diaeresis,
        Multiplication,
        O_Stroke,
        U_Grave,
        U_Acute,
        U_Circumflex,
        U_Diaeresis,
        Y_Acute,
        Thorn,
        Sharp_S,
        a_Grave,
        a_Acute,
        a_Circumflex,
        a_Tilde,
        a_Diaeresis,
        a_Ring_Above,
        ae,
        c_Cedilla,
        e_Grave,
        e_Acute,
        e_Circumflex,
        e_Diaeresis,
        i_Grave,
        i_Acute,
        i_Circumflex,
        i_Diaeresis,
        eth,
        n_Tilde,
        o_Grave,
        o_Acute,
        o_Circumflex,
        o_Tilde,
        o_Diaeresis,
        Division,
        o_Stroke,
        u_Grave,
        u_Acute,
        u_Circumflex,
        u_Diaeresis,
        y_Acute,
        thorn,
        y_Diaeresis
    };

    // -- Methods
    uint8_t Read();
    uint8_t Read_Raw();

    uint8_t Available();

    void Clear();


    // -- Friendship
    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;

protected:
    // -- Methods
    Result_Type Load_Registry();
    Result_Type Save_Registry();

    uint8_t Layout;

    uint8_t Data_Pin;
    uint8_t Clock_Pin;

    void Begin();

};

#endif