#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsItem>
#include"gamecontroller.h"

class GameController;

class Character : public QGraphicsItem {
public:
    Character(GameController & controller);

    enum Direction {
        NoMove,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        Duck
    };
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void moveLeft( );
    void moveRight();
    void moveUp();
    void moveDown();
    //void setMoveDirection(Direction direction); //這還需要嗎???
    void handleCollisions();
    void handleCollisions_food();
    void handleCollisions_Trap();
     void handleCollisions_Door();
      void handleCollisions_Rod();
      void handleCollisions_Stick();
    QPointF head; //座標

protected:
    void advance(int step);
    Direction      moveDirection;
    GameController &controller;
};
#endif // CHARACTER_H
