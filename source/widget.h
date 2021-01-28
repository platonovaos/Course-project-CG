#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

#include "figure.h"
#include "carryover.h"
#include "scaling.h"
#include "rotation.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Carryover_clicked();
    void on_Scaling_clicked();
    void on_Rotation_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Figure *figure;
    Point figureArray[7];
};

#endif // WIDGET_H
