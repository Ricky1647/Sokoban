#ifndef  TRAP_H
#define  TRAP_H
#include<QGraphicsItem>
#include"gamecontroller.h"

class GameController;

class Trap:public  QGraphicsItem
{
public:
    Trap(qreal x, qreal y, GameController &controller);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPointF cor_trap;
    //void handleCollisions_trap();
protected:
    GameController &controller;
    QRectF target;
   // void advance(int step);
};
#endif // ! TRAP_H
