#include "detail.h"

Detail::Detail(TypeDetail _type) :
    QGraphicsItem()
{
    Type = _type;

    switch (Type) {
    case (cube) :
        NumPoints = 8;
        PointsArray = createCube();
        break;

    case (sphere):
        NumPoints = 1;
        PointsArray = createSphere();
        break;

    case (pyramid):
        NumPoints = 5;
        PointsArray = createPyramid();
        break;

    default:
        break;
    }

    Color = Qt::white;
}

Detail::~Detail()
{

}

int Detail::getNumPoints()
{
    return NumPoints;
}

Point Detail::getPoint(const int idx)
{
    Point point = initEmptyPoint();

    if (idx < NumPoints && idx >= 0) {
        point =  PointsArray[idx];
    }

    return point;
}

void Detail::setPoint(const Point pt, const int idx)
{
    if (idx >= 0 && idx < NumPoints) {
        PointsArray[idx] = pt;
    }
}

QRectF Detail::boundingRect() const
{
    return QRectF (-50, -50, 110, 110);
}

void Detail::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        if (Type == cube) {
            drawCube(painter);    
        }

        if (Type == sphere) {
            drawSphere(painter);
        }

        if (Type == pyramid) {
            drawPyramid(painter);
        }


        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Detail::drawCube(QPainter *painter)
{
    drawEdgeCube(painter, PointsArray[0], PointsArray[1], PointsArray[2], PointsArray[3]);
    drawEdgeCube(painter, PointsArray[3], PointsArray[2], PointsArray[6], PointsArray[7]);
    drawEdgeCube(painter, PointsArray[4], PointsArray[5], PointsArray[6], PointsArray[7]);
    drawEdgeCube(painter, PointsArray[0], PointsArray[1], PointsArray[5], PointsArray[4]);

    drawLine(painter, PointsArray[0], PointsArray[1], Qt::white);
    drawLine(painter, PointsArray[1], PointsArray[2], Qt::white);
    drawLine(painter, PointsArray[2], PointsArray[3], Qt::white);
    drawLine(painter, PointsArray[3], PointsArray[0], Qt::white);

    drawLine(painter, PointsArray[4], PointsArray[5], Qt::black);
    drawLine(painter, PointsArray[5], PointsArray[6], Qt::black);
    drawLine(painter, PointsArray[6], PointsArray[7], Qt::white);
    drawLine(painter, PointsArray[7], PointsArray[4], Qt::white);

    drawLine(painter, PointsArray[0], PointsArray[4], Qt::white);
    drawLine(painter, PointsArray[1], PointsArray[5], Qt::black);
    drawLine(painter, PointsArray[2], PointsArray[6], Qt::white);
    drawLine(painter, PointsArray[3], PointsArray[7], Qt::white);
}

void Detail::drawEdgeCube(QPainter *painter, Point p1, Point p2, Point p3, Point p4)
{
    QPolygon polygon;

    polygon << QPoint(p1.X, p1.Y);
    polygon << QPoint(p2.X, p2.Y);
    polygon << QPoint(p3.X, p3.Y);
    polygon << QPoint(p4.X, p4.Y);

    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);
}

void Detail::drawSphere(QPainter *painter)
{
    painter->setPen(Qt::white);
    painter->setBrush(Qt::red);
    painter->drawEllipse(-30, -30, 60, 60);
}

void Detail::drawPyramid(QPainter *painter)
{
    drawEdgeCube(painter, PointsArray[0], PointsArray[1], PointsArray[2], PointsArray[3]);
    drawEdgePyramid(painter, PointsArray[1], PointsArray[2], PointsArray[4]);
    drawEdgePyramid(painter, PointsArray[0], PointsArray[1], PointsArray[4]);
    drawEdgePyramid(painter, PointsArray[3], PointsArray[0], PointsArray[4]);
    drawEdgePyramid(painter, PointsArray[2], PointsArray[3], PointsArray[4]);

    drawLine(painter, PointsArray[0], PointsArray[1], Qt::black);
    drawLine(painter, PointsArray[1], PointsArray[2], Qt::black);
    drawLine(painter, PointsArray[2], PointsArray[3], Qt::white);
    drawLine(painter, PointsArray[3], PointsArray[0], Qt::white);

    drawLine(painter, PointsArray[0], PointsArray[4], Qt::white);
    drawLine(painter, PointsArray[1], PointsArray[4], Qt::black);
    drawLine(painter, PointsArray[2], PointsArray[4], Qt::white);
    drawLine(painter, PointsArray[3], PointsArray[4], Qt::white);
}

void Detail::drawEdgePyramid(QPainter *painter, Point p1, Point p2, Point p3)
{
    QPolygon polygon;

    polygon << QPoint(p1.X, p1.Y);
    polygon << QPoint(p2.X, p2.Y);
    polygon << QPoint(p3.X, p3.Y);

    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);
}

void Detail::drawLine(QPainter *painter, const Point p1, const Point p2, QColor color)
{
    painter->setPen(QPen(color));
    painter->drawLine(p1.X, p1.Y, p2.X, p2.Y);
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
