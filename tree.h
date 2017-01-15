#ifndef TREE_H
#define TREE_H
#include <QAbstractTableModel>
#include <QSqlDatabase>
#include <QStringList>
//tree.h

enum h_type {ROOT, TERM = 1, COURSE, THEME, IMAGE};
struct IData {

    QString path;
    QString comments;
    QStringList tags;
};

struct HData {
    QString name;
    QString comments;
    QStringList tags;
};

struct DataWrapper {
    quint16 id;
    h_type type;
    void *data;
    int number;
    DataWrapper *parent;
    QList<DataWrapper *> children;
    int count;
};
class tree : public QAbstractItemModel
{
    Q_OBJECT
public:
    tree(QString dbname, QObject *parent = nullptr);
    ~tree();
    virtual int rowCount(const QModelIndex &parent) const;
    virtual bool insertRows(int row, int count, const QModelIndex &parent);
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QModelIndex parent(const QModelIndex &child) const;
    void fetchMore(const QModelIndex &parent)
    {
        fetchAll (parent);
    }
    bool canFetchMore(const QModelIndex &parent) const;

private:
    DataWrapper d {0, ROOT, nullptr, 0, nullptr, {}, -1};
    void fetchAll(const QModelIndex &parent);
    int getChildrenCount (h_type type, int pid) const;
    const DataWrapper *dataForIndex(const QModelIndex &index) const;
    DataWrapper *dataForIndex(const QModelIndex&index);
    QSqlDatabase db;
};

#endif // TREE_H
