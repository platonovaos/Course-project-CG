#include "viewportwidget.h"
#include <GL/glut.h>

ViewportWidget::ViewportWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    numDetails = 0;

    move = initEmptyPoint();
    rotate = initEmptyPoint();

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

    for (int i = 0; i < numDetails; i++) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt( 0,0,5,  0,0,0,  0,1,0 );

        glColor3f(1.0, 0.0, 0.0);

        glTranslatef(move.X, move.Y, move.Z);

        glRotatef(rotate.X, 1, 0, 0);
        glRotatef(rotate.Y, 0, 1, 0);
        glRotatef(rotate.Z, 0, 0, 1);

        switch (details[i]) {
            case cube:
                glutSolidCube(0.5);
            break;

            case sphere:
                glutWireSphere(0.5, 20, 20);
            break;

            case cone:
                glutWireCone(0.2, 0.75, 16, 8);
            break;

            case torus:
                glutWireTorus(0.15, 0.65, 16, 16);
            break;

            default:
                break;
        }
    }

}

void ViewportWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45.0, (GLdouble)w/h, 0.01, 100.0 );

    update();
}

void ViewportWidget::mousePressEvent(QMouseEvent *pe)
{
    mousePos = pe->pos();
}

void ViewportWidget::mouseMoveEvent(QMouseEvent *pe)
{
    rotate.X += 180 * (GLfloat)(pe->y() - mousePos.y()) / height();
    rotate.Z += 180 * (GLfloat)(pe->x() - mousePos.x()) / width();

    mousePos = pe->pos();

    update();
}

void ViewportWidget::mouseReleaseEvent(QMouseEvent *pe)
{
}

void ViewportWidget::keyPressEvent(QKeyEvent *pe)
{
    qDebug() << "key";

    if (pe->key() == Qt::Key_Left) {
        move.X -= 1;
    }

    if (pe->key() == Qt::Key_Right) {
        move.X += 1;
    }

    if (pe->key() == Qt::Key_Down) {
        move.Y -= 1;
    }

    if (pe->key() == Qt::Key_Up) {
        move.Y += 1;
    }

    update();
}

