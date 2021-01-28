#include "correctInput.h"

int correctInputPoint(QString x, QString y)
{
    int exitCode = correctInput(x);
    if (exitCode == SUCCESS) {
        exitCode = correctInput(y);
    }

    return exitCode;
}

int correctInput(QString koordStr)
{
    int exitCode = SUCCESS;

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
