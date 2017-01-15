#include "interface.h"
#include "ui_interface.h"
#include "QtWidgets"
#include "tree.h"
#include <QTreeView>
#include <QApplication>
#include <QHBoxLayout>
#include <QObject>



Interface::Interface(tree *model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
    ui->treeView->setModel(model);


    // Устанавливаем заглушку.

    QPixmap pix = QPixmap(":/startpic.png");
    QGraphicsScene * scen = new QGraphicsScene();
    scen->addPixmap(pix.scaled(400,400));
    ui->graphicsView->setScene(scen);



    QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(slotCurrentPic(QModelIndex)));
    QObject::connect (ui->treeView,SIGNAL(activated(QModelIndex)),this,SLOT(slotCurrentPic(QModelIndex)));


    QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(setTextLabel(QModelIndex)));
    QObject::connect (ui->treeView,SIGNAL(activated(QModelIndex)),this,SLOT(setTextLabel(QModelIndex)));


    // Подрубаем кнопки
    QObject::connect (ui->tB_right,SIGNAL(clicked()),this,SLOT(nextImage()));
    QObject::connect (ui->tB_left,SIGNAL(clicked()),this,SLOT(prevImage()));

}
void Interface::setTextLabel(QModelIndex index)
{
    if (!index.data().isNull())
    {
        ui->labelAdress->setText(index.data().toString());
    }
    else
        ui->labelAdress->setText("Current path to image will be shown here");
}

void Interface::slotCurrentPic(QModelIndex index)
{

    QString path = index.data().toString();
    QPixmap outPixmap = QPixmap();
    outPixmap.load(path);
    if (!outPixmap.isNull())
    {
        setPicToGView(outPixmap);
    }
    else
    {
        QPixmap pix = QPixmap(":/startpic.png");
        setPicToGView(pix);

    }
}

void Interface::setPicToGView(QPixmap outPixmap)
{
    QGraphicsScene * scen = new QGraphicsScene();
    ui->graphicsView->setScene(scen);
    QGraphicsPixmapItem * pixmap_item = new QGraphicsPixmapItem();
    scen->addItem(pixmap_item);
    pixmap_item->setVisible(true);
    pixmap_item->setPixmap(outPixmap);
    scen->setSceneRect(0, 0, outPixmap.width(), outPixmap.height());
    ui->graphicsView->fitInView(pixmap_item, Qt::KeepAspectRatio);

}

void Interface::nextImage()
{
    QModelIndex m2=ui->treeView->indexBelow(ui->treeView->currentIndex());
    //emit signalChangeCurrentIndex(m2);
    QPixmap outPixmap = QPixmap();
    outPixmap.load(m2.data().toString());
    if (!outPixmap.isNull())
    {
        ui->treeView->selectionModel()->setCurrentIndex(m2, QItemSelectionModel::SelectCurrent );
        slotCurrentPic(m2);
    }
}

void Interface::prevImage()
{
    QModelIndex m2=ui->treeView->indexAbove(ui->treeView->currentIndex());
    //emit signalChangeCurrentIndex(m2);
    QPixmap outPixmap = QPixmap();
    outPixmap.load(m2.data().toString());
    if (!outPixmap.isNull())
    {
        ui->treeView->selectionModel()->setCurrentIndex(m2, QItemSelectionModel::SelectCurrent );
        slotCurrentPic(m2);
    }
}


Interface::~Interface()
{
    delete ui;
}



