#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QPainter>
#include "point.h"

class Figure : public QGraphicsItem
{
public:
    Figure(Point _figureArray[7]);
    ~Figure();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    Point figureArray[7];
};

#endif // FIGURE_H
