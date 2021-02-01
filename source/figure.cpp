#include "figure.h"
#include <cmath>
#include <iostream>

Detail::Detail(Point _figureArray[7]) :
    QGraphicsItem()
{
    for (int i = 0; i < 7; i++) {
        FigureArray[i] = _figureArray[i];
    }
}

Detail::~Detail()
{

}

QRectF Detail::boundingRect() const
{
    return QRectF (-30,-30,60,60);   // Ограничиваем область, в которой лежит треугольник
}

void Detail::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;

        painter->setPen(QPen(Qt::blue));

        painter->drawLine(FigureArray[0].X, FigureArray[0].Y, FigureArray[1].X, FigureArray[1].Y);
        painter->drawLine(FigureArray[1].X, FigureArray[1].Y, FigureArray[2].X, FigureArray[2].Y);
        painter->drawLine(FigureArray[2].X, FigureArray[2].Y, FigureArray[3].X, FigureArray[3].Y);
        painter->drawLine(FigureArray[3].X, FigureArray[3].Y, FigureArray[0].X, FigureArray[0].Y);

        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Detail::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos() + MouseCoords));
}

void Detail::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    MouseCoords = this->pos() - mapToScene(event->pos());
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Detail::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
