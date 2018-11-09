#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsScene>

#include <rects.h>
#include <snake.h>
#include <powerUp.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene=new QGraphicsScene;
    QGraphicsView *view=new QGraphicsView(scene);
    snake *player=new snake;
    scene->addItem(player);
    powerUp *apple=new powerUp;
    scene->addItem(apple);
    player->getPowerUpPtr(apple);


    double x=200,y=200;
    player->addRect(x,y);

    player->setFlag(QGraphicsRectItem::ItemIsFocusable);
    player->setFocus();
    view->show();
    view->setFixedSize(800,600);

    scene->setSceneRect(0,0,800,600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);




    return a.exec();
}
