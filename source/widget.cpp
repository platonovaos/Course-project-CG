#include "widget.h"
#include "ui_widget.h"

using namespace std;
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();       // Инициализируем графическую сцену

    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    figureArray[0].X = -100; figureArray[0].Y = 100;
    figureArray[1].X = -100; figureArray[1].Y = -100;
    figureArray[2].X = 100; figureArray[2].Y = -100;
    figureArray[3].X = 100; figureArray[3].Y = 100;
    figureArray[4].X = -50; figureArray[4].Y = -150;
    figureArray[5].X = 150; figureArray[5].Y = -150;
    figureArray[6].X = 150; figureArray[6].Y = 50;

    figure = new Figure(figureArray);
    scene->addItem(figure);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Carryover_clicked()
{
    scene->clear();

    int exitCode = carryover(figureArray, ui->x_carry_line->text(), ui->y_carry_line->text());

    if (exitCode == EMPTY_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры переноса не могут быть пустыми!");
        return;
    }
    if (exitCode == INCORRECT_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры переноса могут содержать только числа, '-' и '.'!");
        return;
    }

    figure = new Figure(figureArray);
    scene->addItem(figure);
}

void Widget::on_Scaling_clicked()
{
    scene->clear();

    int exitCode = scale(figureArray, ui->kx_scale_line->text(), ui->ky_scale_line->text(),
                                        ui->x_scale_line->text(), ui->y_scale_line->text());

    if (exitCode == EMPTY_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры масштабирования не могут быть пустыми!");
        return;
    }
    if (exitCode == INCORRECT_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры масштабирования могут содержать только числа, '-' и '.'!");
        return;
    }

    figure = new Figure(figureArray);
    scene->addItem(figure);
}

void Widget::on_Rotation_clicked()
{
    scene->clear();

    int exitCode = rotate(figureArray, ui->tr_rotate_line->text(),
                                        ui->x_rotate_line->text(), ui->y_rotate_line->text());

    if (exitCode == EMPTY_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры поворота не могут быть пустыми!");
        return;
    }
    if (exitCode == INCORRECT_POINT) {
        QMessageBox::warning(this, "Ошибка", "Параметры поворота могут содержать только числа, '-' и '.'!");
        return;
    }

    figure = new Figure(figureArray);
    scene->addItem(figure);
}
