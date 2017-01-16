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
    scen->addPixmap(pix.scaledToHeight(500));
    ui->graphicsView->setScene(scen);



    QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(SlotCurrentPic(QModelIndex)));
    QObject::connect (ui->treeView,SIGNAL(activated(QModelIndex)),this,SLOT(SlotCurrentPic(QModelIndex)));


    QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(SetTextLabel(QModelIndex)));
    QObject::connect (ui->treeView,SIGNAL(activated(QModelIndex)),this,SLOT(SetTextLabel(QModelIndex)));


    // Подрубаем кнопки
    QObject::connect (ui->tB_right,SIGNAL(clicked()),this,SLOT(NextImage()));
    QObject::connect (ui->tB_left,SIGNAL(clicked()),this,SLOT(PrevImage()));
    QObject::connect (ui->tB_zoom_in, SIGNAL(clicked()),this,SLOT(ZoomIn()));
    QObject::connect (ui->tB_zoom_out, SIGNAL(clicked()),this,SLOT(ZoomOut()));
    QObject::connect (ui->pB_zoom_in, SIGNAL(clicked()),this,SLOT(ZoomIn()));
    QObject::connect (ui->pB_zoom_out, SIGNAL(clicked()),this,SLOT(ZoomOut()));
}
void Interface::SetTextLabel(QModelIndex index)
{
    if (!index.data().isNull())
    {
        ui->labelAdress->setText(index.data().toString());
    }
    else
        ui->labelAdress->setText("Current path to image will be shown here");
}

void Interface::SlotCurrentPic(QModelIndex index)
{

    QString path = index.data().toString();
    QPixmap outPixmap = QPixmap();
    outPixmap.load(path);
    if (!outPixmap.isNull())
    {
        SetPicToGView(outPixmap);
    }
    else
    {
        QPixmap pix = QPixmap(":/startpic.png");
        SetPicToGView(pix);

    }
}

void Interface::SetPicToGView(QPixmap outPixmap)
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

void Interface::NextImage()
{
    QModelIndex nextIndex=ui->treeView->indexBelow(ui->treeView->currentIndex());
    QPixmap outPixmap = QPixmap();
    outPixmap.load(nextIndex.data().toString());
    if (!outPixmap.isNull())
    {
        ui->treeView->selectionModel()->setCurrentIndex(nextIndex, QItemSelectionModel::SelectCurrent );
        SetPicToGView(outPixmap);
        SetTextLabel(nextIndex);
    }
}

void Interface::PrevImage()
{
    QModelIndex prevIndex = ui->treeView->indexAbove(ui->treeView->currentIndex());

    QPixmap outPixmap = QPixmap();
    outPixmap.load(prevIndex.data().toString());
    if (!outPixmap.isNull())
    {
        ui->treeView->selectionModel()->setCurrentIndex(prevIndex, QItemSelectionModel::SelectCurrent );
        SetPicToGView(outPixmap);
        SetTextLabel(prevIndex);
    }
}

void Interface::ZoomIn()
{
    QModelIndex index = ui->treeView->currentIndex();
    QString path = index.data().toString();
    QPixmap outPixmap = QPixmap();
    outPixmap.load(path);
    if (!outPixmap.isNull())
    {
        const double scaleFactor = 1.15;
        ui->graphicsView->scale(scaleFactor, scaleFactor);
    }

}
void Interface::ZoomOut()
{
    QModelIndex index = ui->treeView->currentIndex();
    QString path = index.data().toString();
    QPixmap outPixmap = QPixmap();
    outPixmap.load(path);
    if (!outPixmap.isNull())
    {
        const double scaleFactor = 1.15;
        ui->graphicsView->scale(1.0/scaleFactor, 1.0/scaleFactor);
    }

}

Interface::~Interface()
{
    delete ui;
}



