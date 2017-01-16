#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <tree.h>
#include "QtWidgets"
namespace Ui {
class Interface;
}

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface( tree *model, QWidget *parent = 0);
    ~Interface();
private slots:
    virtual void SlotCurrentPic(QModelIndex index);
    virtual void SetTextLabel(QModelIndex index);
    void NextImage();
    void PrevImage();
    void ZoomIn();
    void ZoomOut();
    void RotateImage();
private:
    void SetPicToGView(QPixmap outPixmap);
    Ui::Interface *ui;
};

#endif // INTERFACE_H
