#include "lightsourcepoint.h"

LightSourcePoint::LightSourcePoint(const Vector3f& pos, const float& p) :
    position(pos),
    power(p)
{

}

Vector3f& LightSourcePoint::getPosition()
{
    return position;
}

void LightSourcePoint::setPosition(const Vector3f& newPos)
{
    position.x = newPos.x;
    position.y = newPos.y;
    position.z = newPos.z;
}

float LightSourcePoint::getIntensity()
{
    return power;
}

void  LightSourcePoint::setIntensity(const float& newPower)
{
    power = newPower;
}
