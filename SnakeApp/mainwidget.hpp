#ifndef GAMEFIELDWIDGET_H
#define GAMEFIELDWIDGET_H

#include "game_engine.hpp"
#include <QWidget>
#include <memory>

class GameFieldWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameFieldWidget(QWidget *parent = nullptr);

public slots:
    void gameTick();
    void resetGame();

private:
    std::unique_ptr<GameEngine> _gameEngine;
    Direction userAction = Direction::Right;
    
protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    
    static constexpr int CELL_SIZE = 40;

signals:
    void gameOverTriggered();

};

#endif