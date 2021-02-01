#include "transformDetail.h"

const double trToRadian = 3.14 / 180;

int scale(Point (&figureArray)[7], QString kxStr, QString kyStr)
{
    int exitCode = correctInputPoint(kxStr, kyStr);
    if (exitCode == SUCCESS) {
        double kx = kxStr.toDouble();
        double ky = kyStr.toDouble();

        for (int i = 0; i < 7; i++) {
            figureArray[i].X *= kx;
            figureArray[i].Y *= ky;
        }
    }
    return exitCode;
}

int rotate(Point (&figureArray)[7], QString trStr)
{
    int exitCode = correctInput(trStr);
    if (exitCode == SUCCESS) {
        double tr = trStr.toDouble() * trToRadian;

        for (int i = 0; i < 7; i++) {
            double x = figureArray[i].X;
            double y = figureArray[i].Y;

            figureArray[i].X = x * cos(tr) - y * sin(tr);
            figureArray[i].Y = x * sin(tr) + y * cos(tr);
        }
    }
    return exitCode;
}
