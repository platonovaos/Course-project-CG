#ifndef DRAWER_H
#define DRAWER_H

#include <QImage>
#include <QGraphicsScene>

#include <cmath>
#include <string>

#include "zbuffer.h"
#include "scene.h"

#define FAULT 500

class Drawer : public QGraphicsScene
{
    Q_OBJECT

private:
    int w, h;

    Scene scene;
    QColor bgColor = QColor(0, 0, 0);

    QImage canvas;

    void initCanvas();
    void clearCanvas();
    void updateCanvas();

    ZBuffer zBuffer;

    void initZBuffer();
    void clearZBuffer();

    std::vector<std::vector<QColor>> colorCache;

    void initColorCache();
    void clearColorCache();

    void updateScreen();
    void clearScreen();


    void  objectProcessing(Model&, Vector3f&, Vector3f&, Vector3f&);
    float lightProcessing(const Vector3f&, const Vector3f&);
    void  triangleProcessing(Vector3i&, Vector3i&, Vector3i&,
                            const QColor&, float&, float&, float&);

    int  wPerm, hPerm;
    bool isVisible(const Vector3i&);

public:
    explicit Drawer(const int&, const int&, QObject *parent = nullptr);
    ~Drawer();

    void draw();

    void addDetail(Vector3f&, Vector3f&, QString&, QColor&);
    void editDetail(const int&, Vector3f&, Vector3f&, Vector3f&);

    void addLight(const Vector3f&, const float&);
    void editLight(const int&, const Vector3f&, const float& power = 500);

    void upDownCamera(const float&);
    void rotateCamera(const float&);
    void strafeCamera(const float&);
    void movingCamera(const float&);
};

inline QRgb iColor(const QRgb& a, const float& i);

#endif // DRAWER_H
