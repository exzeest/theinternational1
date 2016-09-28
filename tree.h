#ifndef TREE_H
#define TREE_H
#include <QObject>
//tree.h

class tree : public QObject
{
public:
    tree(char id, QObject *parent = 0);
    ~tree();
private:
    char id_;
};

#endif // TREE_H
