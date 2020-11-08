#include "Calculator.hpp"

Calculator_Class* Calculator_Class::Instance_Pointer = NULL;

Calculator_Class::Calculator_Class() : Software_Class(8)
{
    xTaskCreatePinnedToCore(Main_Task, "Calculator", 4 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
    Execute(Software_Code::Maximize);
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

void Calculator_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Get_Command())
        {
        case 0: //idle
            break;
        case Software_Code::Close:
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Software_Code::Maximize:
            GalaxOS.Display.Set_Current_Page(F("Calculator"));
            break;
        case Software_Code::Minimize:
            vTaskSuspend(NULL);
            break;
        case 0x4230: //B0
            Instance_Pointer->Add_Number(0);
            break;

        case 0x4231: //B1
            Instance_Pointer->Add_Number(1);
            break;

        case 0x4232: //B2
            Instance_Pointer->Add_Number(2);
            break;

        case 0x4233: //B3
            Instance_Pointer->Add_Number(3);
            break;

        case 0x4234: //B4
            Instance_Pointer->Add_Number(4);
            break;

        case 0x4235: //B5
            Instance_Pointer->Add_Number(5);
            break;

        case 0x4236: //B6
            Instance_Pointer->Add_Number(6);
            break;

        case 0x4237: //B7
            Instance_Pointer->Add_Number(7);
            break;
        case 0x4238: //B8
            Instance_Pointer->Add_Number(8);
            break;

        case 0x4239: //B9
            Instance_Pointer->Add_Number(9);
            break;

        case 0x423D: //B=
            Instance_Pointer->Compute();

        case 0x4243: //BC
            Instance_Pointer->Clear();
            break;

        case 0x4244: //BD
            Instance_Pointer->Clear_Last_Number();
            break;

        case 0x422B: //B+
            Instance_Pointer->Set_Operator('+');
            break;

        case 0x422D: //B-
            Instance_Pointer->Set_Operator('-');
            break;

        case 0x422A: //B*
            Instance_Pointer->Set_Operator('*');
            break;

        case 0x422F: //B/
            Instance_Pointer->Set_Operator('/');
            break;

        case 0x42B2: //B²
            pow(Instance_Pointer->Number[Instance_Pointer->Current_Number], 2);
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

