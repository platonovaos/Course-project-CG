#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Exit_triggered(bool checked)
{
    this->close();
}

void MainWindow::on_addDetail_clicked()
{
    ui->mOpenGLViewport->addDetail = true;
    update();
}
