#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    setFixedSize(320, 600);
    setWindowIcon(QIcon(":/res/Fish.ico"));
    setWindowTitle("ChooseScene");

    QMenuBar* bar = menuBar();
    setMenuBar(bar);
    QMenu* startMenu = bar->addMenu("File");
    QAction* quitAction = startMenu->addAction("exit");
    connect(quitAction, &QAction::triggered, this, &ChooseLevelScene::close);

    //选择场景返回按钮
    MyPushButton* backBtn = new MyPushButton(":/res/Cow.ico", ":/res/Dog-Flat Ears.ico");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    //点击返回
    connect(backBtn, &MyPushButton::clicked, [=](){
        //关卡场景延时返回
        QTimer::singleShot(200, this, [=](){
            emit this->chooseSceneBack();
        });
    });

    connect(this, &ChooseLevelScene::sendSelf, this, &ChooseLevelScene::connectPlayScene);

    //创建选择关卡的按钮
    for(int i = 0; i < 20; i++)
    {
        MyPushButton* menuBtn = new MyPushButton(":/res/favicon.ico");
        menuBtn->setParent(this);
        menuBtn->move(30 + i%4 * 65, 155 + i/4 * 65);
        //监听点击关卡事件
        connect(menuBtn, &MyPushButton::clicked, [=](){
            //隐藏当前的选择关卡并保存当前位置
            this->current_x = this->x();
            this->current_y = this->y();
            this->hide();
            //进入play场景
            play = new PlayScene(i+1);
            play->move(this->current_x, this->current_y);
            play->show();
            connect(play, &PlayScene::chooseSceneBack, [=](){
                //关闭前保存当前位置
                this->current_x = play->x();
                this->current_y = play->y();
                this->move(this->current_x, this->current_y);
                this->show();
                delete play;
                play = NULL;
            });
            emit this->sendSelf();
        });


        //设置字体
        QFont* font = new QFont;
        font->setFamily("KaiTi");
        font->setPointSize(20);
        font->setPixelSize(20);
        //添加关卡数字
        QLabel* label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(30 + i%4 * 65, 155 + i/4 * 65);
        label->setFont(*font);
        //设置文字对齐
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置让鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::connectPlayScene()
{
    //接受关闭play场景关卡
    connect(play, &PlayScene::closePlayScene, [=](){
        //删除前保存当前位置
        QTimer::singleShot(200, this, [=](){
            this->current_x = play->x();
            this->current_y = play->y();
            int level = play->levelIndex;
            if(level == 20)
            {
                level = 0;
            }
            delete play;
            play = new PlayScene(level + 1);
            play->move(this->current_x, this->current_y);
            play->show();
            emit this->sendSelf();  //断开后再次连接上
            connect(play, &PlayScene::chooseSceneBack, [=](){
                this->current_x = play->x();
                this->current_y = play->y();
                this->move(this->current_x, this->current_y);
                this->show();
                delete play;
                play = NULL;
            });
        });
    });
}

void ChooseLevelScene::paintEvent(QPaintEvent *event)
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
