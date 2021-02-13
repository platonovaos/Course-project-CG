#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

int frames = 0;
auto frameTime = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Lego");
    this->resize(1025, 829);

    ui->centralwidget->setStyleSheet("QWidget {background: rgba(250, 250, 250, 255);}");

    initDrawer();
    initDetailChanges();
    initLightChanges();

    numDetails = 0;
    numSprite = 0;
    numLight = 0;

    lightPos.push_back(Vector3f(100, 1000, 100));
    drawer->addLight(Vector3f(100, 1000, 100), 1300);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::initDrawer()
{
    int w = ui->graphicsView->width();
    int h = ui->graphicsView->height();

    drawer = new Drawer(w, h, this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setAlignment(Qt::AlignCenter);

    ui->graphicsView->setScene(drawer);
}

void MainWindow::initDetailChanges()
{
    ui->dMoveX->setText("0");
    ui->dMoveY->setText("0");
    ui->dMoveZ->setText("0");

    ui->dScaleX->setText("1");
    ui->dScaleY->setText("1");
    ui->dScaleZ->setText("1");

    ui->dRotateX->setText("0");
    ui->dRotateY->setText("0");
    ui->dRotateZ->setText("0");
}

void MainWindow::initLightChanges()
{
    ui->lMoveX->setText("100");
    ui->lMoveY->setText("100");
    ui->lMoveZ->setText("100");

    ui->lPower->setText("200");
}


//Detail
void MainWindow::on_addDetail_clicked()
{
    detail = new Detail(numDetails);
    DetailParams params = detail->getParameters();

    Vector3f center(params.move.X, params.move.Y, params.move.Z);
    Vector3f scale(params.scale.X, params.scale.Y, params.scale.Z);

    drawer->addDetail(center, scale, params.filename, params.color);

    centersD.push_back(center);
    numDetails++;

    frames = 0;
    frameTime = 0;
    drawer->draw();
}

void MainWindow::on_removeDetail_clicked()
{
    if (numDetails <= 0) {
        return;
    }

    numDetails--;
    drawer->removeDetail();

    drawer->draw();

    initDetailChanges();
}

void MainWindow::on_changeDetail_clicked()
{
    if (centersD.size() == 0) {
        return;
    }

    int idx = numDetails - 1;

    Vector3f center, scale, rotate;

    //move
    QString moveXStr = ui->dMoveX->text();
    QString moveYStr = ui->dMoveY->text();
    QString moveZStr = ui->dMoveZ->text();

    if (moveXStr.isEmpty() || moveYStr.isEmpty() || moveZStr.isEmpty()) {
        center = Vector3f(centersD[idx]);
    }
    else {
        center = Vector3f(moveXStr.toFloat(), moveYStr.toFloat(), moveZStr.toFloat());
    }

    //scale
    QString scaleXStr = ui->dScaleX->text();
    QString scaleYStr = ui->dScaleY->text();
    QString scaleZStr = ui->dScaleZ->text();

    if (scaleXStr.isEmpty() || scaleYStr.isEmpty() || scaleZStr.isEmpty()) {
        scale = Vector3f(1, 1, 1);
    }
    else {
        scale = Vector3f(scaleXStr.toFloat(), scaleYStr.toFloat(), scaleZStr.toFloat());
    }

    //rotate
    QString rotateXStr = ui->dRotateX->text();
    QString rotateYStr = ui->dRotateY->text();
    QString rotateZStr = ui->dRotateZ->text();

    if (rotateXStr.isEmpty() || rotateYStr.isEmpty() || rotateZStr.isEmpty()) {
        rotate = Vector3f(0, 0, 0);
    }
    else {
        rotate = Vector3f(rotateXStr.toFloat(), rotateYStr.toFloat(), rotateZStr.toFloat());
    }

    drawer->editDetail(idx, center, scale, rotate);
    drawer->draw();
    initDetailChanges();
}

void MainWindow::on_addLight_clicked()
{
    light = new Light(numLight);
    LightParams params = light->getParameters();

    Vector3f pos(params.set.X, params.set.Y, params.set.Z);
    drawer->addLight(pos, params.power);

    lightPos.push_back(pos);

    drawer->draw();
}

void MainWindow::on_changeLight_clicked()
{
    if (lightPos.size() == 0) {
        return;
    }

    int idx = numLight - 1;
    Vector3f pos;

    QString moveXStr = ui->lMoveX->text();
    QString moveYStr = ui->lMoveX->text();
    QString moveZStr = ui->lMoveX->text();

    if (moveXStr.isEmpty() || moveYStr.isEmpty() || moveZStr.isEmpty()) {
        pos = lightPos[idx];
    }
    else {
        pos = Vector3f(moveXStr.toFloat(), moveYStr.toFloat(), moveZStr.toFloat());
    }

    QString powerStr = ui->lPower->text();
    if (powerStr.isEmpty()) {
        drawer->editLight(idx, pos);
    }
    else {
        drawer->editLight(idx, pos, ui->lPower->text().toFloat());
    }

    drawer->draw();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    switch (key)
    {
    case Qt::Key_W:
        drawer->movingCamera(1);
        break;
    case Qt::Key_S:
        drawer->movingCamera(-1);
        break;
    case Qt::Key_A:
        drawer->strafeCamera(-0.5);
        break;
    case Qt::Key_D:
        drawer->strafeCamera(0.5);
        break;

    case Qt::Key_I:
        drawer->upDownCamera(0.25);
        break;
    case Qt::Key_J:
        drawer->rotateCamera(-0.05);
        break;
    case Qt::Key_K:
        drawer->upDownCamera(-0.25);
        break;
    case Qt::Key_L:
        drawer->rotateCamera(0.05);
        break;
    }

    drawer->draw();
}
