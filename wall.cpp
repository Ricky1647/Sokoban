#include "wall.h"
#include<QPainter>
#include"constants.h"
Wall::Wall(qreal x, qreal y, GameController &controller) :
    controller(controller)
{
    setPos(x, y);
    setData(GD_Type, GO_Wall);
    cor_wall.rx() = x;
    cor_wall.ry() = y;
}
QRectF Wall::boundingRect() const
{
    return target;
}
void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall("C:/project/wall.png");
    target.setHeight(50);
    target.setWidth(50);
    painter->drawImage(target, wall);
    painter->restore();
}

void Wall::advance(int step)
{
    setPos(cor_wall);

}
