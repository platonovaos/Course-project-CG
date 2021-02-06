#include "viewportwidget.h"
#include <GL/glut.h>

ViewportWidget::ViewportWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    NumDetails = 0;
    SceneRt = false;
    sceneRotate = initEmptyPoint();

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(16);
}

ViewportWidget::~ViewportWidget()
{

}

void ViewportWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    static GLfloat lightPosition[4] = { 0, 10, 0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void ViewportWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    for (int i = 0; i < NumDetails; i++) {
        Detail curDetail = Details[i];

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt( 0,0,5,  0,0,0,  0,1,0 );

        glColor3f(1.0, 0.0, 0.0);

        rotateScene();
        moveDetail(curDetail);
        rotateDetail(curDetail);
        paintDetail(curDetail);
    }
}

void ViewportWidget::rotateScene()
{
    glRotated(sceneRotate.X, 1, 0, 0);
    glRotated(sceneRotate.Y, 0, 1, 0);
    glRotated(sceneRotate.Z, 0, 0, 1);
}

void ViewportWidget::moveDetail(Detail detail)
{
    Point move = detail.getMove();

    glTranslatef(move.X, move.Y, move.Z);
}

void ViewportWidget::rotateDetail(Detail detail)
{
    Point rotate = detail.getRotate();

    glRotatef(rotate.X, 1, 0, 0);
    glRotatef(rotate.Y, 0, 1, 0);
    glRotatef(rotate.Z, 0, 0, 1);
}

void ViewportWidget::paintDetail(Detail detail)
{
    switch (detail.getType()) {
    case cube:
        glutSolidCube(0.5);
        break;

    case sphere:
        glutSolidSphere(0.25, 20, 20);
        break;

    case cone:
        glutSolidCone(0.25, 0.25, 16, 8);
        break;

    case torus:
        glutSolidTorus(0.05, 0.20, 16, 16);
        break;

    default:
        break;
    }
}

void ViewportWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)w/h, 0.01, 100.0);

    update();
}

void ViewportWidget::mousePressEvent(QMouseEvent *pe)
{
    mousePos = pe->pos();
}

void ViewportWidget::mouseMoveEvent(QMouseEvent *pe)
{
    Point rt = initEmptyPoint();
    rt.X += 180 * (pe->y() - mousePos.y()) / height();
    rt.Z += 180 * (pe->x() - mousePos.x()) / width();

    if (SceneRt) {
        sceneRotate.X += rt.X;
        sceneRotate.Y += rt.Y;
        sceneRotate.Z += rt.Z;
    }
    else {
        Details[NumDetails - 1].setRotate(rt);
    }

    mousePos = pe->pos();

    update();
}

void ViewportWidget::addDetail(DetailType type)
{
    Details[NumDetails].setType(type);
    NumDetails += 1;
}

void ViewportWidget::removeDetail()
{
    if (NumDetails > 0) {
        NumDetails--;
    }

    Details[NumDetails].setType(emptyD);
}

