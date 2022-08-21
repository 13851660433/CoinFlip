#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    //重写绘图事件
    void paintEvent(QPaintEvent *event);
    //游戏场景对象指针
    PlayScene* play = NULL;
    void connectPlayScene();
signals:
    //告诉主场景，我要返回
    void chooseSceneBack();
    void sendSelf();

private:
    //位置
    int current_x;
    int current_y;

};

#endif // CHOOSELEVELSCENE_H
