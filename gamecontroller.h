#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include<QGraphicsItem>
#include<QObject>
#include <QTimer>


class QGraphicsScene;
class Box;
class Character;
class Wall;
class Xicon;
class Button;
class Food;
class Trap;
class Door;
class Rod;
class Joystick;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene, QObject *parent = 0);
    ~GameController();

    void checkbox_box();
    void check_box_wall();
     void check_box_on_icon();
    void check();

    void sanseatfood(Character *ch,Food*food );
    void sansintrap(Character *ch,Trap*trap );
    void sansindoor(Character *ch,Door*door );
    void sansinrod(Character *ch,Rod*rod );
    void sansinstick(Character *ch,Joystick *stick );
    void sansinstick2(Character *ch,Joystick *stick );


    void sansPushBox(Character *ch,Box *box );
    void findbox();
    void findicon();
    void clearall();
    void findwall();
    void showstep();
    void showscore();
    void showlove();

public slots:
    void pause();
    void resume();
    void restartgame();
    void firstlevel();
    void secondlevel();
    void chechcomplete();


protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    void handleKeyPressed(QKeyEvent *event);
    QGraphicsScene &scene;
    QTimer timer;
    //box v.s box&ch
    qreal leftnoch_box1, leftnoch_box2,leftnoch_box3;
    qreal rightnoch_box1,rightnoch_box2,rightnoch_box3;
    qreal upnoch_box1,upnoch_box2,upnoch_box3;
    qreal downnoch_box1,downnoch_box2,downnoch_box3;

    qreal leftnobox1_box, leftnobox2_box, leftnobox3_box;
    qreal rightnobox1_box,rightnobox2_box,rightnobox3_box;
    qreal upnobox1_box,upnobox2_box,upnobox3_box;
    qreal downnobox1_box,downnobox2_box,downnobox3_box;
    //box v.s wall
    qreal leftno_box1, rightno_box1, upno_box1, downno_box1;
    qreal leftno_box2, rightno_box2, upno_box2, downno_box2;
    qreal leftno_box3, rightno_box3, upno_box3, downno_box3;
    // ch v.s. wall
    qreal leftno,rightno,upno,downno;

    //ch v.s. trap
    qreal die=0;

    //record steps
    QGraphicsTextItem *game_score;
    QGraphicsTextItem *game_food;
    QGraphicsTextItem *love;
    qreal steps = 0;
    qreal score=0;
    qreal determination=1;

    qreal winpoint1, winpoint2,winpoint3;
    Character *ch;
    Box *box1;
    Box *box2;
    Box *box3;
    Wall *wall1,*wall2,*wall3,*wall4,*wall5,*wall6,*wall7,*wall8,*wall9,*wall10,*wall11,*wall12,*wall13,*wall14,*wall15,*wall16
    ,*wall17,*wall18,*wall19,*wall20,*wall21,*wall22,*wall23,*wall24,*wall25,*wall26,*wall27,*wall28,*wall29,*wall30;
    Food *food1,*food2,*food3,*food4;
    Trap *trap1,*trap2,*trap3;
    Joystick *stick1, *stick2;
    Door *door1;
    Rod *rod1;
    Xicon *icon1,*icon2,*icon3;
    Button *nextlevelButton;
    Button *Youwin;

    QList<QGraphicsItem *> li_box ;
    QList<QGraphicsItem *> li_wall ;
    QList<QGraphicsItem *> li_icon;
};


#endif // GAMECONTROLLER_H
