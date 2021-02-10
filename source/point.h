#ifndef POINT_H
#define POINT_H

#include <QGraphicsItem>
#include <QObject>
#include <QCursor>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QString>

struct Point
{
    int X;
    int Y;
    int Z;
};

enum TypeDetail
{
    emptyD,
    cube,
    sphere,
    pyramid
};

Point initEmptyPoint();

TypeDetail defineType(QString typeStr);

QVector<Point> createCube();
QVector<Point> createSphere();
QVector<Point> createPyramid();

#endif // POINT_H
