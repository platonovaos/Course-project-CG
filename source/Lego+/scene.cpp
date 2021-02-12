#include "scene.h"

#include <QDebug>

Scene::Scene() :
    mainCamera(Camera()),
    details(std::vector<Figure>()),
    lightSources(std::vector<LightSourcePoint>())
{

}


int Scene::countDetails()
{
    return details.size();
}

void Scene::addDetail(const Figure& newModel)
{
    details.push_back(newModel);
}

Figure& Scene::getModel(const int& idx)
{
    return details[idx];
}

void Scene::editModel(const int& idx, Vector3f& center, Vector3f& scale, Vector3f& rotate)
{
    details[idx].setCenter(center);
    details[idx].scale(scale);
    details[idx].rotate(rotate);
}



int Scene::countSprites()
{
    return sprites.size();
}

void Scene::addSprite(const Sprite& sprite, const Vector3f& scale,
                         const Vector3f& end, const float& speed)
{
    sprites.push_back(sprite);
    sprites.back().scale(scale);
    sprites.back().setPath(end, speed);
}

Sprite& Scene::getSprite(const int& idx)
{
    return sprites[idx];
}

void Scene::editSprite(const int& idx, Vector3f& cntr, Vector3f& scl, Vector3f& rt, Vector3f& end, const float& sp)
{
    sprites[idx].setCenter(cntr);
    sprites[idx].scale(scl);
    sprites[idx].rotate(rt);
    sprites[idx].setPath(end, sp);
}

void Scene::editSprite(const int& idx, Vector3f& cntr, Vector3f& scl, Vector3f& rt)
{
    sprites[idx].setCenter(cntr);
    sprites[idx].scale(scl);
    sprites[idx].rotate(rt);
}

void Scene::updateSpriteCenter(const int& idx)
{
    if (!sprites[idx].isReachedEnd())
        sprites[idx].updatePath();
}



void Scene::addLightSource(const Vector3f& lPos, const float& lPower)
{
    lightSources.push_back(LightSourcePoint(lPos, lPower));
}

LightSourcePoint& Scene::getLightSource(const int& idx)
{
    return lightSources[idx];
}

int Scene::getLightSourceCount()
{
    return lightSources.size();
}

void Scene::editLight(const int& idx, const Vector3f& pos, const float& power)
{
    lightSources[idx].setPosition(pos);
    lightSources[idx].setIntensity(power);
}



// Camera methods
Camera&   Scene::getCamera()
{
    return mainCamera;
}

void      Scene::setCamera(const Vector3f& pos, const Vector3f& view, const Vector3f& up)
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



void    Scene::upDownCamera(const float& speed)
{
    Vector3f pos = mainCamera.getPosition();

    if (fabs(pos.y + speed) < 1.25)
        mainCamera.upDown(speed);
}

void    Scene::rotateCamera(const float& speed)
{
    mainCamera.rotateView(speed);
}

void    Scene::strafeCamera(const float& speed)
{
    mainCamera.update();
    mainCamera.strafe(speed);
}

void    Scene::movingCamera(const float& speed)
{
    mainCamera.move(speed);
}
