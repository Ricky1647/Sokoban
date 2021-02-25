#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QGraphicsScene;
class QGraphicsView;
class GameController;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void startgame(); //開啟遊戲，所以還不需用加
    void adjustViewSize();
private:
    Ui::MainWindow *ui;
    void initScene();
    void initSceneBackground();//只是加橫線現在不用加
    QGraphicsScene *scene;
    QGraphicsView *view;
    GameController *game;
};
#endif // MAINWINDOW_H
