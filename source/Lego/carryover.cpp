#include "carryover.h"

int carryover(Point (&figureArray)[7], QString dxStr, QString dyStr)
{
    int exitCode = correctInputPoint(dxStr, dyStr);
    if (exitCode == SUCCESS) {
        double dx = dxStr.toDouble();
        double dy = dyStr.toDouble();

        if (dy != 0.0) {
            dy *= -1;
        }

        for (int i = 0; i < 7; i++) {
            figureArray[i].X += dx;
            figureArray[i].Y += dy;
        }
    }

    return exitCode;
}
