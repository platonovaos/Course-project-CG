#include "figure.h"
#include <cmath>
#include <iostream>

Figure::Figure(Point _figureArray[7]) :
    QGraphicsItem()
{
    for (int i = 0; i < 7; i++) {
        figureArray[i] = _figureArray[i];
    }
}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{
    return QRectF(-580, -425, 1161, 851);   // Ограничиваем область, в которой лежит треугольник
}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;

        painter->setPen(QPen(Qt::blue));

        painter->drawLine(figureArray[0].X, figureArray[0].Y, figureArray[1].X, figureArray[1].Y);
        painter->drawLine(figureArray[1].X, figureArray[1].Y, figureArray[2].X, figureArray[2].Y);
        painter->drawLine(figureArray[2].X, figureArray[2].Y, figureArray[3].X, figureArray[3].Y);
        painter->drawLine(figureArray[3].X, figureArray[3].Y, figureArray[0].X, figureArray[0].Y);

        painter->drawLine(figureArray[4].X, figureArray[4].Y, figureArray[5].X, figureArray[5].Y);
        painter->drawLine(figureArray[5].X, figureArray[5].Y, figureArray[6].X, figureArray[6].Y);

        painter->drawLine(figureArray[1].X, figureArray[1].Y, figureArray[4].X, figureArray[4].Y);
        painter->drawLine(figureArray[2].X, figureArray[2].Y, figureArray[5].X, figureArray[5].Y);
        painter->drawLine(figureArray[3].X, figureArray[3].Y, figureArray[6].X, figureArray[6].Y);

        painter->setPen(QPen(Qt::red));

        painter->setBrush(Qt::white);
        painter->drawPolygon(polygon, Qt::WindingFill);

        painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
        painter->drawLine(-580,0,580,0);
        painter->drawLine(580,0, 570, 10);
        painter->drawLine(580,0, 570, -10);
        painter->drawText(560, 15, "X");
        painter->drawLine(0,-500,0,500);
        painter->drawLine(0, -424, 10, -415);
        painter->drawLine(0, -424, -10, -415);
        painter->drawText(5, -400, "Y");

        for (int i = -500; i < 580; i += 250) {
            painter->drawLine(i, 5, i, -5);
            painter->drawText(i - 35, 15, "(" + QString::number(i) + ";0)");
        }
        for (int i = -500; i < 500; i += 250) {
            if (i == 0)
                continue;
            painter->drawLine(5, i, -5, i);
            painter->drawText(5, i - 10, "(0;" + QString::number(-i) + ")");
        }

        Q_UNUSED(option);
        Q_UNUSED(widget);
}
