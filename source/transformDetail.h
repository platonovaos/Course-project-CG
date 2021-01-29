#ifndef TRANSFORMDETAIL_H
#define TRANSFORMDETAIL_H

#include <cmath>
#include "point.h"
#include "correctInput.h"

int carryover(Point (&figureArray)[7], QString dxStr, QString dyStr);
int scale(Point (&figureArray)[7], QString kxStr, QString kyStr,
                                        QString xStr, QString yStr);
int rotate(Point (&figureArray)[7], QString trStr,
                                        QString xStr, QString yStr);

#endif // TRANSFORMDETAIL_H
