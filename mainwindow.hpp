#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "timer.hpp"

#include "mainwidget.hpp"

#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  GameFieldWidget *gameFieldWidget;
  SnakeTimer *snakeTimer;
};

#endif