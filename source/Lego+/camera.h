#ifndef CAMERA_H
#define CAMERA_H

#include "baseObj/vector3.h"
#include "baseObj/vector3.hpp"

#define DEPTH 255

class Camera
{
private:
    Vector3f mPos;
    Vector3f mView;
    Vector3f mUp;
    Vector3f mStrafe;

    Vector3f cross(const Vector3f&, const  Vector3f&, const Vector3f&);
    float magnitude(const Vector3f&);
    static Vector3f normalize(Vector3f&);

public:
    Camera();
    Camera(const Vector3f&, const Vector3f&, const Vector3f& up = Vector3f(0, 1, 0));

    void setPosition(const Vector3f&, const Vector3f&, const Vector3f&);
    Vector3f& getPosition();

    void setView(const Vector3f&);
    Vector3f& getView();

    void setUp(const Vector3f&);
    Vector3f& getUp();

    void rotateView(const float&);
    void rotatePosition(const float&, Vector3f);

    void move(const float&);
    void strafe(const float&);
    void upDown(const float&);
    void update();


    static Matrix lookAt(Vector3f&, Vector3f&, Vector3f&);
    static Matrix viewport(const int&, const int&, const int&, const int&);
    static Matrix perspective(const float&, const float&, const float&, const float&);
};

#endif // CAMERA_H
