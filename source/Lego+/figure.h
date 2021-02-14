#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <QColor>

#include "baseObj/vector3.h"
#include "baseObj/vector3.hpp"
#include "baseObj/transformmatrix.h"

class Figure
{
protected:
    Vector3f center;
    std::vector<Vector3f> verts;

    std::vector<std::vector<Vector3i>> faces;
    std::vector<Vector3f> norms;

    QColor color;

    Vector3f normalCalculate(const Vector3f&, const Vector3f&, const Vector3f&);
    void normalsProcessing();

public:
    Figure(const char*, const QColor&, const Vector3f& center = Vector3f(0, 0, 0));

    Vector3f& getCenter();
    void setCenter(const Vector3f&);

    int countVerts();
    Vector3f& vert(const int&);

    int countFaces();
    std::vector<int> face(const int&);

    int countNorms();
    void setNorm(const int&, const int&, const Vector3f&);
    Vector3f& norm(const int&, const int&);

    QColor& getColor();
    void setColor(const QColor&);

    void move(const Vector3f&);
    void scale(const Vector3f&);
    void rotate(const Vector3f&);
};

#endif // MODEL_H
