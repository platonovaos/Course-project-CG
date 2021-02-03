#include "point.h"

Detail defineType(QString typeStr)
{
    Detail det;

    if (typeStr == "") {
        det = empty;
    }

    if (typeStr == "Куб") {
        det = cube;
    }

    if (typeStr == "Сфера") {
        det = sphere;
    }

    if (typeStr == "Конус") {
        det = cone;
    }

    if (typeStr == "Тор") {
        det = torus;
    }

    return det;
}

int removeDetail (int numDetails, Detail details[], Detail detailToRemove)
{
    int idx = -1;
    for (int i = numDetails - 1; i <= 0; i--) {
        if (details[i] == detailToRemove) {
            idx = i;
            break;
        }
    }
    return idx;
}

Point initEmptyPoint()
{
    Point p;
    p.X = 0; p.Y = 0; p.Z = 0;

    return p;
}
