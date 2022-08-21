#include "mycoin.h"

//Mycoin::Mycoin(QWidget *parent)
//    : QPushButton{parent}
//{

//}

Mycoin::Mycoin(QString btnImg)
{
    //设置为false的值
    this->isWin = false;

    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        QString str = QString("加载 1% 失败").arg(btnImg);
        qDebug() << str;
        return;
    }
    this->setFixedSize(50, 50);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(50, 50));

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //飞鸡变狗
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Dog-High Ears.ico");
        bool ret = pix.load(str);
        if(!ret)
        {
            qDebug() << "加截play出错";
            return;
        }
        this->setFixedSize(50, 50);
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(50, 50));
        timer1->stop();
        //多张图片的时候可以继续反转
//        if(this->min > this->max)
//        {
//            this->min = 1;
//            timer1->stop();
//        }
    });
    //狗变飞鸡
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Flying-Chicken.ico");
        bool ret = pix.load(str);
        if(!ret)
        {
            qDebug() << "加截play出错";
            return;
        }
        this->setFixedSize(50, 50);
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(50, 50));
        timer2->stop();
        //多张图片的时候可以继续反转
//        if(this->min > this->max)
//        {
//            this->min = 1;
//            timer1->stop();
//        }
    });
}

void Mycoin::changeFlag()
{
    //记录一下问题，狗为false 鸡为true 为什么？？
    if(!this->flag)
    {
        timer1->start(30);
        this->flag = true;
    }
    else
    {
        timer2->start(30);
        this->flag = false;
    }
}

void Mycoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isWin)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}
