#include "Calculator.hpp"

Calculator_Class *Calculator_Class::Instance_Pointer = NULL;

Calculator_Class::Calculator_Class() : Software_Class(8),
                                       Current_Number(0xFF)
{
    xTaskCreatePinnedToCore(Main_Task, "Calculator", 4 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
    Execute(Software_Code::Maximize);
}

Calculator_Class::~Calculator_Class()
{
    Instance_Pointer = NULL;
}

Software_Class *Calculator_Class::Load()
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
            Instance_Pointer->Clear_All();
            break;
        case 0x: // AR : switch Angle unity to Radian
            Instance_Pointer->Angle_Unity = 'R';
            break;
        case 0x: // AD : switch Angle unity to Degree
            Instance_Pointer->Angle_Unity = 'D';
            break;
        case 0x4244: //BD
            Instance_Pointer->Clear();
            break;

        case 0x:
            Instance_Pointer->Set_Operator(Pi);
            break;
        case 0x422B: //B+
            Instance_Pointer->Set_Operator(Addition);
            break;

        case 0x422D: //B-
            Instance_Pointer->Set_Operator(Substraction);
            break;

        case 0x422A: //B*
            Instance_Pointer->Set_Operator(Multiplication);
            break;

        case 0x422F: //B/
            Instance_Pointer->Set_Operator(Division);
            break;

        case 0x: //B
            Instance_Pointer->Set_Operator(Modulo);
            break;

        case:
            Instance_Pointer->Set_Operator(Sine);

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
    if (Number_To_Add < 10)
    {
        Number[Current_Number] *= 10;
        Number[Current_Number] += Number_To_Add;
    }
    else if (Number_To_Add == Pi)
    {
        Number[Current_Number] = PI;
    }
    else if (Number_To_Add == Exponential)
    {
        Number[Current_Number] = NEPER_CONSTANT;
    }
    else if (Number_To_Add == Random)
    {
        Number[Current_Number] = random(10);
    }

    Display();
}

void Calculator_Class::Set_Operator(char const &Opertor_To_Set)
{
    Operator = Opertor_To_Set;
    Current_Number = 1;
    if (Current_Number > 2)
    {
        Number[0] = Result;
        Number[1] = 0;
        Result = 0;
        Current_Number = 0;
    }
    Display();
}

void Calculator_Class::Switch_Symbol()
{
    if (Number[Current_Number] > 0)
    {
        Number[Current_Number] -= Number[Current_Number] * 2;
    }
    else
    {
        Number[Current_Number] += Number[Current_Number] * 2;
    }
    Display();
}

void Calculator_Class::Compute()
{
    uint32_t Temporary_Number[2];
    switch (Operator)
    {
    case Addition:
        Result = Number[0] + Number[1];
        break;
    case Substraction:
        Result = Number[0] - Number[1];
        break;
    case Multiplication:
        Result = Number[0] * Number[1];
        break;
    case Division:
        Result = Number[0] / Number[1];
        break;
    case Modulo:
        Temporary_Number[0] = (long)Number[0];
        Temporary_Number[1] = (long)Number[1];
        Result = Temporary_Number[0] % Temporary_Number[1];
        break;
    case Sine:
        if (Angle_Unity == Degree)
        {
            Result = sinf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = sinf(Number[0]);
        }
        break;
    case Cosine:
        if (Angle_Unity == Degree)
        {
            Result = cosf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = cosf(Number[0]);
        }
        break;
    case Tangent:
        if (Angle_Unity == Degree)
        {
            Result = tanf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = tanf(Number[0]);
        }
        break;
    case Arc_Sine:
        if (Angle_Unity == Degree)
        {
            Result = asinf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = asinf(Number[0]);
        }
        break;
    case Arc_Cosine:
        if (Angle_Unity == Degree)
        {
            Result = acosf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = acosf(Number[0]);
        }
        break;
    case Arc_Tangent:
        if (Angle_Unity == Degree)
        {
            Result = atanf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = atanf(Number[0]);
        }
        break;
    case Hyperbolic_Sine:
        if (Angle_Unity == Degree)
        {
            Result = sinhf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = sinhf(Number[0]);
        }
        break;
    case Hyperbolic_Cosine:
        if (Angle_Unity == Degree)
        {
            Result = coshf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = coshf(Number[0]);
        }
        break;
    case Hyperbolic_Tangent:
        if (Angle_Unity == Degree)
        {
            Result = tanhf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = tanhf(Number[0]);
        }
        break;
    case Arc_Hyperbolic_Sine:
        if (Angle_Unity == Degree)
        {
            Result = asinhf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = asinhf(Number[0]);
        }
        break;
    case Arc_Hyperbolic_Cosine:
        if (Angle_Unity == Degree)
        {
            Result = acoshf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = acoshf(Number[0]);
        }
        break;
    case Arc_Hyperbolic_Tangent:
        if (Angle_Unity == Degree)
        {
            Result = atanhf(Degree_To_Radian(Number[0]));
        }
        else
        {
            Result = atanhf(Number[0]);
        }
        break;
    }
    Current_Number = 2;
    Display();
}

float Calculator_Class::Degree_To_Radian(float Angle)
{
    Angle *= PI;
    Angle /= 180;
    return Angle;
}

void Calculator_Class::Clear()
{
    Number[Current_Number] = 0;
    Display();
}

void Calculator_Class::Clear_All()
{
    Current_Number = 0;
    Number[0] = 0;
    Number[1] = 0;
    Result = 0;
    Operator = 0xFF;
}

void Calculator_Class::Display()
{
    String Temporary_String = "";
    switch (Current_Number)
    {
    case 0:
        GalaxOS.Display.Set_Text(F("CALCULATIO_TXT"), F(""));
        Temporary_String = String(Number[Current_Number]);
        GalaxOS.Display.Set_Text("NUMBER_TXT", Temporary_String);
        break;
    case 1:
        Temporary_String = String(Number[0]);
        Temporary_String += " ";
        Temporary_String += String(Operator);
        GalaxOS.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_String);
        Temporary_String = String(Number[1]);
        GalaxOS.Display.Set_Text(F("NUMBER_TXT"), Temporary_String);
        break;
    case 2:
        Temporary_String = String(Number[0]);
        Temporary_String += " ";
        Temporary_String += String(Operator);
        Temporary_String += " ";
        Temporary_String += String(Number[1]);
        GalaxOS.Display.Set_Text(F("CALCULATIO_TXT"), Temporary_String);
        Temporary_String = String(Result);
        GalaxOS.Display.Set_Text(F("NUMBER_TXT"), Temporary_String);

    default:
        break;
    }
    GalaxOS.Display.Set_Text("NUMBER_TXT", Temporary_String);
}
