#include "interface.h"
#include "ui_interface.h"
#include "QtWidgets"
#include "tree.h"
#include <QTreeView>
#include <QApplication>
#include <QHBoxLayout>
#include <QObject>
#include <QTableView>


Interface::Interface(tree *model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
    ui->treeView->setModel(model);


    // Устанавливаем заглушку.
    QGraphicsScene * scen = new QGraphicsScene();
    ui->graphicsView->setScene(scen);
    QGraphicsPixmapItem * pixmap_item = new QGraphicsPixmapItem();
    scen->addItem(pixmap_item);
    pixmap_item->setVisible(true);
    QPixmap pix = QPixmap("GitTheInternational/startpic.png");
    pixmap_item->setPixmap(pix);
    scen->setSceneRect(0, 0, pix.width(), pix.height());
    ui->graphicsView->fitInView(pixmap_item, Qt::KeepAspectRatio);



    QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(slotCurrentPic(QModelIndex)));
    QObject::connect (ui->treeView,SIGNAL(activated(QModelIndex)),this,SLOT(slotCurrentPic(QModelIndex)));

    //lview.setRootIndex(ip->index(0,0,ip->index(0,0,QModelIndex())));
    //QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),ui->treeView,SLOT(setRootIndex(QModelIndex)));

    QObject::connect (ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(setTextLabel(QModelIndex)));
    QObject::connect (ui->treeView,SIGNAL(activated(QModelIndex)),this,SLOT(setTextLabel(QModelIndex)));
    //QTextStream Qout(stdout);
   // ui->treeView->currentIndex().row();
   // ui->labelAdress->setText(static_cast<QString>(ui->treeView->currentIndex().row()));
   // QObject::connect (ui->treeView, SIGNAL(clicked(QModelIndex)), ui->labelAdress, SLOT(setTextLabel()));
   // Qout<<ui->treeView->currentIndex().row();
    //QObject::connect (ui->treeView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                      //this, SLOT(slotCurrentPic(QModelIndex, model)));

    //QObject::connect(ui->tB_left, SIGNAL (clicked()), ui->treeView, SLOT ());


    // Подрубаем кнопки
    QObject::connect (ui->tB_full_screen, SIGNAL(triggered(QAction*)), ui->graphicsView, SLOT(updateSceneRect(QRectF));

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
    QGraphicsScene * scen = new QGraphicsScene();
    ui->graphicsView->setScene(scen);
    QGraphicsPixmapItem * pixmap_item = new QGraphicsPixmapItem();
    scen->addItem(pixmap_item);
    pixmap_item->setVisible(true);
    QString path = index.data().toString();
    QPixmap outPixmap = QPixmap();
    outPixmap.load(path);
    if (!outPixmap.isNull())
    {
        // Устанавливаем изображение в picLabel

        pixmap_item->setPixmap(outPixmap);
        scen->setSceneRect(0, 0, outPixmap.width(), outPixmap.height());
        ui->graphicsView->fitInView(pixmap_item, Qt::KeepAspectRatio);

    }
    else
    {
        QPixmap pix = QPixmap("GitTheInternational/startpic.png");
        pixmap_item->setPixmap(pix);
        scen->setSceneRect(0, 0, pix.width(), pix.height());
        ui->graphicsView->fitInView(pixmap_item, Qt::KeepAspectRatio);
    }
}

Interface::~Interface()
{
    delete ui;
}

