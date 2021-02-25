#ifndef ROD_H
#define ROD_H


#include <QGraphicsItem>
#include"gamecontroller.h"

class GameController;
class Character;

class Rod :public QGraphicsItem
{
public:
    Rod(qreal x, qreal y, GameController &controller);//初始化 之後加入場景(Scene)
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
    QPointF cor_rod;


protected:
    GameController &controller;
    QRectF target;
    //void advance(int step);
};

#endif // ROD_H
