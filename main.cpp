#include <QApplication>
#include <QTreeView>
#include "tree.h"
#include <QHBoxLayout>
#include <QObject>
#include <QTableView>
#include <interface.h>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("://style.qss");
      file.open(QFile::ReadOnly);
      qDebug()<<file.isOpen();
      QString styleSheet = file.readAll();
         qApp->setStyleSheet(styleSheet);
    a.setStyleSheet(styleSheet);
    tree model("My");
    Interface interface(&model);
    interface.show();

     /*QHBoxLayout layout (&interface);
     QTreeView view;
     QTableView lview;
     layout.addWidget(&view);
     layout.addWidget(&lview);
         view.setModel(&model);
         lview.setModel(&model);
     QObject::connect (&view,SIGNAL(clicked(QModelIndex)),&lview,SLOT(setRootIndex(QModelIndex)));
     interface.show();*/
    return a.exec();
}
