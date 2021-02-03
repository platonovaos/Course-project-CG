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

//Взаимодействие с пользователем
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
    addOffset(ui->mOpenGLViewport->move, offset, axis);
}

void MainWindow::on_addDetail_clicked()
{
    int numDetails = ui->mOpenGLViewport->numDetails;
    TypeDetail type = defineType(ui->typeDetailBox->currentText());

    ui->mOpenGLViewport->numDetails += 1;
    ui->mOpenGLViewport->details[numDetails] = type;

    update();
}

/*void MainWindow::on_removeDetail_clicked()
{
    int numDetails = ui->mOpenGLViewport->numDetails;
    TypeDetail *details = ui->mOpenGLViewport->details;
    TypeDetail type = defineType(ui->typeDetailBox->currentText());

    int removeIdx = removeDetail(numDetails, details, type);

    if (removeIdx > 0 && removeIdx < numDetails) {
        ui->mOpenGLViewport->numDetails = numDetails - 1;
        ui->mOpenGLViewport->details[removeIdx] = emptyD;
    }

    qDebug() << removeIdx;

    update();
}
*/
