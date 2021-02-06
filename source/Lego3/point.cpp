#include "point.h"

Point initEmptyPoint()
{
    Point p;
    p.X = 0; p.Y = 0; p.Z = 0;

    return p;
}

Axis defineAxis(QString axisStr)
{
    Axis axis;

    if (axisStr == "") {
        axis = emptyA;
    }

    if (axisStr == "Ось OX") {
        axis = OX;
    }

    if (axisStr == "Ось OY") {
        axis = OY;
    }

    if (axisStr == "Ось OZ") {
        axis = OZ;
    }

    return axis;
}
