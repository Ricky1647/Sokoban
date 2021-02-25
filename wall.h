#ifndef WALL_H
#define WALL_H
#include <QGraphicsItem>
#include"gamecontroller.h"

class GameController;
class Character;

class Wall :public QGraphicsItem
{
public:
    Wall(qreal x, qreal y, GameController &controller);//初始化 之後加入場景(Scene)
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
    QPointF cor_wall;


protected:
    GameController &controller;
    QRectF target;
    void advance(int step);
};
#endif // WALL_H
