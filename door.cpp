#include "door.h"
#include<QPainter>
#include"constants.h"
Door::Door(qreal x, qreal y, GameController &controller) :
    controller(controller)
{
    setPos(x, y);
    setData(GD_Type, GO_Door);
    cor_door.rx() = x;
    cor_door.ry() = y;
}
QRectF Door::boundingRect() const
{
    return target;
}
void Door::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall("C:/project/door.png");
    target.setHeight(50);
    target.setWidth(50);
    painter->drawImage(target, wall);
    painter->restore();
}

void Door::advance(int step)
{
    setPos(cor_door);

}
