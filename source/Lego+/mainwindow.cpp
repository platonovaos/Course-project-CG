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
    initButton();

    // Combobox
    connect(ui->comboBox_model, SIGNAL(currentIndexChanged(QString)), SLOT(changeModel()));
    connect(ui->comboBox_light, SIGNAL(currentIndexChanged(QString)), SLOT(changeLight()));

    numDetails = 0;
    numSprite = 0;
    numLight = 0;

    lightPos.push_back(Vector3f(100, 1000, 100));
    drawer->addLight(Vector3f(100, 1000, 100), 1300);
    ui->comboBox_light->addItem("Main light");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::initDrawer()
{
    size_t w = ui->graphicsView->width();
    size_t h = ui->graphicsView->height();

    drawer = new Drawer(w, h, this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setAlignment(Qt::AlignCenter);

    ui->graphicsView->setScene(drawer);
}

void MainWindow::initButton()
{
    connect(ui->pushButton_mapply, SIGNAL(released()), this, SLOT(applyModelChange()));
    connect(ui->pushButton_mcancel, SIGNAL(released()), this, SLOT(cancelLineEditsModel()));

    connect(ui->pushButton_lapply, SIGNAL(released()), this, SLOT(applyLightChange()));
    connect(ui->pushButton_lcancel, SIGNAL(released()), this, SLOT(cancelLineEditsLight()));
}


// Model
void MainWindow::changeModel()
{
    int idx = ui->comboBox_model->currentIndex();
    Vector3f currentCenter = centersM[idx];

    ui->le_mmove_x->setText(std::to_string(currentCenter.x).c_str());
    ui->le_mmove_y->setText(std::to_string(currentCenter.y).c_str());
    ui->le_mmove_z->setText(std::to_string(currentCenter.z).c_str());

    ui->le_mscale_x->setText("1");
    ui->le_mscale_y->setText("1");
    ui->le_mscale_z->setText("1");

    ui->le_mrotate_x->setText("0");
    ui->le_mrotate_y->setText("0");
    ui->le_mrotate_z->setText("0");
}

void MainWindow::applyModelChange()
{
    if (centersM.size() == 0)
        return;

    int idx = ui->comboBox_model->currentIndex();

    Vector3f center, scale, rotate;

    // For move
    if (ui->le_mmove_x->text().isEmpty() ||
        ui->le_mmove_y->text().isEmpty() ||
        ui->le_mmove_z->text().isEmpty())
    {
        center = Vector3f(centersM[idx]);
    }
    else
    {
        center = Vector3f(ui->le_mmove_x->text().toFloat(),
                          ui->le_mmove_y->text().toFloat(),
                          ui->le_mmove_z->text().toFloat());
    }

    // For scale
    if (ui->le_mscale_x->text().isEmpty() ||
        ui->le_mscale_y->text().isEmpty() ||
        ui->le_mscale_z->text().isEmpty())
    {
        scale = Vector3f(1, 1, 1);
    }
    else
    {
        scale = Vector3f(ui->le_mscale_x->text().toFloat(),
                         ui->le_mscale_y->text().toFloat(),
                         ui->le_mscale_z->text().toFloat());
    }

    // For rotate
    if (ui->le_mrotate_x->text().isEmpty() ||
        ui->le_mrotate_y->text().isEmpty() ||
        ui->le_mrotate_z->text().isEmpty())
    {
        rotate = Vector3f(0, 0, 0);
    }
    else
    {
        rotate = Vector3f(ui->le_mrotate_x->text().toFloat(),
                          ui->le_mrotate_y->text().toFloat(),
                          ui->le_mrotate_z->text().toFloat());
    }

    drawer->editDetail(idx, center, scale, rotate);
    drawer->draw();
}

void MainWindow::cancelLineEditsModel()
{
    int idx = ui->comboBox_model->currentIndex();
    Vector3f currentCenter = centersM[idx];

    ui->le_lmove_x->setText(std::to_string(currentCenter.x).c_str());
    ui->le_lmove_y->setText(std::to_string(currentCenter.y).c_str());
    ui->le_lmove_z->setText(std::to_string(currentCenter.z).c_str());

    ui->le_mscale_x->setText("1");
    ui->le_mscale_y->setText("1");
    ui->le_mscale_z->setText("1");

    ui->le_mrotate_x->setText("0");
    ui->le_mrotate_y->setText("0");
    ui->le_mrotate_z->setText("0");
}

// Light
void MainWindow::changeLight()
{
    int idx = ui->comboBox_light->currentIndex();
    Vector3f currentCenter = lightPos[idx];

    ui->le_lmove_x->setText(std::to_string(currentCenter.x).c_str());
    ui->le_lmove_y->setText(std::to_string(currentCenter.y).c_str());
    ui->le_lmove_z->setText(std::to_string(currentCenter.z).c_str());

    ui->le_power->setText("500");
}

void MainWindow::applyLightChange()
{
    if (lightPos.size() == 0)
        return;

    int idx = ui->comboBox_light->currentIndex();
    Vector3f pos;

    if (ui->le_lmove_x->text().isEmpty() ||
        ui->le_lmove_y->text().isEmpty() ||
        ui->le_lmove_z->text().isEmpty())
    {
        pos = lightPos[idx];
    }
    else
    {
        pos = Vector3f(ui->le_lmove_x->text().toFloat(),
                       ui->le_lmove_y->text().toFloat(),
                       ui->le_lmove_z->text().toFloat());
    }

    if (ui->le_power->text().isEmpty())
        drawer->editLight(idx, pos);
    else
        drawer->editLight(idx, pos, ui->le_power->text().toFloat());

    drawer->draw();
}

void MainWindow::cancelLineEditsLight()
{
    int idx = ui->comboBox_light->currentIndex();
    Vector3f currentCenter = lightPos[idx];

    ui->le_lmove_x->setText(std::to_string(currentCenter.x).c_str());
    ui->le_lmove_y->setText(std::to_string(currentCenter.y).c_str());
    ui->le_lmove_z->setText(std::to_string(currentCenter.z).c_str());

    ui->le_power->setText("200");
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



// Add new model
void MainWindow::on_addDetail_clicked()
{
    addModelWindow = new Detail(numDetails);
    DetailParams params = addModelWindow->getParameters();
    setAddModelParams(params);
}

void MainWindow::setAddModelParams(DetailParams& newParams)
{
    Vector3f center(newParams.move.X, newParams.move.Y, newParams.move.Z);

    drawer->addDetail(center, newParams.filename, newParams.color);

    centersM.push_back(center);
    ui->comboBox_model->addItem(newParams.detailName);

    numDetails++;

    frames = 0;
    frameTime = 0;
    drawer->draw();
}


// Add new light
void MainWindow::on_pushButton_addLight_clicked()
{
    addLightWindow = new Light(numLight);
    LightParams params = addLightWindow->getParameters();
    setLightParams(params);
}

void MainWindow::setLightParams(LightParams& newParams)
{
    Vector3f pos(newParams.set.X, newParams.set.Y, newParams.set.Z);
    drawer->addLight(pos, newParams.power);

    lightPos.push_back(pos);
    ui->comboBox_light->addItem(newParams.name);

    drawer->draw();
}
