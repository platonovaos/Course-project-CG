#ifndef VIEWPORTWIDGET_H
#define VIEWPORTWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QTimer>
#include <QDebug>

#include "detail.h"

class ViewportWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit ViewportWidget(QWidget *parent = nullptr);
    ~ViewportWidget() override;

    void addDetail(DetailType type);
    void removeDetail();

    int NumDetails;
    QVector<Detail> Details;

    bool SceneRt;

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
        void rotateScene();
        void moveDetail(Detail detail);
        void rotateDetail(Detail detail);
        void paintDetail(Detail detail);

    void resizeGL(int w, int h) Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent *pe) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *pe) Q_DECL_OVERRIDE;

private:
    QTimer timer;
    QPoint mousePos;
    Point sceneRotate;
};

#endif // VIEWPORTWIDGET_H
