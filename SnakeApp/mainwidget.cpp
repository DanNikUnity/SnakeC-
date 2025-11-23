#include "mainwidget.hpp"
#include <QKeyEvent>
#include <QPainter>
#include <QDebug>

GameFieldWidget::GameFieldWidget(QWidget *parent) 
    : QWidget(parent)
    , _gameEngine(std::make_unique<GameEngine>())
{
    setFixedSize(10 * CELL_SIZE, 20 * CELL_SIZE);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    _gameEngine->Init();
    update();
}

void GameFieldWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const auto& gameArray = _gameEngine->GetPainter().Array;

    for (size_t r = 0; r < gameArray.size(); ++r) {
        for (size_t c = 0; c < gameArray[r].size(); ++c) {

            QRect cellRect(static_cast<int>(c) * CELL_SIZE,
                           static_cast<int>(r) * CELL_SIZE,
                           CELL_SIZE, CELL_SIZE);

            if (gameArray[r][c] == 0) {
                painter.fillRect(cellRect, Qt::white);
            } else if (gameArray[r][c] == 1) {
                painter.fillRect(cellRect, Qt::green);
            } else if (gameArray[r][c] == 2) {
                painter.fillRect(cellRect, Qt::red);
            }

            painter.setPen(Qt::gray);
            painter.drawRect(cellRect);
        }
    }
}

void GameFieldWidget::gameTick()
{
    _gameEngine->Run(userAction);

    if (_gameEngine->IsGameOver()) {
        emit gameOverTriggered();
        return;
    }

    update();
}

void GameFieldWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Up:    userAction = Direction::Top;    break;
        case Qt::Key_Down:  userAction = Direction::Bottom; break;
        case Qt::Key_Left:  userAction = Direction::Left;   break;
        case Qt::Key_Right: userAction = Direction::Right;  break;
        default: break;
    }

    QWidget::keyPressEvent(event);
}

void GameFieldWidget::resetGame()
{
    _gameEngine = std::make_unique<GameEngine>();
    _gameEngine->Init();
    userAction = Direction::Right;
    setFocus();
    update();
}
