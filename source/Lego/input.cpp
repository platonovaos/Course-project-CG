#include "input.h"

TError correctInput(QString koordStr)
{
    TError exitCode = SUCCESS;

    if (koordStr == "") {
        exitCode = EMPTY_POINT;
    }

    int i = 0;
    while (koordStr[i] != nullptr && exitCode == SUCCESS) {
        if (koordStr[i] < '0' || koordStr[i] > '9') {
            if (koordStr[i] != '.' && koordStr[i] != '-') {
                exitCode = INCORRECT_POINT;
            }
        }
        i++;
    }
    return exitCode;
}

Axis defineAxis(QString axisStr)
{
    Axis axis = OX;

    if (axisStr == "Ось OY") {
        axis = OY;
    }

    if (axisStr == "Ось OZ") {
        axis = OZ;
    }

    return axis;
}
