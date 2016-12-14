#include <QApplication>
#include <QTreeView>
#include "tree.h"
#include <QHBoxLayout>
#include <QObject>
#include <QTableView>
#include <QDir>
#include <interface.h>
#include <QFile>
#include <QDebug>
int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    tree model("../My");//("/home/skt/theinternational1/My");//("../My");
    QWidget widget;
     QHBoxLayout layout (&widget);
     QTreeView view;
     QTableView lview;
     layout.addWidget(&view);
     layout.addWidget(&lview);
         view.setModel(&model);
         lview.setModel(&model);
       //  lview.setRootIndex(ip->index(0,0,ip->index(0,0,QModelIndex())));
     QObject::connect (&view,SIGNAL(clicked(QModelIndex)),&lview,SLOT(setRootIndex(QModelIndex)));
    // QObject::connect (&view,SIGNAL(entered(QModelIndex)),&lview,SLOT(setRootIndex(QModelIndex)));
    // QObject::connect (&view,SIGNAL(activated(QModelIndex)),&lview,SLOT(setRootIndex(QModelIndex)));
     widget.show();
     */

     QApplication a(argc, argv);
     QFile file("://style.qss");
       file.open(QFile::ReadOnly);
       qDebug()<<file.isOpen();
       QString styleSheet = file.readAll();
          qApp->setStyleSheet(styleSheet);
       //ui.applyButton->setEnabled(false);
     a.setStyleSheet(styleSheet);
     tree model("../My");//("/home/skt/theinternational1/My");//("../My");
     Interface interface(&model);
     interface.show();
      /*QHBoxLayout layout (&interface);
      QTreeView view;
      QTableView lview;
      layout.addWidget(&view);
      layout.addWidget(&lview);
          view.setModel(&model);
          lview.setModel(&model);*/
        //  lview.setRootIndex(ip->index(0,0,ip->index(0,0,QModelIndex())));
      //QObject::connect (&view,SIGNAL(clicked(QModelIndex)),&lview,SLOT(setRootIndex(QModelIndex)));
     // QObject::connect (&view,SIGNAL(entered(QModelIndex)),&lview,SLOT(setRootIndex(QModelIndex)));
     // QObject::connect (&view,SIGNAL(activated(QModelIndex)),&lview,SLOT(setRootIndex(QModelIndex)));

     return a.exec();
}
