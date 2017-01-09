#include "interface.h"
#include "ui_interface.h"
#include "QtWidgets"
#include "tree.h"


Interface::Interface(tree *model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{


    ui->setupUi(this);
    ui->treeView->setModel(model);

}


Interface::~Interface()
{
    delete ui;
}
