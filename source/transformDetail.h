#ifndef TRANSFORMDETAIL_H
#define TRANSFORMDETAIL_H

#include <cmath>
#include "point.h"
#include "correctInput.h"

int scale(Point (&figureArray)[7], QString kxStr, QString kyStr);
int rotate(Point (&figureArray)[7], QString trStr);

#endif // TRANSFORMDETAIL_H
