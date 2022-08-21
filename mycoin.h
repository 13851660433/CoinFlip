#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class Mycoin : public QPushButton
{
    Q_OBJECT

public:
    //explicit Mycoin(QWidget *parent = nullptr);
    Mycoin(QString btnImg);
    //金币属性
    int posX;
    int posY;
    bool flag;
    //改变标志的方法
    void changeFlag();
    QTimer* timer1 = NULL;
    QTimer* timer2 = NULL;
    int min = 1;
    int max = 8;
    //判断胜利
    bool isWin;

    void mousePressEvent(QMouseEvent *e);

signals:

};

#endif // MYCOIN_H
