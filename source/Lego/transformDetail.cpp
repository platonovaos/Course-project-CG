#include "transformDetail.h"

const double trToRadian = 3.14 / 180;

TError rotate(Detail &detail, const QString axisStr, const QString trStr)
{
    TError exitCode = SUCCESS;

    if (axisStr == "") {
        exitCode = EMPTY_POINT;
    } else {
        exitCode = correctInput(trStr);
        if (exitCode == SUCCESS) {

            Axis axis = defineAxis(axisStr);
            double tr = trStr.toDouble() * trToRadian;

            if (axis == OX) {
                rotateOX(detail, tr);
            }

            if (axis == OY) {
                rotateOY(detail, tr);
            }

            if (axis == OZ) {
                rotateOZ(detail, tr);
            }
        }
    }
    return exitCode;
}

void rotateOX(Detail &detail, const double tr)
{
    for (int i = 0; i < detail.getNumPoints(); i++) {
        Point getPoint = detail.getPoint(i);

        int x = getPoint.X;
        int y = getPoint.Y;
        int z = getPoint.Z;

        Point setPoint = initEmptyPoint();
        setPoint.X = x;
        setPoint.Y = static_cast<int>(y * cos(tr) - z * sin(tr) + 0.5);
        setPoint.Z = static_cast<int>(y * sin(tr) + z * cos(tr) + 0.5);

        detail.setPoint(setPoint, i);
    }
}

void rotateOY(Detail &detail, const double tr)
{
    for (int i = 0; i < detail.getNumPoints(); i++) {
        Point getPoint = detail.getPoint(i);

        int x = getPoint.X;
        int y = getPoint.Y;
        int z = getPoint.Z;

        Point setPoint = initEmptyPoint();
        setPoint.X = static_cast<int>(x * cos(tr) + z * sin(tr) + 0.5);
        setPoint.Y = y;
        setPoint.Z = static_cast<int>(-x * sin(tr) + z * cos(tr) + 0.5);

        detail.setPoint(setPoint, i);
    }
}

void rotateOZ(Detail &detail, const double tr)
{
    for (int i = 0; i < detail.getNumPoints(); i++) {
        Point getPoint = detail.getPoint(i);

        int x = getPoint.X;
        int y = getPoint.Y;
        int z = getPoint.Z;

        Point setPoint = initEmptyPoint();
        setPoint.X = static_cast<int>(x * cos(tr) - y * sin(tr) + 0.5);
        setPoint.Y = static_cast<int>(x * sin(tr) + y * cos(tr) + 0.5);
        setPoint.Z = z;

        detail.setPoint(setPoint, i);
    }
}
