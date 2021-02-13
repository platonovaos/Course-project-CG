#include "light.h"
#include "ui_addlightwindow.h"

Light::Light(int idx)
{
    params.set.X = 100;
    params.set.Y = -100;
    params.set.Z = 100;

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
