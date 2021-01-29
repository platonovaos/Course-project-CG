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
    Detail(Point _figureArray[7]);
    ~Detail();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Point FigureArray[7];
};

#endif // FIGURE_H
