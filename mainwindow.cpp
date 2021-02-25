#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QGraphicsView>
#include<QGraphicsTextItem>
#include"button.h"
#include "gamecontroller.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene, this))
    //ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    setCentralWidget(view);
        resize(600, 600);
        initScene();
        initSceneBackground();
        QTimer::singleShot(0, this, SLOT(adjustViewSize()));
        QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Sokuban"));
        QFont titleFont("comic sans", 20);
        titleText->setFont(titleFont);
        titleText->setPos(-100,-100);
        scene->addItem(titleText);
        Button* playButton = new Button(QString("Play"));
        playButton->setPos(-100, 0);
        scene->addItem(playButton);
        connect(playButton, SIGNAL(clicked()), this, SLOT(startgame()));
}

MainWindow::~MainWindow()
{
    //delete ui;
}
void MainWindow::initScene()
{
     scene->setSceneRect(-200, -200, 400,400);

}
void MainWindow::initSceneBackground(){
    qreal TILE_SIZE = 50;
    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);
    view->setBackgroundBrush(QBrush(bg));
}
void MainWindow::adjustViewSize()
{
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}
void MainWindow::startgame()
{
    QTimer time(0);
    scene->clear();
    scene->update();
    game = new GameController(*scene, this);
}

