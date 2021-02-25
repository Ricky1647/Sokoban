#include "rod.h"
#include<QPainter>
#include"constants.h"

Rod::Rod(qreal x, qreal y, GameController &controller) :
controller(controller) //初始化controller是必須的
{
    setPos(x, y);
    setData(GD_Type, GO_Rod);
    cor_rod.rx() = x;
    cor_rod.ry() = y;
}
QRectF Rod::boundingRect() const
{
    return target;
}
void  Rod::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall("C:/project/red.png");
    target.setHeight(50);
    target.setWidth(50);
    painter->drawImage(target, wall);
    painter->restore();
}
