#include "point.h"

void initializeCube(Point (&figureArray)[4])
{
    figureArray[0].X = -30; figureArray[0].Y = -30;
    figureArray[1].X = -30; figureArray[1].Y = 30;
    figureArray[2].X = 30; figureArray[2].Y = 30;
    figureArray[3].X = 30; figureArray[3].Y = -30;
}
