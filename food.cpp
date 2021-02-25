#include "food.h"
#include<QPainter>
#include"constants.h"
Food::Food(qreal x, qreal y, GameController &controller) :
    controller(controller)
{
    setPos(x, y);
    setData(GD_Type, GO_Food);
    cor_food.rx() = x;
    cor_food.ry() = y;
}
QRectF Food::boundingRect() const
{
    return target;
}
void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall("C:/project/ketchup.jpg");
    target.setHeight(50);
    target.setWidth(50);
    painter->drawImage(target, wall);
    painter->restore();
}

void Food::advance(int step)
{
    setPos(cor_food);

}
