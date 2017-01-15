#include "interface.h"
#include "ui_interface.h"
#include "QtWidgets"
#include "tree.h"
#include <QTreeView>
#include <QApplication>
#include <QHBoxLayout>
#include <QObject>
#include <QTableView>


tree * mod;

Interface::Interface(tree *model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{

    mod= model;
    ui->setupUi(this);
    ui->treeView->setModel(model);
    /*
    ui->tableView->setModel(model);
    //lview.setRootIndex(ip->index(0,0,ip->index(0,0,QModelIndex())));
    //QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),ui->treeView,SLOT(setRootIndex(QModelIndex)));
    QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),ui->tableView,SLOT(setRootIndex(QModelIndex)));
    //QObject::connect (ui->treeView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                      //this, SLOT(slotCurrentPic(QModelIndex, model)));
    */
//    ui->graphicsView->setModel(model);
    //lview.setRootIndex(ip->index(0,0,ip->index(0,0,QModelIndex())));
    //QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),ui->treeView,SLOT(setRootIndex(QModelIndex)));
    QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(slotCurrentPic(QModelIndex)));
    //QObject::connect (ui->treeView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                      //this, SLOT(slotCurrentPic(QModelIndex, model)));


}
void Interface::slotCurrentPic(QModelIndex index)
{
    QPixmap outPixmap = QPixmap(); // Создаём QPixmap, который будет помещаться в picLabel
    //(mod->index(index.row(), 2))
    //outPixmap.load("/home/skt/images/GameTheory/Game (1).jpg");
    outPixmap.load((index.data()).toString());
    // Устанавливаем изображение в picLabel
    QGraphicsScene * scen = new QGraphicsScene();
    scen->addPixmap(outPixmap.scaled(400,500));
    //scen->setBackgroundBrush(Qt::blue);
    //scen->addText(QString:: number(index.row()));
    //scen->addText((index.data()).toString());
    ui->graphicsView->setScene(scen);

    /*
    QPixmap outPixmap = QPixmap(); // Создаём QPixmap, который будет помещаться в picLabel
    //(model->index(index.row(), 2))
    outPixmap.load(model->data(index,1).toString());
    // Устанавливаем изображение в picLabel
    ui->picLabel->setPixmap(outPixmap.scaled(400,500));
    */
}

Interface::~Interface()
{
    delete ui;
}
