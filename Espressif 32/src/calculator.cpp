#include "Calculator.hpp"

Calculator_Class* Calculator_Class::Instance_Pointer = NULL;

#define INSTANCE_POINTER Calculator_Class:Instance_Pointer

Calculator_Class::Calculator_Class()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    
    xTaskCreatePinnedToCore(Calculator_Task, "Calculator", 4*1024, NULL, 2, Task_Handle, 1);
}

Calculator_Class::~Calculator_Class()
{
    Instance_Pointer == NULL;
}

void Calculator_Task(void *pvParameters)
{
    while (1)
    {
        while (INSTANCE_POINTER->Read_Position == INSTANCE_POINTER->Write_Position)
        {
            vTaskDelay(pdMS_TO_TICKS(20));
        }
        switch (INSTANCE_POINTER->Task_Method_Array[INSTANCE_POINTER->Read_Position])
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
        INSTANCE_POINTER->Task_Method_Array[INSTANCE_POINTER->Read_Position];
        INSTANCE_POINTER->Read_Position++;
        vTaskDelay(pdMS_TO_TICKS(10));
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
            case '^':
                pow(Number[0], Number[i]);
            case 'S':
                sin(Number[i]);
            case 'C':
                cos(Number[i]);
            case 'T':
                tan(Number[i]);
            case 's':
                asin();
                break;
            case 'c':
                acos(Number[i]);
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
    memset(Number[1], NULL, sizeof(Number[1]));
    memset(Number[2], NULL, sizeof(Number[2]));
    memset(Operator, NULL, sizeof(Operator));

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

