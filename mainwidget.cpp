#include "mainwidget.hpp"

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>

GameFieldWidget::GameFieldWidget(QWidget *parent)
    : QWidget(parent) {
          // painter.Array is [20][10] => height=20 rows, width=10 cols
          // so width in cells = 10, height in cells = 20
          setFixedSize(10 * CELL_SIZE, 20 * CELL_SIZE);
          // accept keyboard focus so keyPressEvent is called
          setFocusPolicy(Qt::StrongFocus);
          setFocus();

          _gameEngine.Init();
          update();
            
    }

    
    void GameFieldWidget::paintEvent(QPaintEvent *) {
        QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (int r = 0; r < 20; ++r) {
        for (int c = 0; c < 10; ++c) {
        QRect cellRect(c * CELL_SIZE, r * CELL_SIZE, CELL_SIZE, CELL_SIZE);

        if (_gameEngine.painter.Array[r][c] == 0)   {
            painter.fillRect(cellRect, Qt::white);
        } else if (_gameEngine.painter.Array[r][c] == 1) {
            painter.fillRect(cellRect, Qt::green);
        } else if (_gameEngine.painter.Array[r][c] == 2) {
            painter.fillRect(cellRect, Qt::red);
        }

        painter.setPen(Qt::gray);
        painter.drawRect(cellRect);

        }
    }
}

void GameFieldWidget::gameTick() {
    _gameEngine.Run(userAction);
    update();
}

void GameFieldWidget::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Up:
      this->userAction = Direction::Top;
      break;
    case Qt::Key_Down:
      this->userAction = Direction::Bottom;
      break;
    case Qt::Key_Left:
      this->userAction = Direction::Left;
      break;
    case Qt::Key_Right:
      this->userAction = Direction::Right;
      break;
    default:
      break;
  }
    int key = event->key();
    qDebug() << "Pressed key code:" << key;
//   if (!gamePaused) {
//     userInput(this->userAction, true);
//   }
//   if (this->userAction == Terminate) {
//     exit(0);
//   }

//   if (this->userAction == Pause) {
//     this->userAction = Start;
//     gamePaused = !gamePaused;
//     emit pauseToggled();
//     update();
//   } else {
//     this->userAction = Start;
//     emit userInputDetected();
//   }

  // QWidget::keyPressEvent(event);
}