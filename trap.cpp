#include"trap.h"
#include<QPainter>
#include"constants.h"

Trap::Trap(qreal x, qreal y, GameController &controller) :
controller(controller) //初始化controller是必須的
{
    setPos(x, y);
    setData(GD_Type, GO_Trap);
    cor_trap.rx() = x;
    cor_trap.ry() = y;
}
QRectF Trap::boundingRect() const
{
    return target;
}
void  Trap::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall("C:/project/trap.png");
    target.setHeight(50);
    target.setWidth(50);
    painter->drawImage(target, wall);
    painter->restore();
}
