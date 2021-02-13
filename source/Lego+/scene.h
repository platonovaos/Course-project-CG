#ifndef SCENE_H
#define SCENE_H

#include "./SceneObjects/model.h"
#include "./SceneObjects/camera.h"
#include "./SceneObjects/lightsourcepoint.h"

class Scene
{
private:
    std::vector<Figure> details;
    std::vector<LightSourcePoint> lightSources;
    Camera mainCamera;

public:
    Scene();

    //Detail
    int countDetails();
    void addDetail(const Figure&, const Vector3f& scale = Vector3f(1, 1, 1));
    void removeDetail();

    Figure& getDetail(const int&);
    void editDetail(const int&, Vector3f&, Vector3f&, Vector3f&);


    //Light
    int countLightSource();
    void addLightSource(const Vector3f&, const float&);
    void removeLightSource();

    LightSourcePoint& getLightSource(const int&);
    void editLight(const int&, const Vector3f&, const float&);


    // Camera
    Camera& getCamera();
    void setCamera(const Vector3f&, const Vector3f&, const Vector3f&);

    Vector3f& getCameraPos();
    Vector3f& getCameraView();
    Vector3f& getCameraUp();

    void upDownCamera(const float&);
    void rotateCamera(const float&);
    void strafeCamera(const float&);
    void movingCamera(const float&);
};

#endif // SCENE_H
