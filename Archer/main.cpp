#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "archer.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene=new QGraphicsScene;
    QGraphicsView *view=new QGraphicsView;

    archer *bowman=new archer();
    scene->addItem(bowman);
    bowman->setPos(0,550);
    bowman->createArrow();

    view->setScene(scene);
    scene->setSceneRect(0,0,800,600);
    view->show();
    return a.exec();
}
