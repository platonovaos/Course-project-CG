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

    scene = new QGraphicsScene(this);   // �������������� ����������� �����

    initializeUi();
    scene->setSceneRect(0,0,500,500); // ������������� ������ �����
}

void Widget::initializeUi()
{
    ui->graphicsView->resize(1150, 780);
    ui->graphicsView->setScene(scene);  // ������������� ����������� ����� � graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // ������������� �����������
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // ��� ����
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // ��������� ��������� �� ���������
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // ��������� ��������� �� �����������
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Scaling_clicked()
{
    scene->clear();

    int exitCode = scale(figureArray, ui->kx_scale_line->text(), ui->ky_scale_line->text());

    if (exitCode == EMPTY_POINT) {
        QMessageBox::warning(this, "������", "��������� ��������������� �� ����� ���� �������!");
        return;
    }
    if (exitCode == INCORRECT_POINT) {
        QMessageBox::warning(this, "������", "��������� ��������������� ����� ��������� ������ �����, '-' � '.'!");
        return;
    }

    detail = new Detail(figureArray);
    scene->addItem(detail);
}

void Widget::on_Rotation_clicked()
{
    scene->clear();

    int exitCode = rotate(figureArray, ui->tr_rotate_line->text());

    if (exitCode == EMPTY_POINT) {
        QMessageBox::warning(this, "������", "��������� �������� �� ����� ���� �������!");
        return;
    }
    if (exitCode == INCORRECT_POINT) {
        QMessageBox::warning(this, "������", "��������� �������� ����� ��������� ������ �����, '-' � '.'!");
        return;
    }

    detail = new Detail(figureArray);
    scene->addItem(detail);
}

void Widget::on_addDetail_clicked()
{
    figureArray[0].X = -30; figureArray[0].Y = -30;
    figureArray[1].X = -30; figureArray[1].Y = 30;
    figureArray[2].X = 30; figureArray[2].Y = 30;
    figureArray[3].X = 30; figureArray[3].Y = -30;

    detail = new Detail(figureArray);

    detail->setPos(0, 0);
    detail->setFlag(QGraphicsItem::ItemIsSelectable);
    scene->addItem(detail);
}
