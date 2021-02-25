#include<QPainter>
#include "character.h"
#include "gamecontroller.h"
#include"constants.h"

Character::Character(GameController &controller) :
    head(0, 0),
    //moveDirection(NoMove),
    controller(controller)

{
}
QRectF Character::boundingRect() const
{
    return QRectF(0, 0,	50, 50);
}
void Character::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->drawImage(QRectF(0, 0, 50, 50), QImage("C:/project/sans.png"));
    painter->restore();
}
/*void Character::setMoveDirection(Direction direction)
{
    moveDirection = direction;
}*/
void Character::advance(int step)
{
 setPos(head);
 handleCollisions();
 handleCollisions_food();
 //controller.chechcomplete();
 handleCollisions_Trap();
 handleCollisions_Door();
 handleCollisions_Rod();
 handleCollisions_Stick();
}
void Character::moveLeft( ){
    head.rx() -=50;
    if (head.rx() < -200) {
        head.rx() = -200;
    }
}
void Character::moveRight(){
    head.rx() += 50 ;
    if (head.rx() > 150) {
        head.rx() = 150;
    }
}
void Character::moveUp(){
    head.ry() -=50;
    if (head.ry() < -150) {
        head.ry() = -150;
    }
}
void Character::moveDown(){
    head.ry() +=50;
    if (head.ry() > 150) {
        head.ry() = 150;
    }
}

void Character::handleCollisions(){
    QList<QGraphicsItem *> collisions = collidingItems();
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Box) {
            controller.sansPushBox(this, (Box*)collidingItem);
        }
    }
}
void Character::handleCollisions_food(){
    QList<QGraphicsItem *> collisions = collidingItems();
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Food) {
            controller.sanseatfood(this, (Food*)collidingItem);
        }
    }
}
void Character::handleCollisions_Trap(){
    QList<QGraphicsItem *> collisions = collidingItems();
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Trap) {
            controller.sansintrap(this, (Trap*)collidingItem);
        }
    }
}
void Character::handleCollisions_Door(){
    QList<QGraphicsItem *> collisions = collidingItems();
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Door) {
            controller.sansindoor(this, (Door*)collidingItem);
        }
    }
}
void Character::handleCollisions_Rod(){
    QList<QGraphicsItem *> collisions = collidingItems();
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Rod) {
            controller.sansinrod(this, (Rod*)collidingItem);
        }
    }
}
void Character::handleCollisions_Stick(){
    QList<QGraphicsItem *> collisions = collidingItems();
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Stick) {
            controller.sansinstick(this, (Joystick*)collidingItem);}
        if (collidingItem->data(GD_Type) == GO_Stick2) {
                controller.sansinstick2(this, (Joystick*)collidingItem);}
        }

}

