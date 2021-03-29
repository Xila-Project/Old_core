#ifndef TEMPLATE_HPP_INCLUDED
#define TEMPLATE_HPP_INCLUDED

#include "Xila.hpp"

class Image_Viewer_Class : public Software_Class
{
private:
    static Image_Viewer_Class* Instance_Pointer;

    void Get_Metadata();
    void Draw_Image();

    uint16_t Color_Planes;
    size_t Header_Size;
    size_t Size;
    uint16_t Width, Height;
    char Color[2];

    uint32_t Offset;
    uint8_t Color_Depth;

public:

    File Image_File;

    static void Main_Task(void*);


    static Software_Class* Load();
    static void Startup();
    static void Background();
    static void Shutdown();

    Image_Viewer_Class();
    ~Image_Viewer_Class();

    enum Pictures
    {
        Icon_32 = Xila.Display.Image_Viewer
    };

    enum Pages
    {
        Main = 25
    };
};

Software_Handle_Class Image_Viewer_Handle("Picture viewer", Image_Viewer_Class::Icon_32, Image_Viewer_Class::Load);

#endif