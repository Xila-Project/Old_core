#include "Unit_Test.hpp"

Unit_Test_Class Unit_Test;

Xila_Class::Software_Handle Unit_Test_Handle("Unit Test", 0, Unit_Test_Class::Load);

Unit_Test_Class *Unit_Test_Class::Instance_Pointer = NULL;

Xila_Class::Software *Unit_Test_Class::Load()
{
    TEST_ASSERT_EQUAL_MEMORY(NULL, Instance_Pointer, sizeof(Instance_Pointer));

    Instance_Pointer = new Unit_Test_Class;
    return Instance_Pointer;
}

Unit_Test_Class::Unit_Test_Class() : Xila_Class::Software(Unit_Test_Handle)
{
    TEST_ASSERT_EQUAL_MEMORY(this, Instance_Pointer, sizeof(Instance_Pointer));
}

Unit_Test_Class::~Unit_Test_Class()
{
    TEST_ASSERT_EQUAL_MEMORY(this, Instance_Pointer, sizeof(Instance_Pointer));
    Instance_Pointer = NULL;
}

void Unit_Test_Class::Run()
{
    Task_Type::Delay_Static(2000);
    UNITY_BEGIN();

    Software();
    Software_Handle();
    Account();
    Clipboard();
    Dialog();
    Display();
    Drive();
    Flash();
    GPIO();
    Keyboard();
    Mathematics();
    Memory();
    Power();
    Software_Management();
    Sound();
    System();
    Task();
    Time();
    WiFi();

    UNITY_END();
}

void Unit_Test_Class::Software()
{
}

void Unit_Test_Class::Software_Handle()
{
    {
        Xila_Class::Software_Handle Unit_Test_Handle_2("Unit Test", 0, Unit_Test_Class::Load);
        TEST_ASSERT_TRUE(Unit_Test_Handle == Unit_Test_Handle_2);
    }
    {
        Xila_Class::Software_Handle Unit_Test_Handle_2("Unit", 0, Unit_Test_Class::Load);
        TEST_ASSERT_FALSE(Unit_Test_Handle == Unit_Test_Handle_2);
    }
}

void Unit_Test_Class::Account()
{
    TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Account.Check_Credentials(Unit_Test_Username, Unit_Test_Password));
    TEST_ASSERT_EQUAL_STRING_ARRAY(Unit_Test_Username, Xila.Account.Get_Current_Username(), sizeof(Unit_Test_Username));
    TEST_ASSERT_EQUAL_UINT8(Xila.Account.Logged, Xila.Account.Get_State());

    TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Account.Add("Unit2", "Password"));
    TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Account.Change_Password("Password", "Password2"));
    TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Account.Change_Username("Unit2", "Unit3"));
    TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Account.Set_Autologin(true));
    TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Account.Set_Autologin(false));
    TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Account.Delete("Unit3"));
}

void Unit_Test_Class::Clipboard()
{
    {
        TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Clipboard.Clear());
        uint64_t Number_To_Copy = 1234567890;
        TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Clipboard.Copy(Number_To_Copy));
        uint64_t Number_To_Paste;
        TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Clipboard.Paste(Number_To_Paste));
        TEST_ASSERT_EQUAL_UINT64(Number_To_Copy, Number_To_Paste);
    }
    {
        TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Clipboard.Clear());
        char String_To_Copy[] = "This is a copy/pasted string for a test unit.";
        TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Clipboard.Copy(String_To_Copy));
        char String_To_Paste[sizeof(String_To_Copy)];
        TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Clipboard.Copy(String_To_Paste));
        TEST_ASSERT_EQUAL_STRING_ARRAY(String_To_Copy, String_To_Paste, sizeof(String_To_Copy));
    }
}

void Unit_Test_Class::Dialog()
{
    // -- Nothing can be automaticaly tested here.
}

void Unit_Test_Class::Display()
{
    // -- Nothing can be automaticaly tested here.
}

void Unit_Test_Class::Drive()
{
    TEST_ASSERT_NOT_EQUAL(0, Xila.Drive.Size());
    TEST_ASSERT_NOT_EQUAL(0, Xila.Drive.Total_Bytes());
    TEST_ASSERT_NOT_EQUAL(0, Xila.Drive.Used_Bytes());
    TEST_ASSERT_NOT_EQUAL(Xila.Drive.None, Xila.Drive.Type());
    TEST_ASSERT_TRUE(Xila.Drive.Make_Directory("/UnitTest"));
    TEST_ASSERT_TRUE(Xila.Drive.Exists("/UnitTest"));
    File_Type Unit_File = Xila.Drive.Open("/UnitTest/File1.txt", FILE_WRITE);
    TEST_ASSERT_TRUE(Unit_File);
    Unit_File.print("This is a test string for drive testing unit.");
    TEST_ASSERT_EQUAL_STRING("This is a test string for drive testing unit.", Unit_File.readString().c_str());
    char File_Name[24];
    TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.Drive.Get_Name(Unit_File, File_Name, sizeof(File_Name)));
    TEST_ASSERT_EQUAL_STRING("File1.txt", File_Name);
    Unit_File.Close();
    Xila.Drive.Open("/UnitTest/File2.txt", FILE_WRITE).Close();
    Xila.Drive.Open("/UnitTest/File3.txt", FILE_WRITE).Close();
    File_Type Unit_Folder = Xila.Drive.Open("/UnitTest");
    TEST_ASSERT_EQUAL_UINT16(3, Xila.Drive.Count_Items(Unit_Folder));
    TEST_ASSERT_TRUE(Xila.Drive.Rename("/UnitTest", "/Unit2"));
    TEST_ASSERT_TRUE(Xila.Drive.Remove("/Unit2/File1.txt"));
    TEST_ASSERT_TRUE(Xila.Drive.Remove_Directory("/Unit2"));
    TEST_ASSERT_FALSE(Xila.Drive.Exists("/UnitTest"));
}

void Unit_Test_Class::Flash()
{
    // -- Nothing to test here.
}

void Unit_Test_Class::GPIO()
{
    // -- Nothing to test here (hardware related).
    //RUN_TEST(Xila.GPIO.Set_Mode(5, Xila.GPIO.Output));
    //TEST_ASSERT_EQUAL_UINT8(Xila.Success, Xila.GPIO.Valid_Output_Pin(5));
}

void Unit_Test_Class::Keyboard()
{
    // -- Nothing ot test here (hardware related).
}

void Unit_Test_Class::Mathematics()
{
    TEST_ASSERT_EQUAL_DOUBLE(3.1415, Xila.Mathematics.String_To_Float("3,1415"));
    //char Test_Buffer[]
    //TEST_ASSERT

    TEST_ASSERT_TRUE(Xila.Mathematics.Is_NAN(NAN));
    TEST_ASSERT_TRUE(Xila.Mathematics.Is_Infinite(INFINITY));
    
    TEST_ASSERT_EQUAL_DOUBLE(-7, Xila.Mathematics.Copy_Sign(-2, 7));
    TEST_ASSERT_EQUAL_DOUBLE(-2, Xila.Mathematics.Floor(-2.1346));
    TEST_ASSERT_EQUAL_DOUBLE(4, Xila.Mathematics.Modulo(9, 5));
    TEST_ASSERT_EQUAL_DOUBLE(12, Xila.Mathematics.Greatest_Common_Divisor(96, 36));
    TEST_ASSERT_EQUAL_DOUBLE(288, Xila.Mathematics.Least_Common_Multiple(96, 36));
    TEST_ASSERT_EQUAL_DOUBLE(Pi, Xila.Mathematics.Radians(180));
    TEST_ASSERT_EQUAL_DOUBLE(90, Xila.Mathematics.Degrees(Pi/2));
    TEST_ASSERT_EQUAL_DOUBLE(40320, Xila.Mathematics.Factorial(16));
    TEST_ASSERT_EQUAL_DOUBLE(6, Xila.Mathematics.Absolute(-6));
    TEST_ASSERT_EQUAL_DOUBLE(0.5, Xila.Mathematics.Inverse(2));
    for (double i = 0; i < PI; i += 0,1)
    {
        TEST_ASSERT_EQUAL_DOUBLE(sin(i), Xila.Mathematics.Sine(-0.5, (5 * Xila.Mathematics.Pi) / 6);
        TEST_ASSERT_EQUAL_DOUBLE(cos(i) Xila.Mathematics.Cosine((2* Xila.Mathematics.Pi) / 3));
        TEST_ASSERT_EQUAL_DOUBLE(tan(i), Xila.Mathematics.Tangent(Xila.Mathematics.Pi/4));
    }
    
    TEST_ASSERT_EQUAL_DOUBLE(256, Xila.Mathematics.Power(2, 8));
    TEST_ASSERT_EQUAL_DOUBLE(64, Xila.Mathematics.Square(2, 8));
    TEST_ASSERT_EQUAL_DOUBLE(27, Xila.Mathematics.Cube(3));
    TEST_ASSERT_EQUAL_DOUBLE(3, Xila.Mathematics.Root(6561, 8));
    TEST_ASSERT_EQUAL_DOUBLE(2, Xila.Mathematics.Square_Root(4));
    TEST_ASSERT_EQUAL_DOUBLE(3, Xila.Mathematics.Cubic_Root(27));
    TEST_ASSERT_DOUBLE_WITHIN(0.1, 54.49, Xila.Mathematics.Exponential(4));
    TEST_ASSERT_DOUBLE_WITHIN(0.1, 3.58, Xila.Mathematics.Natural_Logarithm(36));
    TEST_ASSERT_DOUBLE_WITHIN(0.1, 3.92, Xila.Mathematics.Decimal_Logarithm(85));    
}

void Unit_Test_Class::Memory()
{
    TEST_ASSERT_NOT_EQUAL(0, Xila.Memory.Get_Heap_Size());
    TEST_ASSERT_NOT_EQUAL(0, Xila.Memory.Get_Free_Heap());
    TEST_ASSERT_NOT_EQUAL(0, Xila.Memory.Get_Minimum_Free_Heap());
    TEST_ASSERT_NOT_EQUAL(0, Xila.Memory.Get_Maximum_Allocated_Heap());

    #ifdef DBOARD_HAS_PSRAM
        TEST_ASSERT_NOT_EQUAL(0, Xila.Memory.Get_PSRAM_Size());
        TEST_ASSERT_NOT_EQUAL(0, Xila.Memory.Get_Free_PSRAM());
        TEST_ASSERT_NOT_EQUAL(0, Xila.Memory.Get_Minimum_Free_Heap());
        TEST_ASSERT_NOT_EQUAL(0, Xila.Memory.Get_Maximum_Allocated_PSRAM());
    #endif
}

void Unit_Test_Class::Power()
{

    //TEST_ASSERT_EQUAL(Xila.Success, Xila.Power.Open_Registry());
    //TEST_ASSERT_EQUAL(Xila.Success, Xila.Power.Save_Registry());
    
    // -- Nothing to test here because it's hardware related.
}

void Unit_Test_Class::Software_Management();
{
    TEST_ASSERT_EQUAL(Xila.Software_Management.Openned, Xila.Software_Management.Get_State(Unit_Test_Handle));
    TEST_ASSERT_EQUAL(Xila.Software_Management.Minimized, )
    TEST_ASSERT_EQUAL(Xila.Software_Management.Openned)
}




