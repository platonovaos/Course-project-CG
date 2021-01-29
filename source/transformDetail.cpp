#include "transformDetail.h"

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

int scale(Point (&figureArray)[7], QString kxStr, QString kyStr,
                                        QString xStr, QString yStr)
{
    int exitCode = correctInputPoint(kxStr, kyStr);
    if (exitCode == SUCCESS) {
        double kx = kxStr.toDouble();
        double ky = kyStr.toDouble();

        correctInputPoint(xStr, yStr);
        if (exitCode == SUCCESS) {
            double xCentre = xStr.toDouble();
            double yCentre = yStr.toDouble();

            if (yCentre != 0.0) {
                yCentre *= -1;
            }

            for (int i = 0; i < 7; i++) {
                figureArray[i].X -= xCentre;
                figureArray[i].Y -= yCentre;

                figureArray[i].X *= kx;
                figureArray[i].Y *= ky;

                figureArray[i].X += xCentre;
                figureArray[i].Y += yCentre;
            }
        }
    }
    return exitCode;
}

const double trToRadian = 3.14 / 180;

int rotate(Point (&figureArray)[7], QString trStr,
                                        QString xStr, QString yStr)
{
    int exitCode = correctInput(trStr);
    if (exitCode == SUCCESS) {
        exitCode = correctInputPoint(xStr, yStr);
        if (exitCode == SUCCESS) {

            double tr = trStr.toDouble() * trToRadian;
            double xCentre = xStr.toDouble();
            double yCentre = yStr.toDouble();

            if (yCentre != 0.0) {
                yCentre *= -1;
            }

            for (int i = 0; i < 7; i++) {
                double x = figureArray[i].X;
                double y = figureArray[i].Y;

                x -= xCentre;
                y -= yCentre;

                figureArray[i].X = x * cos(tr) - y * sin(tr);
                figureArray[i].Y = x * sin(tr) + y * cos(tr);

                figureArray[i].X += xCentre;
                figureArray[i].Y += yCentre;
            }
        }
    }
    return exitCode;
}
