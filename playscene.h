#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);
    //用来记录当前所选关卡
    int levelIndex;
    //重写绘图事件
    void paintEvent(QPaintEvent *event);
    //用二维数组，维护每个关卡数据
    int gameArray[4][4];
    Mycoin * coinBtn[4][4];

    //判断是否胜利
    bool isWin;

signals:
    void chooseSceneBack();
    void closePlayScene();

};

#endif // PLAYSCENE_H
