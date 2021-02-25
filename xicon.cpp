#include "xicon.h"
#include"constants.h"
#include<QPainter>
Xicon::Xicon(qreal x, qreal y, GameController &controller) :
    controller(controller)
{
    setPos(x, y);
    setData(GD_Type, GO_Icon); //include constants.h可以解決
    cor_icon.rx() = x;
    cor_icon.ry() = y;
}
QRectF Xicon::boundingRect() const
{
    return target;
}
void Xicon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();                     //請include QPainter 謝謝
    QImage xicon("C:/project/xicon.png");
    target.setHeight(50);
    target.setWidth(50);
    painter->drawImage(target, xicon);
    painter->restore();
}
