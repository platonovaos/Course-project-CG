#include "detail.h"

Detail::Detail()
{
    type = emptyD;
    move = initEmptyPoint();
    rotate = initEmptyPoint();
}

Detail::~Detail()
{

}

void Detail::setType(const DetailType tp)
{
    type = tp;
}

void Detail::setMove(const float offset, const Axis axis)
{
    if (axis == OX) {
        move.X += offset;
    }

    if (axis == OY) {
        move.Y += offset;
    }

    if (axis == OZ) {
        move.Z += offset;
    }
}

void Detail::setRotate(Point rt)
{
    rotate.X += rt.X;
    rotate.Y += rt.Y;
    rotate.Z += rt.Z;
}

DetailType Detail::getType()
{
    return type;
}

Point Detail::getMove()
{
    return move;
}

Point Detail::getRotate()
{
    return rotate;
}

DetailType defineType(QString typeStr)
{
    DetailType type;

    if (typeStr == "") {
        type = emptyD;
    }

    if (typeStr == "Куб") {
        type = cube;
    }

    if (typeStr == "Сфера") {
        type = sphere;
    }

    if (typeStr == "Конус") {
        type = cone;
    }

    if (typeStr == "Тор") {
        type = torus;
    }

    return type;
}
