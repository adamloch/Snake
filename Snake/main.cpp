#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "snake.h"
#include "apple.h"
#include <iostream>
#include <cstdlib>
#include <ctime>



int main(int argc, char *argv[])
{





    QApplication a(argc, argv);
    QGraphicsScene *scene=new QGraphicsScene;
    Snake *player=new Snake;
    scene->addItem(player);
    apple *powerup=new apple;
    scene->addItem(powerup);
    QGraphicsView *view=new QGraphicsView(scene);
    player->setFlag(QGraphicsRectItem::ItemIsFocusable);
    player->setFocus();
    view->show();
    view->setFixedSize(803,603);
    scene->setSceneRect(0,0,800,600);


    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);     //locks scrollbars
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    player->setPos((view->width()/2)-50,500);
    return a.exec();
}
