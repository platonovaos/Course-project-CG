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
    return QRectF(-580, -425, 1161, 851);   // Ограничиваем область, в которой лежит треугольник
}

void Detail::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;

        painter->setPen(QPen(Qt::blue));

        painter->drawLine(FigureArray[0].X, FigureArray[0].Y, FigureArray[1].X, FigureArray[1].Y);
        painter->drawLine(FigureArray[1].X, FigureArray[1].Y, FigureArray[2].X, FigureArray[2].Y);
        painter->drawLine(FigureArray[2].X, FigureArray[2].Y, FigureArray[3].X, FigureArray[3].Y);
        painter->drawLine(FigureArray[3].X, FigureArray[3].Y, FigureArray[0].X, FigureArray[0].Y);

        painter->drawLine(FigureArray[4].X, FigureArray[4].Y, FigureArray[5].X, FigureArray[5].Y);
        painter->drawLine(FigureArray[5].X, FigureArray[5].Y, FigureArray[6].X, FigureArray[6].Y);

        painter->drawLine(FigureArray[1].X, FigureArray[1].Y, FigureArray[4].X, FigureArray[4].Y);
        painter->drawLine(FigureArray[2].X, FigureArray[2].Y, FigureArray[5].X, FigureArray[5].Y);
        painter->drawLine(FigureArray[3].X, FigureArray[3].Y, FigureArray[6].X, FigureArray[6].Y);

        painter->setPen(QPen(Qt::red));

        painter->setBrush(Qt::blue);
        painter->drawPolygon(polygon, Qt::WindingFill);

        /*painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
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
        }*/

        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Detail::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}

void Detail::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Detail::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
