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
    initializeRotationAxisBox();
    initializeTypeDetailBox();

    scene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены
    scene->setBackgroundBrush(Qt::black);

    NumDetails = 0;
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


}

void Widget::initializeRotationAxisBox()
{
    ui->rotationAxis->addItem("");
    ui->rotationAxis->addItem("Ось OX");
    ui->rotationAxis->addItem("Ось OY");
    ui->rotationAxis->addItem("Ось OZ");
}

void Widget::initializeTypeDetailBox()
{
    ui->typeDetailBox->addItem("");
    ui->typeDetailBox->addItem("Куб");
    ui->typeDetailBox->addItem("Сфера");
    ui->typeDetailBox->addItem("Пирамида");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addDetail_clicked()
{
    TypeDetail type = defineType(ui->typeDetailBox->currentText());

    Detail *curDetail = new Detail(type);
    curDetail->setPos(290, 220);
    curDetail->setFlag(QGraphicsItem::ItemIsSelectable);
    scene->addItem(curDetail);

    Details.push_back(curDetail);
    NumDetails++;
}

void Widget::on_removeDetail_clicked()
{
    if (NumDetails > 0) {
        Detail *curDetail = Details[NumDetails - 1];
        scene->removeItem(curDetail);

        Details.pop_back();
        NumDetails--;
    }
}

void Widget::on_Rotation_clicked()
{
    Detail *curDetail = Details[NumDetails - 1];
    int exitCode = rotate(*curDetail, ui->rotationAxis->currentText(), ui->tr_rotate_line->text());

    if (exitCode == EMPTY_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры поворота не могут быть пустыми!");
        return;
    }
    if (exitCode == INCORRECT_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры поворота могут содержать только числа, '-' и '.'!");
        return;
    }

    scene->update();
}

void Widget::on_zBuffer_clicked()
{

}
