#include "addmodelwindow.h"
#include "ui_addmodelwindow.h"

AddModelWindow::AddModelWindow(int modelCnt, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AddModelWindow),
    modelCnt(modelCnt)
{
    ui->setupUi(this);
    this->setWindowTitle("Add new Model");
    this->resize(328, 289);

    params.filename = "/home/main/foog/cube.h";
    params.modelName = ("model_" + std::to_string(modelCnt)).c_str();

    params.moveX = 0;
    params.moveY = 0;
    params.moveZ = 0;

    params.scaleX = 1;
    params.scaleY = 1;
    params.scaleZ = 1;

    params.color = Qt::red;

    //connect(ui->pushButton_ok, SIGNAL(released()), this, SLOT(okButton()));
    //emit saveModelParams(params);
}

AddModelWindow::~AddModelWindow()
{
    delete ui;
}

void AddModelWindow::okButton()
{
    params.filename = "/home/main/foog/cube.h";
    params.modelName = ("model_" + std::to_string(modelCnt)).c_str();

    params.moveX = 0;
    params.moveY = 0;
    params.moveZ = 0;

    params.scaleX = 1;
    params.scaleY = 1;
    params.scaleZ = 1;

    params.color = Qt::red;

    emit saveModelParams(params);

    this->destroy();
}

AddModelParameters AddModelWindow::getParameters()
{
    return params;
}
