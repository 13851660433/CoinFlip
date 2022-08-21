#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMenu>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include <QPropertyAnimation>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //配置主场景
    setFixedSize(320, 600);
    setWindowIcon(QIcon(":/res/Fish.ico"));
    setWindowTitle("CoinFlip");

    //设置共用图标
    QIcon* ic = new QIcon(":/res/Skunk.ico");

    //设置菜单栏
    QMenu *menu = this->menuBar()->addMenu("File");
    QAction* open = menu->addAction(*ic, "open");
    menu->addAction(*ic, "save");
    QAction* exitAction = menu->addAction(*ic, "exit");

    //打开设置二级目录
    QMenu* menu2 = new QMenu(this);
    menu2->addAction("1");
    open->setMenu(menu2);

    //点击exit时退出
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);

    //主界面文字
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    font.setBold(true);
    QLabel* label = new QLabel;
    label->setParent(this);
    label->setText("游戏时间");
    label->setGeometry(this->width()/2/2, 300, this->width(), 100);
    label->setFont(font);
    QLabel* text = new QLabel;
    text->setParent(this);
    text->setFont(font);
    text->setGeometry(this->width()/2/2/2/2, -this->width(), this->width(), 100);

    QString sname[] = {"点击小鱼， 开始游戏", "点击小鱼， 开始游戏", "点击小鱼， 开始游戏", "不要再点了", "我已说了好几遍了", "受不了了", "周依依再点我要揍你了"};
    num = 0;
    //设置主界面左上角的图标按钮
    MyPushButton* bicon = new MyPushButton(":/res/Skunk.ico");
    bicon->setParent(this);
    bicon->move(10, 30);
    connect(bicon, &MyPushButton::clicked, [=](){
        //这里可设置按钮的动作
        bicon->zoom1();
        bicon->zoom2();
        int i = QRandomGenerator::global()->bounded(0, 5); //随机0-5之间的整数
        QString name = sname[num];
        text->setText(name);
        QPropertyAnimation* animation = new QPropertyAnimation(text, "geometry");
        animation->setDuration(500);
        animation->setStartValue(QRect(text->x(), -this->width(), text->width(), text->height()));
        animation->setEndValue(QRect(text->x(), 200, text->width(), text->height()));
        animation->setEasingCurve(QEasingCurve::OutBounce);
        animation->start();
        num++;
        if(num == 7)
        {
            num = i;
        }
        QTimer::singleShot(10000, this, [=](){
            text->setGeometry(this->width()/2/2/2/2, -this->width(), this->width(), 100);
        });
    });

    //开始按钮
    MyPushButton* startBtn = new MyPushButton(":/res/Fish.ico");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);
    //创建一个新窗口
    chooseScene = new ChooseLevelScene;
    //监听选择关卡返回按钮
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=](){
        //隐藏选择关卡
        this->current_x = chooseScene->x();
        this->current_y = chooseScene->y();
        chooseScene->hide();
        //显示主场景
        this->move(this->current_x, this->current_y);
        this->show();
    });
    //点击startBtn按钮
    connect(startBtn, &MyPushButton::clicked, [=](){
       startBtn->zoom1();
       startBtn->zoom2();
       //延时进入场景
       QTimer::singleShot(200, this, [=](){
           //隐藏主场景
           this->current_x = this->x();
           this->current_y = this->y();
           this->hide();
           //进入到选择关卡
           chooseScene->move(this->current_x, this->current_y);
           chooseScene->show();
       });
    });
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //背景图片
    QPainter painter(this);
    QPixmap pix;
    bool result;
    result = pix.load(":/res/black.jpeg");
    if(result)
    {
        painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    }

    //背景上面的图标
//    result = pix.load(":/res/Skunk.ico");
//    if(result)
//    {
//        pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
//        painter.drawPixmap(10, 30, pix);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

