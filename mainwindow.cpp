#include "mainwindow.hpp"

#include <QVBoxLayout>
#include <QWidget>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QVBoxLayout *layout = new QVBoxLayout(centralWidget);
  gameFieldWidget = new GameFieldWidget(this);
  layout->addWidget(gameFieldWidget);
  snakeTimer = new SnakeTimer(this);
    connect(snakeTimer, &SnakeTimer::tick, gameFieldWidget,
          &GameFieldWidget::gameTick);

snakeTimer->start(200);

}

  MainWindow::~MainWindow(){}

  