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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeRotateAxisBox()
{
    ui->rotateAxisBox->addItem("");
    ui->rotateAxisBox->addItem("Ось OX");
    ui->rotateAxisBox->addItem("Ось OY");
    ui->rotateAxisBox->addItem("Ось OZ");
}

void MainWindow::initializeAddDetailBox()
{
    ui->typeDetailBox->addItem("");
    ui->typeDetailBox->addItem("Куб");
    ui->typeDetailBox->addItem("Сфера");
    ui->typeDetailBox->addItem("Конус");
    ui->typeDetailBox->addItem("Тор");
}

void MainWindow::on_addDetail_clicked()
{
    int numDetails = ui->mOpenGLViewport->numDetails;
    Detail typeDetail = defineType(ui->typeDetailBox->currentText());

    ui->mOpenGLViewport->numDetails += 1;
    ui->mOpenGLViewport->details[numDetails] = typeDetail;

    update();
}

void MainWindow::on_removeDetail_clicked()
{
    int numDetails = ui->mOpenGLViewport->numDetails;
    Detail *details = ui->mOpenGLViewport->details;
    Detail typeDetail = defineType(ui->typeDetailBox->currentText());

    int removeIdx = removeDetail(numDetails, details, typeDetail);

    if (removeIdx > 0 && removeIdx < numDetails) {
        ui->mOpenGLViewport->numDetails = numDetails - 1;
        ui->mOpenGLViewport->details[removeIdx] = empty;
    }

    qDebug() << removeIdx;

    update();
}
