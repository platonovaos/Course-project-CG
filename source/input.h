#ifndef INPUT_H
#define INPUT_H

#include <QString>
#include "exitCodes.h"

enum Axis
{
    OX,
    OY,
    OZ
};

TError correctInput(QString point);
Axis defineAxis(QString axisStr);

#endif // INPUT_H
