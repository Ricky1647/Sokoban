#include <QEvent>
#include "gamecontroller.h"
#include <QGraphicsScene>
#include<QKeyEvent>
#include"button.h"
#include"box.h"
#include"character.h"
#include"constants.h"
#include"wall.h"
#include"xicon.h"
#include"food.h"
#include"trap.h"
#include"door.h"
#include"rod.h"
#include"joystick.h"
GameController::GameController(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene)
{
    timer.start(1000/20);
    Button* restartButton = new Button(QString("Levl 1(Restart)"));
    Button* restartButton1 = new Button(QString("Step : "));
    Button* scoreButton = new Button(QString("Score : "));
    Button* LoveButton = new Button(QString("Health : "));
    restartButton->setPos(-200, -200);
    restartButton1->setPos(-100, -200);
    scoreButton->setPos(0,-200);
    LoveButton->setPos(100, -200);
    scene.addItem(restartButton);
     scene.addItem(restartButton1);
     scene.addItem(scoreButton);
     scene.addItem(LoveButton);
    scene.installEventFilter(this);
    connect(restartButton, SIGNAL(clicked()), this, SLOT(restartgame()));
    game_score = new QGraphicsTextItem;
    game_score->setFont(QFont("Times", 10, QFont::Bold));
    game_score->setPos(-35, -188);
    game_score->setHtml(tr("<font color = red >0</font>"));

    game_food = new QGraphicsTextItem;
    game_food->setFont(QFont("Times", 10, QFont::Bold));
    game_food->setPos(75, -188);
    game_food->setHtml(tr("<font color = red >0</font>"));

    love = new QGraphicsTextItem;
    love->setFont(QFont("Times", 10, QFont::Bold));
    love->setPos(165, -189);
    love->setHtml(tr("<font color = red >1</font>"));


    scene.addItem(game_score);
    scene.addItem(game_food);
    scene.addItem(love);
    firstlevel();
    findbox();
    findwall();
    findicon();



     //connect(&timer, SIGNAL(timeout()),  this, SLOT(check_box_on_icon()));


    //忘記加resume就跑不出來
    resume();
}
GameController::~GameController()
{
}

//pause the game
void GameController::pause()
{
    disconnect(&timer, SIGNAL(timeout()),
        &scene, SLOT(advance()));
}

//restart the game
void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()),
        &scene, SLOT(advance()));

}

void GameController::firstlevel()
{

    ch = (new Character(*this));
    ch->setZValue(200);
    box1 = (new Box(50, -50, *this));
    box2=(new Box(-50,-50, *this)); //為甚麼box2不能推動 因為你沒有給他 方向判斷
    box3=(new Box(-50,0, *this));
    box1->setZValue(100);
    box2->setZValue(100);
    box3->setZValue(100);
    wall1=(new Wall(-100,-100, *this));
    wall2=(new Wall(-200,-100, *this));
    wall3=(new Wall(-200,-50, *this));
    wall4=(new Wall(-200,0, *this));
    wall5=(new Wall(-200,50, *this));
     wall6=(new Wall(-200,100, *this));

     wall7=(new Wall(-150,100, *this));
     wall8=(new Wall(-100,100, *this));
     wall9=(new Wall(-50,100, *this));
     wall10=(new Wall(0,100, *this));
     wall11=(new Wall(50,100, *this));
     wall12=(new Wall(100,100, *this));
     wall13=(new Wall(150,100, *this));
     wall14=(new Wall(150,50, *this));
     wall15=(new Wall(150,0, *this));
     wall16=(new Wall(150,-50, *this));
     wall17=(new Wall(150,-100, *this));
     wall18=(new Wall(150,-150, *this));
     wall19=(new Wall(100,-150, *this));
     wall20=(new Wall(50,-150, *this));
     wall21=(new Wall(0,-150, *this));
     wall22=(new Wall(-50,-150, *this));
     wall22->setData(GD_Type, GO_Sceret);
     door1=(new Door(-100,-150, *this));
     wall24=(new Wall(-150,-150, *this));
     wall25=(new Wall(-200,-150, *this));
     wall26=(new Wall(-50,-200, *this));
     wall26->setZValue(-50);
     wall27=(new Wall(-100,-200, *this));
     wall27->setZValue(-50);
      wall28=(new Wall(50,200, *this));
      wall29=(new Wall(100,200, *this));
      wall30=(new Wall(200,150, *this));
     icon1=(new Xicon(-150,-100, *this));
     //wall24->setData(GD_Type, GO_Sceret);
    // wall24->setZValue(250);
      icon2=(new Xicon(-150,-50, *this));
       icon3=(new Xicon(-150,0, *this));
       food1=(new Food(100,50, *this));
       trap1=(new Trap(-100,-50, *this));
       trap2=(new Trap(250,250, *this));
       trap3=(new Trap(-300,-300, *this));
        trap2->setZValue(100);
        food2=(new Food(300,300, *this));
        food3=(new Food(300,300, *this));
        scene.addItem(food2);
        scene.addItem(food3);
     scene.addItem(trap2);
       scene.addItem(trap3);
       rod1=(new Rod(300,300, *this));
       scene.addItem(rod1);
       stick1=(new Joystick(300,300, *this));
       scene.addItem(stick1);
       stick2=(new Joystick(300,300, *this));
       stick2->setData(GD_Type,GO_Stick2);
       scene.addItem(stick2);

    scene.addItem(ch);
    scene.addItem(box1);
    scene.addItem(box2);
    scene.addItem(box3);
    scene.addItem(wall1);
    scene.addItem(wall2);
     scene.addItem(wall3);
     scene.addItem(wall4);
     scene.addItem(wall5);
     scene.addItem(wall6);
     scene.addItem(wall7);
     scene.addItem(wall8);
     scene.addItem(wall9);
     scene.addItem(wall10);
     scene.addItem(wall11);
     scene.addItem(wall12);
     scene.addItem(wall13);
     scene.addItem(wall14);
     scene.addItem(wall15);
     scene.addItem(wall16);
     scene.addItem(wall17);
     scene.addItem(wall18);
     scene.addItem(wall19);
     scene.addItem(wall20);
     scene.addItem(wall21);
     scene.addItem(wall22);
     scene.addItem(door1);
     scene.addItem(wall24);
     scene.addItem(wall25);
     scene.addItem(wall26);
     scene.addItem(wall27);
     scene.addItem(wall28);
     scene.addItem(wall29);
      scene.addItem(wall30);
     scene.addItem(icon1);
     scene.addItem(icon2);
     scene.addItem(icon3);
     scene.addItem(food1);
      scene.addItem(trap1);


}

void GameController::secondlevel()
{

score=0;
showscore();
    resume();
    steps=0;
    showstep();
    determination=1;
    showlove();
    die=0;
    ch->head.rx()=-50;
    ch->head.ry() = -50;
    ch->setPos(ch->head);
    box1->cor.rx()=100;
    box1->cor.ry()=150;
    box1->setPos(box1->cor);
    box2->cor.rx() = 50;
    box2->cor.ry() = -50;
    box2->setPos(box2->cor);
    box3->cor.rx() = 50;
    box3->cor.ry() = 0;
    box3->setPos(box3->cor);
    trap2->cor_trap.rx()= -100;
    trap2->cor_trap.ry()=0;
    trap2->setPos(trap2->cor_trap);

     trap3->cor_trap.rx()=-100;
     trap3->cor_trap.ry()=50;
     trap3->setPos(trap3->cor_trap);
     food1->cor_food.rx()=100;
     food1->cor_food.ry()=50;
      food1->setPos(food1->cor_food);
     food2->cor_food.rx()=100;
      food2->cor_food.ry()=0;
       food2->setPos(food1->cor_food);
       food3->cor_food.rx()=100;
       food3->cor_food.ry()=-50;
        food3->setPos(food1->cor_food);

        rod1->cor_rod.rx()=300;
        rod1->cor_rod.ry()=350;
        rod1->setPos( rod1->cor_rod);


        icon1->cor_icon.rx()=150;
         icon1->cor_icon.ry()=150;
         icon1->setPos( icon1->cor_icon);

        stick1->cor_stick.rx()=50;
         stick1->cor_stick.ry()=-100;
         stick1->setPos( stick1->cor_stick);

         stick2->cor_stick.rx()=0;
          stick2->cor_stick.ry()=150;
          stick2->setPos( stick2->cor_stick);
    scene.update();



}


void GameController::restartgame() {
    resume();
    die=0;
    steps=0;
    showstep();
    score=0;
    showscore();
    determination=1;
    showlove();
    ch->head.rx()=0;
    ch->head.ry() = 0;
    ch->setPos(ch->head);
    box1->cor.rx() = 50;
    box1->cor.ry() = -50;
    box1->setPos(box1->cor);
    box2->cor.rx() = -50;
    box2->cor.ry() = -50;
    box2->setPos(box2->cor);
    box3->cor.rx() = -50;
    box3->cor.ry() = 0;
    box3->setPos(box3->cor);
   food1->cor_food.rx()=100;
   food1->cor_food.ry()=50;
    food1->setPos(food1->cor_food);
    food2->cor_food.rx()=300;
    food2->cor_food.ry()=300;
     food2->setPos(food1->cor_food);
     food3->cor_food.rx()=300;
     food3->cor_food.ry()=350;
      food3->setPos(food1->cor_food);
      trap2->cor_trap.rx()= 300;
      trap2->cor_trap.ry()=350;
      trap2->setPos(trap2->cor_trap);
      trap3->cor_trap.rx()=300;
      trap3->cor_trap.ry()=350;
      trap3->setPos(trap3->cor_trap);
      rod1->cor_rod.rx()=300;
      rod1->cor_rod.ry()=350;
      rod1->setPos( rod1->cor_rod);

      stick1->cor_stick.rx()=300;
      stick1->cor_stick.ry()=350;
     stick1->setPos(  stick1->cor_stick);

     //-150,-100
     icon1->cor_icon.rx()=-150;
     icon1->cor_icon.ry()=-100;
     icon1->setPos(  icon1->cor_icon);

     stick2->cor_stick.rx()=300;
     stick2->cor_stick.ry()=350;
    stick2->setPos(  stick2->cor_stick);
      scene.update();
}
void GameController::handleKeyPressed(QKeyEvent *event)
{
    switch (event->key()){
    case Qt::Key_Left:
        check();
       checkbox_box();
       check_box_wall();
       if(leftnoch_box1==1&&leftnobox1_box==1){}
       else if(leftnoch_box2==1&&leftnobox2_box==1){}
       else if(leftnoch_box3==1&&leftnobox3_box==1){}
       else if(leftnoch_box1==1&&leftno_box1==1){}
       else if(leftnoch_box2==1&&leftno_box2==1){}
       else if(leftnoch_box3==1&&leftno_box3==1){}
       else if(leftno){}
       else if(die){}
       else{ch->moveLeft();
       ch->setPos(ch->head);
       box1->hitDirection = Box::MoveLeft_box;
       box2->hitDirection = Box::MoveLeft_box;
       box3->hitDirection = Box::MoveLeft_box;
       steps++;
       showstep();
       check_box_on_icon();
       chechcomplete();}
       clearall();
       break;
    case Qt::Key_Right:
          check();
       checkbox_box();
       check_box_wall();


       if(rightnoch_box1==1&&rightnobox1_box==1){}
       else if(rightnoch_box2==1&&rightnobox2_box==1){}
       else if(rightnoch_box3==1&&rightnobox3_box==1){}
       else if(rightnoch_box1==1&&rightno_box1==1){}
       else if(rightnoch_box2==1&&rightno_box2==1){}
       else if(rightnoch_box3==1&&rightno_box3==1){}
       else if(rightno){}
         else if(die){}
       else{
       ch->moveRight();
       ch->setPos(ch->head);
       box1->hitDirection = Box::MoveRight_box;
       box2->hitDirection = Box::MoveRight_box;
       box3->hitDirection = Box::MoveRight_box;
       steps++;
       showstep();
        check_box_on_icon();
       chechcomplete();}
       clearall();
       break;
    case Qt::Key_Up:
          check();
        checkbox_box();
        check_box_wall();


        if(upnoch_box1==1&&upnobox1_box==1){}
        else if(upnoch_box2==1&&upnobox2_box==1){}
        else if(upnoch_box3==1&&upnobox3_box==1){}
        else if(upnoch_box1==1&&upno_box1==1){}
        else if(upnoch_box2==1&&upno_box2==1){}
        else if(upnoch_box3==1&&upno_box3==1){}
        else if(upno){}
          else if(die){}
        else{
        ch->moveUp();
        ch->setPos(ch->head);
        box1->hitDirection = Box::MoveUp_box;
        box2->hitDirection = Box::MoveUp_box;
        box3->hitDirection = Box::MoveUp_box;
        steps++;
        showstep();
        check_box_on_icon();
        chechcomplete();
                }
        clearall();
         break;
    case Qt::Key_Down:
          check();
         checkbox_box();
         check_box_wall();
         check_box_on_icon();
          chechcomplete();
        if(downnoch_box1==1&&downnobox1_box==1){}
        else if(downnoch_box2==1&&downnobox2_box==1){}
        else if(downnoch_box3==1&&downnobox3_box==1){}
        else if(downnoch_box1==1&&downno_box1==1){}
        else if(downnoch_box2==1&&downno_box2==1){}
        else if(downnoch_box3==1&&downno_box3==1){}
        else if(downno){}
         else if(die){}
        else{
        ch->moveDown();
        ch->setPos(ch->head);
        box1->hitDirection = Box::MoveDown_box;
        box2->hitDirection = Box::MoveDown_box;
        box3->hitDirection = Box::MoveDown_box;
        steps++;
        showstep();
        check_box_on_icon();
        chechcomplete();}
        clearall();
        break;
    }
}
 void GameController::sansPushBox(Character *ch,Box *box ){
     switch (box->hitDirection){
     case Box::MoveLeft_box:
         box->cor.rx() -= 50;
         box->setPos(box->cor);
check_box_on_icon();
         break;
     case Box::MoveRight_box:
         checkbox_box();
         box->cor.rx() += 50;
         box->setPos(box->cor);
         check_box_on_icon();
         break;
     case Box::MoveUp_box:
         box->cor.ry() -= 50;
         box->setPos(box->cor);
         check_box_on_icon();
         break;
     case Box::MoveDown_box:
         box->cor.ry() += 50;
         box->setPos(box->cor);
         check_box_on_icon();
         break;
     }
 }
bool GameController::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    }
    else {
        return QObject::eventFilter(object, event);
    }
}
void GameController::showstep() {
    int current_score = game_score->toPlainText().toInt();
    current_score = steps;
    game_score->setHtml(tr("<font color = red>%1</font>").arg(current_score));
}
void GameController::showscore() {
    int current_score = game_food->toPlainText().toInt();
    current_score = score;
    game_food->setHtml(tr("<font color = red>%1</font>").arg(current_score));
    if(current_score==30)
    {
        rod1->cor_rod.rx()=100;
        rod1->cor_rod.ry()=-100;
        rod1->setPos( rod1->cor_rod);
          scene.update();
    }
}
void GameController::showlove() {
    int current_score =love->toPlainText().toInt();
    current_score = determination;
    love->setHtml(tr("<font color = red>%1</font>").arg(current_score));
}
void GameController::findbox() {
    QList<QGraphicsItem *> listing = scene.items();
    for (int o = 0; o<listing.size(); o++) {
        if (listing[o]->data(GD_Type) == GO_Box) {
            li_box.append(listing[o]);
        }
    }
}
void GameController::findicon() {

    QList<QGraphicsItem *> listing = scene.items();
    for (int o = 0; o<listing.size(); o++) {
        if (listing[o]->data(GD_Type) == GO_Icon) {
            li_icon.append(listing[o]);
        }
    }
}
void GameController::check_box_wall() {
    for (int i = 0; i < li_wall.size(); i++) {
        if (box1->cor.rx() + 50 == li_wall[i]->x() && box1->cor.ry() == li_wall[i]->y())
        {
            rightno_box1 = 1;
        }
        if (box2->cor.rx() + 50 == li_wall[i]->x() && box2->cor.ry() == li_wall[i]->y())
        {
            rightno_box2 = 1;
        }
        if (box3->cor.rx() + 50 == li_wall[i]->x() && box3->cor.ry() == li_wall[i]->y())
        {
            rightno_box3 = 1;
        }
    }
    //假如左邊有牆壁
    for (int i = 0; i < li_wall.size(); i++) {
        if (box1->cor.rx() - 50 == li_wall[i]->x() && box1->cor.ry() == li_wall[i]->y())
        {
            leftno_box1 = 1;
        }
        if (box2->cor.rx() - 50 == li_wall[i]->x() && box2->cor.ry() == li_wall[i]->y())
        {
            leftno_box2 = 1;
        }
        if (box3->cor.rx() - 50 == li_wall[i]->x() && box3->cor.ry() == li_wall[i]->y())
        {
            leftno_box3 = 1;
        }
    }
    //假如上面有牆壁
    for (int i = 0; i < li_wall.size(); i++) {
        if (box1->cor.rx() == li_wall[i]->x() && box1->cor.ry() - 50 == li_wall[i]->y())
        {
            upno_box1 = 1;
        }
        if (box2->cor.rx() == li_wall[i]->x() && box2->cor.ry() - 50 == li_wall[i]->y())
        {
            upno_box2 = 1;
        }
        if (box3->cor.rx() == li_wall[i]->x() && box3->cor.ry() - 50 == li_wall[i]->y())
        {
            upno_box3 = 1;
        }
    }
    //假如下面有牆壁
    for (int i = 0; i < li_wall.size(); i++) {
        if (box1->cor.rx() == li_wall[i]->x() && box1->cor.ry() + 50 == li_wall[i]->y())
        {
            downno_box1 = 1;
        }
        if (box2->cor.rx() == li_wall[i]->x() && box2->cor.ry() + 50 == li_wall[i]->y())
        {
            downno_box2 = 1;
        }
        if (box3->cor.rx() == li_wall[i]->x() && box3->cor.ry() + 50 == li_wall[i]->y())
        {
            downno_box3 = 1;
        }
    }
}
void GameController::check() //這是人物檢查
{

    //假如右邊有牆壁
    for (int i = 0; i < li_wall.size(); i++) {
        if (ch->head.rx() + 50 == li_wall[i]->x() && ch->head.ry() == li_wall[i]->y())
        {
            rightno = 1;
        }
    }
    //假如左邊有牆壁
    for (int i = 0; i < li_wall.size(); i++) {
        if (ch->head.rx() - 50 == li_wall[i]->x() && ch->head.ry() == li_wall[i]->y())
        {
            leftno = 1;
        }
    }
    //假如上面有牆壁
    for (int i = 0; i < li_wall.size(); i++) {
        if (ch->head.rx() == li_wall[i]->x() && ch->head.ry() - 50 == li_wall[i]->y())
        {
            upno = 1;
        }
    }
    //假如下面有牆壁
    for (int i = 0; i < li_wall.size(); i++) {
        if (ch->head.rx() == li_wall[i]->x() && ch->head.ry() + 50 == li_wall[i]->y())
        {
            downno = 1;
        }
    }

}
void GameController::checkbox_box(){
    for (int i = 0; i < li_box.size(); i++) {
        if(box1->cor.rx()+50==li_box[i]->x()&&box1->cor.ry()==li_box[i]->y())
        {
            rightnobox1_box=1;
        }
        else if(box2->cor.rx()+50==li_box[i]->x()&&box2->cor.ry()==li_box[i]->y())
        {
            rightnobox2_box=1;
        }
        else if(box3->cor.rx()+50==li_box[i]->x()&&box3->cor.ry()==li_box[i]->y())
        {
            rightnobox3_box=1;
        }

        if(box1->cor.rx()-50==li_box[i]->x()&&box1->cor.ry()==li_box[i]->y())
        {
            leftnobox1_box=1;
        }
        else if(box2->cor.rx()-50==li_box[i]->x()&&box2->cor.ry()==li_box[i]->y())
        {
            leftnobox2_box=1;
        }
        else if(box3->cor.rx()-50==li_box[i]->x()&&box3->cor.ry()==li_box[i]->y())
        {
            leftnobox3_box=1;
        }

        if(box1->cor.rx()==li_box[i]->x()&&box1->cor.ry()-50==li_box[i]->y())
        {
           upnobox1_box=1;
        }
        else if(box2->cor.rx()==li_box[i]->x()&&box2->cor.ry()-50==li_box[i]->y())
        {
            upnobox2_box=1;
        }
        else if(box3->cor.rx()==li_box[i]->x()&&box3->cor.ry()-50==li_box[i]->y())
        {
            upnobox3_box=1;
        }

        if(box1->cor.rx()==li_box[i]->x()&&box1->cor.ry()+50==li_box[i]->y())
        {
           downnobox1_box=1;
        }
        else if(box2->cor.rx()==li_box[i]->x()&&box2->cor.ry()+50==li_box[i]->y())
        {
           downnobox2_box=1;
        }
        else if(box3->cor.rx()==li_box[i]->x()&&box3->cor.ry()+50==li_box[i]->y())
        {
            downnobox3_box=1;
        }
    }
    if(ch->head.rx()+50==box1->cor.rx()&&ch->head.ry()==box1->cor.ry())
    {
     rightnoch_box1=1;
    }
    else if(ch->head.rx()+50==box2->cor.rx()&&ch->head.ry()==box2->cor.ry())
    {
     rightnoch_box2=1;
    }
    else if(ch->head.rx()+50==box3->cor.rx()&&ch->head.ry()==box3->cor.ry())
    {
     rightnoch_box3=1;
    }

    if(ch->head.rx()-50==box1->cor.rx()&&ch->head.ry()==box1->cor.ry())
    {
     leftnoch_box1=1;
    }
    else if(ch->head.rx()-50==box2->cor.rx()&&ch->head.ry()==box2->cor.ry())
    {
     leftnoch_box2=1;
    }
    else if(ch->head.rx()-50==box3->cor.rx()&&ch->head.ry()==box3->cor.ry())
    {
     leftnoch_box3=1;
    }

    if(ch->head.rx()==box1->cor.rx()&&ch->head.ry()-50==box1->cor.ry())
    {
     upnoch_box1=1;
    }
    else if(ch->head.rx()==box2->cor.rx()&&ch->head.ry()-50==box2->cor.ry())
    {
     upnoch_box2=1;
    }
    else if(ch->head.rx()==box3->cor.rx()&&ch->head.ry()-50==box3->cor.ry())
    {
     upnoch_box3=1;
    }

    if(ch->head.rx()==box1->cor.rx()&&ch->head.ry()+50==box1->cor.ry())
    {
     downnoch_box1=1;
    }
    else if(ch->head.rx()==box2->cor.rx()&&ch->head.ry()+50==box2->cor.ry())
    {
     downnoch_box2=1;
    }
    else if(ch->head.rx()==box3->cor.rx()&&ch->head.ry()+50==box3->cor.ry())
    {
     downnoch_box3=1;
    }
}
void GameController::clearall(){
   leftnoch_box1=0, leftnoch_box2=0,leftnoch_box3=0;
   rightnoch_box1=0,rightnoch_box2=0,rightnoch_box3=0;
   upnoch_box1=0,upnoch_box2=0,upnoch_box3=0;
   downnoch_box1=0,downnoch_box2=0,downnoch_box3=0;

    leftnobox1_box=0, leftnobox2_box=0, leftnobox3_box=0;
    rightnobox1_box=0,rightnobox2_box=0,rightnobox3_box=0;
    upnobox1_box=0,upnobox2_box=0,upnobox3_box=0;
    downnobox1_box=0,downnobox2_box=0,downnobox3_box=0;

   leftno_box1=0, rightno_box1=0, upno_box1=0, downno_box1=0;
   leftno_box2=0, rightno_box2=0, upno_box2=0, downno_box2=0;
   leftno_box3=0, rightno_box3=0, upno_box3=0, downno_box3=0;

   leftno=0,rightno=0,upno=0,downno=0;

   winpoint1=0,winpoint2=0,winpoint3=0;

}
void GameController::findwall() {
    QList<QGraphicsItem *> listing = scene.items();
    for (int o = 0; o<listing.size(); o++) {
        if (listing[o]->data(GD_Type) == GO_Wall) {
            li_wall.append(listing[o]);
        }
    }
}
void GameController::check_box_on_icon()
{
    for (int i = 0; i < li_icon.size(); i++)
    {
        if (box1->cor.rx() == li_icon[i]->x() && box1->cor.ry() == li_icon[i]->y())
        {
            winpoint1 = 1;
        }

        if (box2->cor.rx() == li_icon[i]->x() && box2->cor.ry() == li_icon[i]->y())
        {
            winpoint2 = 1;
        }

        if (box3->cor.rx() == li_icon[i]->x() && box3->cor.ry() == li_icon[i]->y())
        {
            winpoint3 = 1;
        }
    }

}
void GameController::chechcomplete(){

    if (winpoint1==1&&winpoint2==1&&winpoint3==1)
    {
        Button* nextlevelButton = new Button(QString("Level 2(Restart)"));
        nextlevelButton->setPos(-200, 150);
        scene.addItem(nextlevelButton);
        connect(nextlevelButton, SIGNAL(clicked()), this, SLOT(secondlevel()));
    }
    if (winpoint1==1&&winpoint2==1&&winpoint3==1&&score==30)
    {
        Button* Youwin = new Button(QString("Youwin!!!!"));
        Youwin->setPos(-100, 150);
        scene.addItem(Youwin);

    }
}
void GameController::sanseatfood(Character *ch,Food*food ){
  score+=10;
  food->cor_food.rx()=500;
  food->cor_food.ry()=500;
  food->setPos(food->cor_food);
  showscore();
}
void GameController::sansintrap(Character *ch,Trap*trap ){
    determination=-999;
    showlove();
    die=1;
}
void GameController::sansindoor(Character *ch,Door*door ){
    Button* nextlevelButton = new Button(QString("Level 2(Restart)"));
    nextlevelButton->setPos(-200, 150);
    scene.addItem(nextlevelButton);
    connect(nextlevelButton, SIGNAL(clicked()), this, SLOT(secondlevel()));
}
void GameController::sansinrod(Character *ch,Rod*rod ){
    trap2->cor_trap.rx()= 300;
    trap2->cor_trap.ry()=350;
    trap2->setPos(trap2->cor_trap);
    trap3->cor_trap.rx()=300;
    trap3->cor_trap.ry()=350;
    trap3->setPos(trap3->cor_trap);
}
void GameController::sansinstick(Character *ch,Joystick *stick ){
    ch->head.rx()=50;
    ch->head.ry()=150;
    ch->setPos( ch->head);


    scene.update();
}
void GameController::sansinstick2(Character *ch,Joystick *stick ){
    ch->head.rx()=0;
    ch->head.ry()=0;
    ch->setPos( ch->head);
    scene.update();
}

