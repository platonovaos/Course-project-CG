#ifndef VIEWPORTWIDGET_H
#define VIEWPORTWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QTimer>
#include <QDebug>

#include "point.h"

class ViewportWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit ViewportWidget(QWidget *parent = nullptr);
    ~ViewportWidget() override;

    int numDetails;
    Detail details[10];

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent *pe) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *pe) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *pe) Q_DECL_OVERRIDE;

    void keyPressEvent(QKeyEvent *pe) Q_DECL_OVERRIDE;

private:
    QTimer timer;
    QPoint mousePos;

    Point move;
    Point rotate;
};

#endif // VIEWPORTWIDGET_H
