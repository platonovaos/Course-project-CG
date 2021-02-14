#ifndef SETLIGHTWINDOW_H
#define SETLIGHTWINDOW_H

#include <QString>
#include "baseObj/point.h"

struct LightParams
{
    Point set;
    float power;

    QString name;
};

class Light
{
public:
    Light(int idx);
    ~Light();

    LightParams getParameters();

private:
    LightParams params;
};

#endif // ADDLIGHTWINDOW_H
