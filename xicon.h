#ifndef XICON_H
#define XICON_H


#include <QGraphicsItem>
#include"gamecontroller.h"

class GameController;

class Xicon :public QGraphicsItem
{
public:
    Xicon(qreal x, qreal y, GameController &controller);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
   // void handleCollisions();
     QPointF cor_icon;
protected:
    QRectF target;
    GameController &controller;
    //void advance(int step);
};
#endif // XICON_H
