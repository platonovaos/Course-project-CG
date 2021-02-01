#include "widget.h"
#include "ui_widget.h"

using namespace std;
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(1500, 800);
    this->setFixedSize(1500, 800);

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену

    initializeUi();
    scene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены
}

void Widget::initializeUi()
{
    ui->graphicsView->resize(1150, 780);
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    ui->rotationAxis->addItem("");
    ui->rotationAxis->addItem("Ось OX");
    ui->rotationAxis->addItem("Ось OY");
    ui->rotationAxis->addItem("Ось OZ");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Rotation_clicked()
{
    scene->clear();

    int exitCode = rotate(*detail, ui->rotationAxis->currentText(), ui->tr_rotate_line->text());

    if (exitCode == EMPTY_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры поворота не могут быть пустыми!");
        return;
    }
    if (exitCode == INCORRECT_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры поворота могут содержать только числа, '-' и '.'!");
        return;
    }

    Point figureArray[4];
    for (int i = 0; i < detail->getNumPoints(); i++) {
        figureArray[i] = detail->getPoint(i);
    }
    detail = new Detail(4, figureArray);
    scene->addItem(detail);
}

void Widget::on_addDetail_clicked()
{
    Point figureArray[4];
    initializeCube(figureArray);

    detail = new Detail(4, figureArray);

    detail->setPos(290, 220);
    detail->setFlag(QGraphicsItem::ItemIsSelectable);
    scene->addItem(detail);
}
