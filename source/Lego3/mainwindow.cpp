#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(1500, 800);
    this->setFixedSize(1500, 800);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,500,500);

    initializeRotateAxisBox();
    initializeAddDetailBox();

    ui->rotateDetail->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeRotateAxisBox()
{
    ui->moveAxisBox->addItem("");
    ui->moveAxisBox->addItem("Ось OX");
    ui->moveAxisBox->addItem("Ось OY");
    ui->moveAxisBox->addItem("Ось OZ");
}

void MainWindow::initializeAddDetailBox()
{
    ui->typeDetailBox->addItem("");
    ui->typeDetailBox->addItem("Куб");
    ui->typeDetailBox->addItem("Сфера");
    ui->typeDetailBox->addItem("Конус");
    ui->typeDetailBox->addItem("Тор");
}


void MainWindow::keyPressEvent(QKeyEvent *pe)
{
    float offset = 0;

    if (pe->key() == Qt::Key_Left) {
        offset = -0.5;
    }

    if (pe->key() == Qt::Key_Right) {
        offset = 0.5;
    }

    Axis axis = defineAxis(ui->moveAxisBox->currentText());

    int currentDetail = (ui->mOpenGLViewport->NumDetails) - 1;
    (ui->mOpenGLViewport->Details[currentDetail]).setMove(offset, axis);
}

void MainWindow::on_addDetail_clicked()
{
    DetailType type = defineType(ui->typeDetailBox->currentText());
    ui->mOpenGLViewport->addDetail(type);

    update();
}

void MainWindow::on_removeDetail_clicked()
{
    ui->mOpenGLViewport->removeDetail();
    update();
}

void MainWindow::on_rotateDetail_clicked()
{
    ui->rotateScene->setChecked(false);
    ui->mOpenGLViewport->SceneRt = false;
}

void MainWindow::on_rotateScene_clicked()
{
    ui->rotateDetail->setChecked(false);
    ui->mOpenGLViewport->SceneRt = true;

    update();
}
