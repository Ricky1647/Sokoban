#ifndef DOOR_H
#define DOOR_H
#include <QGraphicsItem>
#include"gamecontroller.h"

class GameController;
class Character;

class Door :public QGraphicsItem
{
public:
    Door(qreal x, qreal y, GameController &controller);//初始化 之後加入場景(Scene)
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
    QPointF cor_door;


protected:
    GameController &controller;
    QRectF target;
    void advance(int step);
};

#endif // DOOR_H
