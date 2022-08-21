#include "playscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>

//PlayScene::PlayScene(QWidget *parent)
//    : QMainWindow{parent}
//{

//}

PlayScene::PlayScene(int levelNum)
{
//    QString str = QString("进入到第%1关卡").arg(levelNum);
//    qDebug() << str;
    this->levelIndex = levelNum;

    setFixedSize(320, 600);
    setWindowIcon(QIcon(":/res/Fish.ico"));
    setWindowTitle("Playscene");

    QMenuBar* bar = menuBar();
    setMenuBar(bar);
    QMenu* startMenu = bar->addMenu("File");
    QAction* quitAction = startMenu->addAction("exit");
    connect(quitAction, &QAction::triggered, this, &PlayScene::close);

    //选择场景返回按钮
    MyPushButton* backBtn = new MyPushButton(":/res/Cow.ico", ":/res/Dog-Flat Ears.ico");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    //点击返回
    connect(backBtn, &MyPushButton::clicked, [=](){
        //关卡场景延时返回
//        qDebug() << "返回选择关卡";
        QTimer::singleShot(200, this, [=](){
            emit this->chooseSceneBack();
        });
    });

    //显示当前关卡数
    QString current = QString("Level:%1").arg(this->levelIndex);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    font.setBold(true);
    QLabel* label = new QLabel;
    label->setParent(this);
    label->setText(current);
    label->setGeometry(30, this->height() - 160, 140, 50);
    label->setFont(font);

    //显示游戏胜利字样
    QString wins = QString("第%1关胜利").arg(this->levelIndex);
    QFont fontWin;
    fontWin.setFamily("华文新魏");
    fontWin.setPointSize(20);
    fontWin.setBold(true);
    QLabel* labelWin = new QLabel;
    labelWin->setParent(this);
    labelWin->setText(wins);
    labelWin->setGeometry(30, this->height(), 140, 50);
    labelWin->setFont(fontWin);
//    labelWin->setHidden(true);

    //初始化每个关卡的二维数组
    dataconfig config;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //胜利图标
    MyPushButton* winbutton = new MyPushButton(":/res/Shark.ico");
    winbutton->setParent(this);
    winbutton->setGeometry(150, -winbutton->height(), winbutton->width(), winbutton->height());
    connect(winbutton, &MyPushButton::clicked, [=](){
       winbutton->zoom1();
       winbutton->zoom2();
       //发送关闭关卡信号
       emit this->closePlayScene();
    });

    //游戏场景中金币背景
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            QPixmap pix = QPixmap(":/res/playback.jpeg");
            QLabel* label = new QLabel;
            label->setGeometry(0, 0, 63, 63);
            label->setPixmap(pix);
            label->setParent(this);
            label->move(30 + i * 65, 160 + j * 65);

            //生成金币
            QString qstr;
            if(this->gameArray[i][j] == 1)
            {
                qstr = ":/res/Dog-High Ears.ico";
            }
            else
            {
                qstr = ":/res/Flying-Chicken.ico";
            }
            Mycoin* coin = new Mycoin(qstr);
            coin->setParent(this);
            coin->move(38 + i * 65, 167 + j * 65);

            //给金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];
            //保存金币位置
            coinBtn[i][j] = coin;
            //点击金币，进行翻转
            connect(coin, &Mycoin::clicked, [=](){
                coin->changeFlag();
                QTimer::singleShot(100, this, [=](){
                    if(coin->posX + 1 <= 3)
                    {
                        coinBtn[coin->posX+1][coin->posY] -> changeFlag();
                    }
                    if(coin->posX - 1 >= 0)
                    {
                        coinBtn[coin->posX-1][coin->posY] -> changeFlag();
                    }
                    if(coin->posY + 1 <= 3)
                    {
                        coinBtn[coin->posX][coin->posY+1] -> changeFlag();
                    }
                    if(coin->posY - 1 >= 0)
                    {
                        coinBtn[coin->posX][coin->posY-1] -> changeFlag();
                    }

                    //判断是否胜利
                    this->isWin = true;
                    for(int i = 0; i < 4; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                            if(coinBtn[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }

                    if(this->isWin)
                    {
//                        qDebug() << "游戏胜利";
                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < 4; j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }
                        }
                        //创建动态对象
                        QPropertyAnimation* animation = new QPropertyAnimation(winbutton, "geometry");
                        //设置动画时间间隔
                        animation->setDuration(500);
                        //起始位置
                        animation->setStartValue(QRect(winbutton->x(), winbutton->y(), winbutton->width(), winbutton->height()));
                        //结束位置
                        animation->setEndValue(QRect(winbutton->x(), winbutton->y() + winbutton->height() + 30, winbutton->width(), winbutton->height()));
                        //设置弹跳曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //执行动画
                        animation->start();

                        //创建动态对象
                        QPropertyAnimation* animation1 = new QPropertyAnimation(labelWin, "geometry");
                        //设置动画时间间隔
                        animation1->setDuration(500);
                        //起始位置
                        animation1->setStartValue(QRect(labelWin->x(), labelWin->y(), labelWin->width(), labelWin->height()));
                        //结束位置
                        animation1->setEndValue(QRect(labelWin->x(), labelWin->y() - 190, labelWin->width(), labelWin->height()));
                        //设置弹跳曲线
                        animation1->setEasingCurve(QEasingCurve::OutBounce);
                        //执行动画
                        animation1->start();
                    }
                });
            });
        }
    }
}

void PlayScene::paintEvent(QPaintEvent *event)
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
    result = pix.load(":/res/Skunk.ico");
    if(result)
    {
        pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
        painter.drawPixmap(10, 30, pix);
    }
}
