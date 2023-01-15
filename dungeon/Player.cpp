#include "Player.h"
#include "mainwindow.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <random>
#include <QDebug>

extern MainWindow * w;

Player::Player()
{
    setRect(0,0,98,98);
    setBrush(Qt::black);
}
void Player::keyPressEvent(QKeyEvent *event)
{   
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 1 )
            setPos(x()-100,y());
    }
    else if(event->key() == Qt::Key_Right){
            if(pos().x() < 599)
                setPos(x()+100,y());
    }else if(event->key() == Qt::Key_Up){
            if(pos().y() > 1)
                setPos(x(),y()-100);
    }else if(event->key() == Qt::Key_Down){
            if(pos().y() < 599)
                setPos(x(),y()+100);
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0; i<colliding_items.size();++i){
        if(typeid(*(colliding_items[i])) == typeid(Wall)){
            scene()->removeItem(this);
            w->resetScore();
            return;
        }else if(typeid(*(colliding_items[i])) == typeid(Gem)){
            scene()->removeItem(this);
            w->increaseScore();
            return;
        }
    }

}
