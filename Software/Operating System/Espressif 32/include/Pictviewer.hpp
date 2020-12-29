#ifndef TEMPLATE_HPP_INCLUDED
#define TEMPLATE_HPP_INCLUDED

#include "Xila.hpp"

class Picture_Viewer_Class : public Software_Class
{
public:
    static Software_Class *Load();
    static void Startup();
    static void Background();
    static void Shutdown();

    enum Picture
    {

    };

    enum Pages
    {

    };
};

#endif