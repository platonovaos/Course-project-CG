#ifndef ADDMODELWINDOW_H
#define ADDMODELWINDOW_H

#include <QDialog>
#include <QFileDialog>
#include <QColorDialog>

#include <cstdlib>

struct AddModelParameters
{
    float moveX, moveY, moveZ;
    float scaleX, scaleY, scaleZ;

    QString filename;
    QString modelName;

    QColor color;

    float enX, enY, enZ;
    float speed;
};

namespace Ui {
class AddModelWindow;
}

class AddModelWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddModelWindow(int, QDialog *parent = nullptr);
    AddModelParameters getParameters();
    ~AddModelWindow();

private:
    Ui::AddModelWindow *ui;
    AddModelParameters params;

    int modelCnt;

private slots:
    void okButton();

signals:
    void saveModelParams(AddModelParameters&);
};

#endif // ADDMODELWINDOW_H
