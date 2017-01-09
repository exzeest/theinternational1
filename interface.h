#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <tree.h>

namespace Ui {
class Interface;
}

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface( tree *model, QWidget *parent = 0);
    ~Interface();

private:
    Ui::Interface *ui;
};

#endif // INTERFACE_H
