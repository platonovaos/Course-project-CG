#ifndef TRANSFORMDETAIL_H
#define TRANSFORMDETAIL_H

#include <cmath>
#include "point.h"
#include "input.h"
#include "detail.h"

TError rotate(Detail &detail, const QString axisStr, const QString trStr);

void rotateOX(Detail &detail, const double tr);
void rotateOY(Detail &detail, const double tr);
void rotateOZ(Detail &detail, const double tr);

#endif // TRANSFORMDETAIL_H
