#ifndef DETAIL_H
#define DETAIL_H

#include <QColor>
#include <cstdlib>
#include "baseObj/point.h"

enum TypeDetail
{
    emptyD,
    cube,
    sphere,
    cylinder
};

struct DetailParams
{
    Point move;
    Point scale;

    QString filename;
    QString detailName;

    QColor color;
};

class Detail
{
public:
    Detail(TypeDetail type);
    ~Detail();

    DetailParams getParameters();

private:
    DetailParams params;
};

TypeDetail defineType(QString typeStr);
QString defineFile(TypeDetail type);

#endif // DETAIL_H
