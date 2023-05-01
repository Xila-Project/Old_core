#ifndef Test_Hpp_Interface_Included
#define Test_Hpp_Interface_Included



class Foo_Class
{
public:
    Foo_Class(const char* Name);

    ~Foo_Class();

    bool Clap(int Test);

private:
    char Name[32];
};


#endif