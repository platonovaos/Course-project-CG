#ifndef POINT_H
#define POINT_H

#include <QString>

enum TypeDetail
{
    emptyD,
    cube,
    sphere,
    cone,
    torus
};

TypeDetail defineType(QString typeStr);
int removeDetail (int numDetails, TypeDetail details[], TypeDetail detailToRemove);


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
void addOffset(Point &move, float offset, Axis axis);

#endif // POINT_H
