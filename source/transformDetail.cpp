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

        int y = getPoint.Y;
        int z = getPoint.Z;

        Point setPoint;
        setPoint.Y = y * cos(tr) + z * sin(tr);
        setPoint.Y = -y * sin(tr) + z * cos(tr);
        detail.setPoint(i, setPoint);
    }
}

void rotateOY(Detail &detail, const double tr)
{
    for (int i = 0; i < detail.getNumPoints(); i++) {
        Point getPoint = detail.getPoint(i);

        int x = getPoint.X;
        int z = getPoint.Z;

        Point setPoint;
        setPoint.X = x * cos(tr) + z * sin(tr);
        setPoint.Z = -x * sin(tr) + z * cos(tr);
        detail.setPoint(i, setPoint);
    }
}

void rotateOZ(Detail &detail, const double tr)
{
    for (int i = 0; i < detail.getNumPoints(); i++) {
        Point getPoint = detail.getPoint(i);

        int x = getPoint.X;
        int y = getPoint.Y;

        Point setPoint;
        setPoint.X = x * cos(tr) - y * sin(tr);
        setPoint.Y = x * sin(tr) + y * cos(tr);
        detail.setPoint(i, setPoint);
    }
}
