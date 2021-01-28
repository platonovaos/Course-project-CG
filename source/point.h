#ifndef POINT_H
#define POINT_H

class Point
{
public:
    int X;
    int Y;
};

class Triangle
{
    const int numPoints = 3;
    Point *PointsArray;
};

#endif // POINT_H
