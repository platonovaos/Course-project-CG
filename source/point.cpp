#include "point.h"

Point initEmptyPoint()
{
    Point pt;
    pt.X = 0;
    pt.Y = 0;
    pt.Z = 0;

    return pt;
}

TypeDetail defineType(QString typeStr)
{
    TypeDetail type = emptyD;

    if (typeStr == "Куб") {
        type = cube;
    }
    if (typeStr == "Сфера") {
        type = sphere;
    }
    if (typeStr == "Пирамида") {
        type = pyramid;
    }

    return type;
}

QVector<Point> createCube()
{
    QVector<Point> pointsArray;
    Point point = initEmptyPoint();

    point.X = -30; point.Y = -30; point.Z = 10;
    pointsArray.push_back(point);

    point.X = -30; point.Y = 30; point.Z = 10;
    pointsArray.push_back(point);

    point.X = 30; point.Y = 30; point.Z = 10;
    pointsArray.push_back(point);

    point.X = 30; point.Y = -30; point.Z = 10;
    pointsArray.push_back(point);

    //задняя грань
    point.X = -15; point.Y = -45; point.Z = -10;
    pointsArray.push_back(point);

    point.X = -15; point.Y = 15; point.Z = -10;
    pointsArray.push_back(point);

    point.X = 45; point.Y = 15; point.Z = -10;
    pointsArray.push_back(point);

    point.X = 45; point.Y = -45; point.Z = -10;
    pointsArray.push_back(point);

    return pointsArray;
}

QVector<Point> createSphere()
{
    QVector<Point> pointsArray;
    Point point = initEmptyPoint();

    point.X = -30; point.Y = -30; point.Z = 10;
    pointsArray.push_back(point);

    return pointsArray;
}

QVector<Point> createPyramid()
{
    QVector<Point> pointsArray;
    Point point = initEmptyPoint();

    point.X = -30; point.Y = 30; point.Z = 10;
    pointsArray.push_back(point);

    point.X = -15; point.Y = 15; point.Z = -10;
    pointsArray.push_back(point);

    point.X = 45; point.Y = 15; point.Z = -10;
    pointsArray.push_back(point);

    point.X = 30; point.Y = 30; point.Z = 10;
    pointsArray.push_back(point);

    point.X = 7; point.Y = -30; point.Z = 10;
    pointsArray.push_back(point);

    return pointsArray;
}

