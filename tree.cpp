#include "tree.h"
#include <QObject>
#include <QtDebug>


tree::tree(char id, QObject *parent):
    QObject(parent), id_(id)
{
    qDebug() << '+'<< id_;
}
tree::~tree()
{
    qDebug() << '-' << id_;
}
