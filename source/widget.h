#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "transformDetail.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void initializeUi();
    ~Widget();

private slots:
    void on_Rotation_clicked();
    void on_addDetail_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;

    Detail *detail;
    QVector<Detail> activeDetails;
};

#endif // WIDGET_H
