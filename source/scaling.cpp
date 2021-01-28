#include "scaling.h"

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
