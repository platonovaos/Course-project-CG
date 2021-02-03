#include "point.h"

TypeDetail defineType(QString typeStr)
{
    TypeDetail type;

    if (typeStr == "") {
        type = emptyD;
    }

    if (typeStr == "Куб") {
        type = cube;
    }

    if (typeStr == "Сфера") {
        type = sphere;
    }

    if (typeStr == "Конус") {
        type = cone;
    }

    if (typeStr == "Тор") {
        type = torus;
    }

    return type;
}

int removeDetail (int numDetails, TypeDetail details[], TypeDetail detailToRemove)
{
    int idx = -1;
    for (int i = numDetails - 1; i <= 0; i--) {
        if (details[i] == detailToRemove) {
            idx = i;
            break;
        }
    }
    return idx;
}

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

void addOffset(Point &move, float offset, Axis axis)
{
    if (axis == OX) {
        move.X += offset;
    }

    if (axis == OY) {
        move.Y += offset;
    }

    if (axis == OZ) {
        move.Z += offset;
    }
}
