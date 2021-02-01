#ifndef POINT_H
#define POINT_H

struct Point
{
    int X;
    int Y;
    int Z;
};

void initializeCube(Point (&figureArray)[4]);

#endif // POINT_H
