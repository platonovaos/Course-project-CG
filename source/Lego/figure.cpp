#include "figure.h"

Detail::Detail(int _numPoints, Point _figureArray[4]) :
    QGraphicsItem(),
    NumPoints(_numPoints)
{
    for (int i = 0; i < NumPoints; i++) {
        FigureArray[i] = _figureArray[i];
    }
}

int Detail::getNumPoints()
{
    return NumPoints;
}

Point Detail::getPoint(int idx)
{
    if (idx < NumPoints) {
        return FigureArray[idx];
    }
}

void Detail::setPoint(int idx, Point point)
{
    if (idx < NumPoints) {
        FigureArray[idx] = point;
    }
}

Detail::~Detail()
{

}

QRectF Detail::boundingRect() const
{
    return QRectF (-40, -40, 80, 80);   // Îãðàíè÷èâàåì îáëàñòü, â êîòîðîé ëåæèò òðåóãîëüíèê
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

