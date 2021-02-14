#include "matrix.h"

Matrix::Matrix(Vector3f v) :
    data(std::vector<std::vector<float>>(4, std::vector<float>(1, 1.f))),
    numRows(4), numCols(1)
{
    data[0][0] = v.x;
    data[1][0] = v.y;
    data[2][0] = v.z;
}

Matrix::Matrix(const int r, int c) :
    data(std::vector<std::vector<float>>(r, std::vector<float>(c, 0.f))),
    numRows(r), numCols(c)
{

}



int Matrix::nrows()
{
    return numRows;
}

int Matrix::ncols()
{
    return numCols;
}


std::vector<float>& Matrix::operator[](const int& i)
{
    return data[i];
}

Matrix Matrix::operator *(const Matrix& a)
{
    Matrix result(numRows, a.numCols);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < a.numCols; j++) {
            result.data[i][j] = 0.0f;

            for (int k = 0; k < numRows; k++) {
                result.data[i][j] += data[i][k] * a.data[k][j];
            }
        }
    }
    return result;
}



void Matrix::fill(const float& v)
{
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            data[i][j] = v;
        }
    }
}

float Matrix::get(const int& i, const int& j)
{
    return data[i][j];
}


Matrix Matrix::identity(const int& dimensions)
{
    Matrix result(dimensions, dimensions);

    for (int i = 0; i < dimensions; i++) {
        for (int j = 0; j < dimensions; j++) {
            result[i][j] = (i == j ? 1.f : 0.f);
        }
    }
    return result;
}
