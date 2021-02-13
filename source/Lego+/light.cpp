#include "light.h"
#include "ui_addlightwindow.h"

Light::Light(int idx)
{
    params.set.X = 0;
    params.set.Y = 0;
    params.set.Z = 10;

    params.power = 500;
    params.name = ("light " + std::to_string(idx)).c_str();
}

Light::~Light()
{

}

LightParams Light::getParameters()
{
    return params;
}
