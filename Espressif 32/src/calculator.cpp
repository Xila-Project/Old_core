#include "Calculator.hpp"

Calculator_Class* Calculator_Class::Instance_Pointer = NULL;

#define INSTANCE_POINTER Calculator_Class::Instance_Pointer

Calculator_Class::Calculator_Class() : Software_Class(8)
{
    xTaskCreatePinnedToCore(Calculator_Task, "Calculator", 4*1024, NULL, 2, &Task_Handle, 1);
}

Calculator_Class::~Calculator_Class()
{
    Instance_Pointer = NULL;
}

Software_Class* Calculator_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Calculator_Class();
    }
    return Instance_Pointer;
}

void Calculator_Task(void *pvParameters)
{
    while (1)
    {
        switch (INSTANCE_POINTER->Get_Command())
        {
        case 0: //idle
            break;
        case 0x4230: //B0
            INSTANCE_POINTER->Add_Number(0);
            break;

        case 0x4231: //B1
            INSTANCE_POINTER->Add_Number(1);
            break;

        case 0x4232: //B2
            INSTANCE_POINTER->Add_Number(2);
            break;

        case 0x4233: //B3
            INSTANCE_POINTER->Add_Number(3);
            break;

        case 0x4234: //B4
            INSTANCE_POINTER->Add_Number(4);
            break;

        case 0x4235: //B5
            INSTANCE_POINTER->Add_Number(5);
            break;

        case 0x4236: //B6
            INSTANCE_POINTER->Add_Number(6);
            break;

        case 0x4237: //B7
            INSTANCE_POINTER->Add_Number(7);
            break;
        case 0x4238: //B8
            INSTANCE_POINTER->Add_Number(8);
            break;

        case 0x4239: //B9
            INSTANCE_POINTER->Add_Number(9);
            break;

        case 0x423D: //B=
            INSTANCE_POINTER->Compute();

        case 0x4243: //BC
            INSTANCE_POINTER->Clear();
            break;

        case 0x4244: //BD
            INSTANCE_POINTER->Clear_Last_Number();
            break;

        case 0x422B: //B+
            INSTANCE_POINTER->Set_Operator('+');
            break;

        case 0x422D: //B-
            INSTANCE_POINTER->Set_Operator('-');
            break;

        case 0x422A: //B*
            INSTANCE_POINTER->Set_Operator('*');
            break;

        case 0x422F: //B/
            INSTANCE_POINTER->Set_Operator('/');
            break;

        case 0x42B2: //B²
            pow(INSTANCE_POINTER->Number[INSTANCE_POINTER->Current_Number], 2);
            break;


        default:
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(20));
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
                Result += Number[i];
                break;
            case '-':
                Result -= Number[i];
                break;
            case '*':
                Result *= Number[i];
                break;
            case '/':
                Result /= Number[i];
                break;
            case '^':
                pow(Number[0], Number[i]);
                break;
            case 'S':
                Result = sin(Number[i]);
                break;
            case 'C':
                Result = cos(Number[i]);
                break;
            case 'T':
                Result = tan(Number[i]);
                break;
            case 's':
                asin(Number[i]);
                break;
            case 'c':
                Result = acos(Number[i]);
            case 't':
                Result = atan(Number[i]);
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
    memset(Number, 0, sizeof(Number));
    memset(Operator, 0, sizeof(Operator));

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

#undef INSTANCE_POINTER

