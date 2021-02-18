#ifndef DETAIL_H
#define DETAIL_H

#include "point.h"

class Detail : public QObject, public QGraphicsItem
{
public:
    Detail(TypeDetail _type);
    ~Detail();

    int getNumPoints();
    Point getPoint(const int idx);
    void setPoint(const Point pt, const int idx);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void drawCube(QPainter *painter);
        void drawEdgeCube(QPainter *painter, Point p1, Point p2, Point p3, Point p4);
        void drawLine(QPainter *painter, const Point p1, const Point p2, QColor color);

        void drawSphere(QPainter *painter);

        void drawPyramid(QPainter *painter);
        void drawEdgePyramid(QPainter *painter, Point p1, Point p2, Point p3);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    TypeDetail Type;

    QVector<Point> PointsArray;
    int NumPoints;

    QColor Color;
    QPointF MouseCoords;
};

#endif // DETAIL_H
