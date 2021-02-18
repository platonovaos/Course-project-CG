#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "transformDetail.h"
#include "zbuffer.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void initializeUi();
        void initializeRotationAxisBox();
        void initializeTypeDetailBox();
    ~Widget();

private slots:
    void on_addDetail_clicked();
    void on_removeDetail_clicked();

    void on_Rotation_clicked();
    void on_zBuffer_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;

    int NumDetails;
    QVector<Detail*> Details;
};

#endif // WIDGET_H
