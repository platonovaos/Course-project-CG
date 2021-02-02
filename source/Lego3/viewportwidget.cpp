#include "viewportwidget.h"
#include <GL/glut.h>


ViewportWidget::ViewportWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    wireframe = true;
    addDetail = false;

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(16);
}

ViewportWidget::~ViewportWidget()
{

}

void ViewportWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 0);

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

    if (addDetail) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt( 0,0,5,  0,0,0,  0,1,0 );

        glColor3f(1.0, 0.0, 0.0);
        glRotatef(0, 1, 1, 1);

        if (wireframe)
            glutWireSphere(0.5, 20, 20);
        else
            glutSolidSphere(0.5, 20, 20);
    }

}

void ViewportWidget::resizeGL(int w, int h)
{
    glViewport(0,0, w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45.0, (float)w/h, 0.01, 100.0 );

    update();
}
