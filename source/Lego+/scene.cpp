#include "scene.h"

#include <QDebug>

Scene::Scene() :
    details(std::vector<Figure>()),
    lightSources(std::vector<LightSourcePoint>()),
    mainCamera(Camera())
{

}

//Detail
int Scene::countDetails()
{
    return details.size();
}

void Scene::addDetail(const Figure& newModel, const Vector3f& scaleK)
{
    details.push_back(newModel);
    details.back().scale(scaleK);
}

void Scene::removeDetail()
{
    details.pop_back();
}

Figure& Scene::getDetail(const int& idx)
{
    return details[idx];
}

void Scene::editDetail(const int& idx, Vector3f& center, Vector3f& scale, Vector3f& rotate)
{
    details[idx].move(center);
    details[idx].scale(scale);
    details[idx].rotate(rotate);
}


//Light
int Scene::countLightSource()
{
    return lightSources.size();
}

void Scene::addLightSource(const Vector3f& lPos, const float& lPower)
{
    lightSources.push_back(LightSourcePoint(lPos, lPower));
}

void Scene::removeLightSource()
{
    lightSources.pop_back();
}

LightSourcePoint& Scene::getLightSource(const int& idx)
{
    return lightSources[idx];
}

void Scene::editLight(const int& idx, const Vector3f& pos, const float& power)
{
    lightSources[idx].setPosition(pos);
    lightSources[idx].setIntensity(power);
}


//Camera
Camera& Scene::getCamera()
{
    return mainCamera;
}

void Scene::setCamera(const Vector3f& pos, const Vector3f& view, const Vector3f& up)
{
    mainCamera = Camera(pos, view, up);
}

Vector3f& Scene::getCameraPos()
{
    return mainCamera.getPosition();
}

Vector3f& Scene::getCameraView()
{
    return mainCamera.getView();
}

Vector3f& Scene::getCameraUp()
{
    return mainCamera.getUp();
}

void Scene::upDownCamera(const float& speed)
{
    Vector3f pos = mainCamera.getPosition();

    if (fabs(pos.y + speed) < 1.25f) {
        mainCamera.upDown(speed);
    }
}

void Scene::rotateCamera(const float& speed)
{
    mainCamera.rotateView(speed);
}

void Scene::strafeCamera(const float& speed)
{
    mainCamera.update();
    mainCamera.strafe(speed);
}

void Scene::movingCamera(const float& speed)
{
    mainCamera.move(speed);
}
