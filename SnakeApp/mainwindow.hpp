#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timer.hpp"
#include "mainwidget.hpp"
#include "gameoverdialog.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onGameOver();
    void onReplayClicked();

private:
    GameFieldWidget *gameFieldWidget;
    SnakeTimer *snakeTimer;
    GameOverDialog *gameOverDialog;
};

#endif
