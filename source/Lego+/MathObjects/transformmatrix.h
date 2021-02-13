#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H

#include <math.h>
#include "matrix.h"

class MoveMatrix : public Matrix
{
public:
    MoveMatrix(int, int, int);
};


class RotateOxMatrix : public Matrix
{
public:
    RotateOxMatrix(double);
};

class RotateOyMatrix : public Matrix
{
public:
    RotateOyMatrix(double);
};

class RotateOzMatrix : public Matrix
{
public:
    RotateOzMatrix(double);
};

#endif // TRANSFORMMATRIX_H
