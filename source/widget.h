#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "figure.h"
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
    void on_Scaling_clicked();
    void on_Rotation_clicked();

    void on_addDetail_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;

    Detail *detail;
    Point figureArray[7];
};

#endif // WIDGET_H
