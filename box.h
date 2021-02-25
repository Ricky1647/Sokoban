#ifndef BOX_H
#define BOX_H
#include <QGraphicsItem>
#include"gamecontroller.h"

class GameController;

class Box : public QGraphicsItem
{

public:
    //你需要把它放在public上
    Box(qreal x, qreal y, GameController &controller);
    enum Direction {
        MoveLeft_box,
        MoveRight_box,
        MoveUp_box,
        MoveDown_box
    };
    //指標指座標
    QPointF  cor;

    //回傳區域
    QRectF boundingRect() const;

    //畫人物圖片
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void setHitdirection(Direction dir);
    Direction hitDirection;
protected:

    //連結主控台
    GameController &controller;

    //不斷回傳主控台判斷
    void advance(int step);

    //那時候一直搞圖片位置的產物
    QRectF target;
};

#endif // BOX_H
