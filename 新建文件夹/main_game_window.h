#ifndef MAIN_GAME_WINDOW_H
#define MAIN_GAME_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>
#include <QTimer>
#include <QMessageBox>
#include <QDebug> // 新添加的头文件
#include "game_model.h" // 新添加的头文件

namespace Ui {
class MainGameWindow;
}

class GameModel; // 前置声明游戏模型类

class MainGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGameWindow(QWidget *parent = nullptr);
    ~MainGameWindow();

protected:
    virtual void paintEvent(QPaintEvent *event);       // 界面重绘
    virtual void mousePressEvent(QMouseEvent *event);  // 鼠标控制

private:
    Ui::MainGameWindow *ui;
    GameModel *game;        // 游戏
    QTimer *timer;          // 计时器
    QLabel *timeLabel;      // 计时数字

    void handleGameState(GameModel *game); // 处理游戏状态

private slots:
    void onStartGameClicked();    // 开始游戏
    void onLevelChooseClicked();  // 选择游戏难度
    void onQuitClicked();         // 退出游戏
    void updateTimer();           // 计时
};

#endif // MAIN_GAME_WINDOW_H
