#ifndef DETAIL_H
#define DETAIL_H

#include "point.h"

enum DetailType
{
    emptyD,
    cube,
    sphere,
    cone,
    torus
};

class Detail
{
public:
    Detail();
    ~Detail();

    void setType(const DetailType tp);
    void setMove(const float offset, const Axis axis);
    void setRotate(Point rt);

    DetailType getType();
    Point getMove();
    Point getRotate();

private:
    DetailType type;
    Point move;
    Point rotate;
};

DetailType defineType(QString typeStr);

#endif // DETAIL_H
