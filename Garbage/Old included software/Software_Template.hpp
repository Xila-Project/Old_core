#ifndef TEMPLATE_HPP_INCLUDED
#define TEMPLATE_HPP_INCLUDED

#include "Xila.hpp"

class Template_Class : public Xila_Class::Software
{
public:
    static Xila_Class::Software *Load();
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