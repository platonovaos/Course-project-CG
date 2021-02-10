#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QKeyEvent>

#include <string>
#include <chrono>

#include "drawer.h"
#include "addmodelwindow.h"
#include "addlightwindow.h"

#include "MathObjects/vector3.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Drawer *drawer;

    int modelCnt, spriteCnt, lightCnt;

    std::vector<Vector3f> centersM;
    std::vector<Vector3f> centersS;
    std::vector<Vector3f> lightPos;

    void initDrawer();
    void initLables();
    void initButton();

    void keyPressEvent(QKeyEvent *event);

    AddModelWindow *addModelWindow;
    AddModelParameters addModelparams;

    AddLightWindow *addLightWindow;
    AddLightParameters addLightParams;

private slots:


    // Model
    void changeModel();
    void applyModelChange();
    void cancelLineEditsModel();

    // Sprite
    void changeSprite();
    void applySpriteChange();
    void cancelLineEditsSprite();

    // Light
    void changeLight();
    void applyLightChange();
    void cancelLineEditsLight();

    // Window
    void setAddModelParams(AddModelParameters&);

    void openAddLightWindow();
    void setLightParams(AddLightParameters&);
    void on_pushButton_addModel_clicked();
};
#endif // MAINWINDOW_H
