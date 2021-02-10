#ifndef ZBUFFER_H
#define ZBUFFER_H

#include <QGraphicsScene>
#include "detail.h"

const int maxYLines = 200;
const double maxDist = 1000;
const int clBk = 3;

struct Cell
{
    double Z;
    int Color;
};

class ZBuffer
{
public:
    ZBuffer(int ax, int ay);
    ~ZBuffer();

    void addDetail(Detail &detail);
    void Clear();

    int sX, sY;
};

void zbuffer(QGraphicsScene *scene, QVector<Detail*> details, const int numDetails);

#endif // ZBUFFER_H
