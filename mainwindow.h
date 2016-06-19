#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QKeyEvent>
#include <QLabel>


#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <enemy.h>
#include <wood.h>
#include <arrow.h>
#include <bird_black.h>
#include <bird_blue.h>
#include <bird_red.h>
#include <bird_yellow.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void restartgame();
    void exitgame();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    Bird_red *b1;
    Bird_blue *b2;
    Bird_black *b3;
    Bird_yellow *b4;
    Enemy *e1;
    Enemy *e2;
    QLabel *score;
    QPushButton *restart;
    QPushButton *exit;
    void init();
    int count,num,s,v1,v2;
    float start_x,start_y,end_x,end_y;//,step_x,step_y;
    bool kill,kill1,skillstatus;
    void game();

};

#endif // MAINWINDOW_H
