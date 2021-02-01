#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QObject>
#include <QCursor>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "point.h"

class Detail : public QObject, public QGraphicsItem
{
public:
    Detail(int _numPoints, Point _figureArray[4]);

    int getNumPoints();
    Point getPoint(int idx);
    void setPoint(int idx, Point point);

    ~Detail();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Point FigureArray[4];
    int NumPoints;
    QPointF MouseCoords;
};

#endif // FIGURE_H
