#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QKeyEvent>
#include <string>
#include <chrono>

#include "detail.h"
#include "light.h"
#include "MathObjects/vector3.h"
#include "drawer.h"

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

    int numDetails, numLight;

    std::vector<Vector3f> centersD;
    std::vector<Vector3f> lightPos;

    void initDrawer();
    void initDetailChanges();
    void initLightChanges();

    void keyPressEvent(QKeyEvent *event);

    Detail *detail;
    Light *light;

private slots:
    void on_addDetail_clicked();
    void on_removeDetail_clicked();
    void on_changeDetail_clicked();

    void on_addLight_clicked();
    void on_changeLight_clicked();
};
#endif // MAINWINDOW_H
