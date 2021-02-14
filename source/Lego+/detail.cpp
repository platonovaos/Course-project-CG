#include "detail.h"
#include "ui_addmodelwindow.h"

Detail::Detail(TypeDetail type)
{
    params.filename = defineFile(type);

    params.move.X = 0;
    params.move.Y = 0;
    params.move.Z = 0;

    params.scale.X = 0.25;
    params.scale.Y = 0.25;
    params.scale.Z = 0.25;

    params.color = Qt::red;
}

Detail::~Detail()
{

} 

DetailParams Detail::getParameters()
{
    return params;
}


TypeDetail defineType(QString typeStr)
{
    TypeDetail type = emptyD;
    if (typeStr == "Куб") {
        type = cube;
    }

    if (typeStr == "Сфера") {
        type = sphere;
    }

    if (typeStr == "Цилиндр") {
        type = cylinder;
    }

    return type;
}

QString defineFile(TypeDetail type)
{
    QString filename = "";
    switch (type) {
        case cube:
            filename = "/home/main/Desktop/BMSTU/5sem/Курсач/код/Lego+/details/cube.h";
            break;
        case sphere:
            filename = "/home/main/Desktop/BMSTU/5sem/Курсач/код/Lego+/details/sphere.h";
            break;
        case cylinder:
            filename = "/home/main/Desktop/BMSTU/5sem/Курсач/код/Lego+/details/cylinder.h";
            break;
        default:
            break;
    }

    return filename;
}
