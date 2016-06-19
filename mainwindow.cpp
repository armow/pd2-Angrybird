#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/back.jpg").scaled(960,450));
    score=new QLabel(this);
    score->setStyleSheet("color:black");
    score->setFont(QFont("Timers",28));
    score->setText("Score : 0");
    score->setGeometry(220,0,200,100);
    score->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    game();
    init();
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

}

void MainWindow::game()
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,1200,540);
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width()*1.5,height()/6.0),world,scene));
    //Create arrow
    itemList.push_back(new Arrow(6,4.8,1,2,QPixmap(":/arrow.png").scaled(50,115),world,scene));
    // Create bird
    b1 = new Bird_red(6.3,8.0f,1.0f,&timer,QPixmap(":/angrybird-red.png").scaled(55,55),world,scene);
    itemList.push_back(b1);
    b2 = new Bird_blue(4.5f,4.0f,1.0f,&timer,QPixmap(":/angrybird-blue.png").scaled(55,55),world,scene);
    itemList.push_back(b2);
    b3 = new Bird_black(4,4.0f,1.0f,&timer,QPixmap(":/angrybird-black.png").scaled(60,60),world,scene);
    itemList.push_back(b3);
    b4 = new Bird_yellow(3.5,4.0f,1.0f,&timer,QPixmap(":/angrybird-yellow.png").scaled(55,55),world,scene);
    itemList.push_back(b4);
    //Create enemy
    e1=new Enemy(22.5,5,1.0,&timer,QPixmap(":/angrybird-green.png").scaled(55,55),world,scene);
    itemList.push_back(e1);
    e2=new Enemy(26,5,1.0,&timer,QPixmap(":/angrybird-green.png").scaled(55,55),world,scene);
    itemList.push_back(e2);

    // Timer
    /*connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);*/

    //Create wood
    itemList.push_back(new Wood(21,5,1,3,&timer,QPixmap(":/w3.png").scaled(20,90),world,scene));
    itemList.push_back(new Wood(24.5,5,1,3,&timer,QPixmap(":/w3.png").scaled(20,90),world,scene));
    itemList.push_back(new Wood(28,5,1,3,&timer,QPixmap(":/w3.png").scaled(20,90),world,scene));
    itemList.push_back(new Wood(21.1,5.5,2.7,1,&timer,QPixmap(":/w1.png").scaled(130,25),world,scene));
    itemList.push_back(new Wood(24.4,5.5,3,1,&timer,QPixmap(":/w1.png").scaled(150,25),world,scene));
    itemList.push_back(new Wood(22,9,2.5,2.5,&timer,QPixmap(":/ice.png").scaled(70,70),world,scene));
    itemList.push_back(new Wood(25,9,2.5,2.5,&timer,QPixmap(":/ice.png").scaled(70,70),world,scene));
    //Create restart button
    restart=new QPushButton;
    restart->setIcon(QPixmap("restart.png"));
    restart->setIconSize(QSize(60,60));
    restart->setGeometry(430,0,100,100);
    restart->setStyleSheet("background-color:transparent");
    scene->addWidget(restart);
    connect(restart,SIGNAL(clicked(bool)),this,SLOT(restartgame()));
    //Create exit button
    exit=new QPushButton;
    exit->setIcon(QPixmap("exit.png"));
    exit->setIconSize(QSize(60,60));
    exit->setGeometry(500,0,100,100);
    exit->setStyleSheet("background-color:transparent");
    scene->addWidget(exit);
    connect(exit,SIGNAL(clicked(bool)),this,SLOT(exitgame()));
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    //MousePress
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent= static_cast<QMouseEvent*>(event);
        if(mouseEvent->button()== Qt::LeftButton)
        {
            //qDebug()<<mouseEvent->pos().x()<<mouseEvent->pos().y();
            start_x=mouseEvent->pos().x();
            start_y=mouseEvent->pos().y();

        }


    }
    else if(event->type() == QEvent::MouseMove)
    {
        /*if(mousepress==true)
        {
        step_x=b1->getPosition().x;
        step_y=b1->getPosition().y;
        //qDebug()<<step_x<<step_y;
        }*/
    }
    else if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouseEvent= static_cast<QMouseEvent*>(event);
        if(mouseEvent->button()== Qt::LeftButton)
        {
            if(num==1)
            {
                num=4;
                end_x=mouseEvent->pos().x();
                end_y=mouseEvent->pos().y();
                b2->setLinearVelocity(b2Vec2((start_x-end_x)/15,(end_y-start_y)/15));

            }
            else if(num==2)
            {
                num=4;
                end_x=mouseEvent->pos().x();
                end_y=mouseEvent->pos().y();
                b3->setLinearVelocity(b2Vec2((start_x-end_x)/15,(end_y-start_y)/15));
            }
            else if(num==3)
            {
                num=4;
                end_x=mouseEvent->pos().x();
                end_y=mouseEvent->pos().y();
                b4->setLinearVelocity(b2Vec2((start_x-end_x)/15,(end_y-start_y)/15));
            }
            else if(num==0)
            {
                num=4;
                end_x=mouseEvent->pos().x();
                end_y=mouseEvent->pos().y();
                b1->setLinearVelocity(b2Vec2((start_x-end_x)/15,(end_y-start_y)/15));
            }
        }
    }
    //KeyPress
    else if(event->type()== QEvent::KeyPress)
    {
        QKeyEvent *keyevent=static_cast<QKeyEvent*>(event);
        if(keyevent->key()==Qt::Key_Z)
        {
            count++;
            if(count>5){
                num=1;
                count=0;
                delete b1;
                delete b2;
                b2 = new Bird_blue(6.3f,8.0f,1.0f,&timer,QPixmap(":/angrybird-blue.png").scaled(55,55),world,scene);
                skillstatus=true;
            }
        }
        else if(keyevent->key()==Qt::Key_X)
        {
            count++;
            if(count>5){
                num=2;
                count=0;
                delete b2;
                delete b3;
                b3 = new Bird_black(6.3f,8.0f,1.0f,&timer,QPixmap(":/angrybird-black.png").scaled(60,60),world,scene);
                skillstatus=true;
            }
        }
        else if(keyevent->key()==Qt::Key_C)
        {
            count++;
            if(count>5){
                num=3;
                count=0;
                delete b3;
                delete b4;
                b4 = new Bird_yellow(6.3f,8.0f,1.0f,&timer,QPixmap(":/angrybird-yellow.png").scaled(55,55),world,scene);
                skillstatus=true;
            }
        }
        //Skill
        else if(keyevent->key()==Qt::Key_A)
        {
            if(skillstatus==true){
            b2->skill();
            skillstatus=false;
            }
        }
        else if(keyevent->key()==Qt::Key_S)
        {
            if(skillstatus==true){
            b3->skill();
            skillstatus=false;
            }
        }
        else if(keyevent->key()==Qt::Key_D)
        {
            if(skillstatus==true){
            b4->skill();
            skillstatus=false;
            }
        }

    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
    v1=e1->getLinearVelocity().x;
    v2=e2->getLinearVelocity().x;
    if(kill==false)
    {
        if(v1>15){
            kill=true;
            s=s+5000;
            delete e1;
        }

    }
    if(kill1==false)
    {
        if(v2>15){
            kill1=true;
            s=s+5000;
            delete e2;
        }
    }
    if(v1>5){
        if(kill==false)
            s+=100;
    }
    if(v2>5){
        if(kill1==false)
            s+=100;
    }
    score->setText("Score : "+QString::number(s));
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::restartgame()
{
    itemList.clear();
    game();
    init();

}

void MainWindow::exitgame()
{
    close();
}

void MainWindow::init()
{
    start_x=0;
    start_y=0;
    end_x=0;
    end_y=0;
    //step_x=0;
    //step_y=0;
    kill=false;
    kill1=false;
    count=0;
    num=0;
    s=0;
    v1=0;
    v2=0;
    skillstatus=false;

}
