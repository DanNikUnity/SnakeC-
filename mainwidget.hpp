#ifndef GAMEFIELDWIDGET_H
#define GAMEFIELDWIDGET_H
#include <QDebug>
#include "game_engine.hpp"

#include <QWidget>

class GameFieldWidget : public QWidget {
  Q_OBJECT

 public:
  GameFieldWidget(QWidget *parent);
 public slots:
 void gameTick();


 private:
GameEngine _gameEngine;
    Direction userAction = Direction::Right;

  protected:
  void paintEvent(QPaintEvent * event) override;
  void keyPressEvent(QKeyEvent *event) override;

 static constexpr int CELL_SIZE = 40;
};

#endif