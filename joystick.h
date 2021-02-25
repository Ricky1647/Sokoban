#ifndef JOYSTICK_H
#define JOYSTICK_H


#include <QGraphicsItem>
#include"gamecontroller.h"

class GameController;
class Character;

class Joystick :public QGraphicsItem
{
public:
    Joystick(qreal x, qreal y, GameController &controller);//初始化 之後加入場景(Scene)
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
    QPointF cor_stick;


protected:
    GameController &controller;
    QRectF target;
   // void advance(int step);
};



#endif // JOYSTICK_H
