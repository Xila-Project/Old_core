#include "calculator.hpp"
#include "galaxos.hpp"

uint8_t Calculator_Class::Number_Instance = 0;

Calculator_Class::Calculator_Class()
{
    if (Number_Instance > 0)
    {
        delete this;
        return;
    }

    ++Number_Instance;
}

Calculator_Class::~Calculator_Class()
{
    --Number_Instance;
}

void Calculator_Class::Execute(uint16_t const &Socket_Method_To_Set)
{
    Socket_Method = Socket_Method_To_Set;
    vTaskResume(Socket_Handle);
}

void Calculator_Class::Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2)
{
    Socket_Method = ((uint16_t)Socket_Method_Char1 << 8) | (uint16_t)Socket_Method_Char2;
    vTaskResume(Socket_Handle);
}

void Calculator_Socket(void *pvParameters)
{
    Calculator_Class *Calculator_Pointer;
    GalaxOS.Get_Software_Pointer(Calculator_Pointer);
    for (;;)
    {
        switch (Calculator_Pointer->Socket_Method)
        {
        case 0:

            break;
        case 0x4230: //B0
            Calculator_Pointer->Add_Number(0);
            break;

        case 0x4231: //B1
            Calculator_Pointer->Add_Number(1);
            break;

        case 0x4232: //B2
            Calculator_Pointer->Add_Number(2);
            break;

        case 0x4233: //B3
            Calculator_Pointer->Add_Number(3);
            break;

        case 0x4234: //B4
            Calculator_Pointer->Add_Number(4);
            break;

        case 0x4235: //B5
            Calculator_Pointer->Add_Number(5);
            break;

        case 0x4236: //B6
            Calculator_Pointer->Add_Number(6);
            break;

        case 0x4237: //B7
            Calculator_Pointer->Add_Number(7);
            break;

        case 0x4238: //B8
            Calculator_Pointer->Add_Number(8);
            break;

        case 0x4239: //B9
            Calculator_Pointer->Add_Number(9);
            break;

        case 0x423D: //B=
            Calculator_Pointer->Compute();

        case 0x4243: //BC
            Calculator_Pointer->Clear();
            break;

        case 0x4244: //BD
            Calculator_Pointer->Clear_Last_Number();
            break;

        case 0x422B: //B+
            Calculator_Pointer->Set_Operator('+');
            break;

        case 0x422D: //B-
            Calculator_Pointer->Set_Operator('-');
            break;

        case 0x422A: //B*
            Calculator_Pointer->Set_Operator('*');
            break;

        case 0x422F: //B/
            Calculator_Pointer->Set_Operator('/');
            break;

        case 0x42B2: //B²
            pow(Calculator_Pointer->Number[Calculator_Pointer->Current_Number], 2);
            break;

        

        default:
            break;
        }
        Calculator_Pointer->Socket_Method = 0;
        vTaskSuspend(NULL);
    }
}

void Calculator_Class::Add_Number(uint8_t const &Number_To_Add)
{
    Number[Current_Number] *= 10;
    Number[Current_Number] += Number_To_Add;
}

void Calculator_Class::Set_Operator(char const &Opertor_To_Set)
{
    Operator[Current_Number] = Opertor_To_Set;
    Current_Number++;
}

void Calculator_Class::Compute()
{
    for (uint8_t i = 1; i < 6; i++)
    {
        if (Number[i] != 0 && Operator[i - 1] != 0)
        {
            switch (Operator[i - 1])
            {
            case '+':
                Number[0] += Number[i];
                break;
            case '-':
                Number[0] -= Number[i];
                break;
            case '*':
                Number[0] *= Number[i];
                break;
            case '/':
                Number[0] /= Number[i];
                break;
            default:
                break;
            }
        }
    }
    Display();
}

void Calculator_Class::Clear()
{
    Current_Number = 0;
    Number[0] = 0;
    Number[1] = 0;
    Number[2] = 0;
    Number[3] = 0;
    Number[4] = 0;
    Number[5] = 0;
    Operator[0] = 0;
    Operator[1] = 0;
    Operator[2] = 0;
    Operator[3] = 0;
    Operator[4] = 0;
}

void Calculator_Class::Clear_Last_Number()
{
    Number[Current_Number] = 0;
}

void Calculator_Class::Display()
{
    String Temporary_String = "";
    for (uint8_t i = 0; i < 6; i++)
    {
        if (Number[i] == 0)
        {
            break;
        }
        else
        {
           Temporary_String += Number[i];
        }
        Temporary_String += " ";

        if (Operator[i] != 0 && i < 5)
        {
            Temporary_String += Operator[i];
        }
    }
    GalaxOS.Display.Set_Text("NUMBER_TXT", Temporary_String);
}

