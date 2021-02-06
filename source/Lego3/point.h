#ifndef POINT_H
#define POINT_H

#include <QString>

struct Point
{
    float X;
    float Y;
    float Z;
};

Point initEmptyPoint();

enum Axis
{
    emptyA,
    OX,
    OY,
    OZ
};

Axis defineAxis(QString axisStr);

#endif // POINT_H
