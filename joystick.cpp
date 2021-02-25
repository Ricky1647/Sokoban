#include "joystick.h"
#include<QPainter>
#include"constants.h"

Joystick::Joystick(qreal x, qreal y, GameController &controller) :
controller(controller) //初始化controller是必須的
{
    setPos(x, y);
    setData(GD_Type, GO_Stick);
    cor_stick.rx() = x;
    cor_stick.ry() = y;
}
QRectF Joystick::boundingRect() const
{
    return target;
}
void Joystick::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall("C:/project/joystick.png");
    target.setHeight(50);
    target.setWidth(50);
    painter->drawImage(target, wall);
    painter->restore();
}


