#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "snakehead.h"
#include "apple.h"



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QGraphicsScene *scene=new QGraphicsScene;
    SnakeHead *player=new SnakeHead();
    scene->addItem(player);

    apple *powerupp=new apple;
    scene->addItem(powerupp);
    player->getApplePtr(powerupp);
    QGraphicsView *view=new QGraphicsView(scene);
    player->setFlag(QGraphicsRectItem::ItemIsFocusable);
    player->setFocus();

    view->show();
    view->setFixedSize(803,603);
    scene->setSceneRect(0,0,800,600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);     //locks scrollbars
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    player->setPos(0,0);
    return a.exec();
}
