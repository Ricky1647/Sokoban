#include "box.h"
#include <QPainter>
#include"constants.h"

Box::Box(qreal x, qreal y, GameController &controller) :
    controller(controller)
{
    setPos(x, y);
    setData(GD_Type, GO_Box);
    cor.rx()=x;
    cor.ry() = y;
}
QRectF Box::boundingRect() const
{
    return target;
}
void Box::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage box("C:/project/box.png");
    target.setHeight(50);
    target.setWidth(50);
    painter->drawImage(target, box);
    painter->restore();
}
void Box::advance(int step) {
}
void Box::setHitdirection(Direction dir)
{
    hitDirection = dir;
}
