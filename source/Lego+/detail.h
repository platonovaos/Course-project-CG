#ifndef DETAIL_H
#define DETAIL_H

#include <QColor>
#include <cstdlib>
#include "MathObjects/point.h"

struct DetailParams
{
    Point move;
    Point scale;

    QString filename;
    QString modelName;

    QColor color;

    Point en;
};

class Detail
{
public:
    Detail(const int idx);
    ~Detail();

    DetailParams getParameters();

private:
    DetailParams params;
};

#endif // DETAIL_H
