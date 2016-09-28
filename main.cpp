#include <QApplication>
#include <QQmlApplicationEngine>
#include "tree.h"

int main(/*int argc, char *argv[]*/)
{
     tree a ('A');
     tree *b = new tree ('B', &a);
     return 0;
//  QApplication app(argc, argv);

//  QQmlApplicationEngine engine;
//  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//  return app.exec();
}
