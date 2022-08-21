#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //重写事件
    void paintEvent(QPaintEvent *event);

    ChooseLevelScene* chooseScene = NULL;
    int num;
private:
    Ui::MainWindow *ui;

    //位置
    int current_x;
    int current_y;
};
#endif // MAINWINDOW_H
