#include "detail.h"
#include "ui_addmodelwindow.h"

Detail::Detail(const int idx)
{
    params.filename = "/home/main/Desktop/BMSTU/5sem/Курсач/код/Lego+/details/cube.h";
    params.modelName = ("detail " + std::to_string(idx)).c_str();

    params.move.X = 0;
    params.move.Y = 0;
    params.move.Z = 0;

    params.scale.X = 1;
    params.scale.Y = -1;
    params.scale.Z = 1;

    params.color = Qt::red;
}

Detail::~Detail()
{

} 

DetailParams Detail::getParameters()
{
    return params;
}
