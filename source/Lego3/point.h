#ifndef POINT_H
#define POINT_H

#include <QString>

enum Detail
{
    empty,
    cube,
    sphere,
    cone,
    torus
};

Detail defineType(QString typeStr);
int removeDetail (int numDetails, Detail details[], Detail detailToRemove);


struct Point
{
    int X;
    int Y;
    int Z;
};

Point initEmptyPoint();

#endif // POINT_H
