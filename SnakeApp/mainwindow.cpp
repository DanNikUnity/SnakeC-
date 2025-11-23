#include "mainwindow.hpp"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    gameFieldWidget = new GameFieldWidget(this);
    layout->addWidget(gameFieldWidget);

    snakeTimer = new SnakeTimer(this);
    connect(snakeTimer, &SnakeTimer::tick, gameFieldWidget, &GameFieldWidget::gameTick);

    connect(gameFieldWidget, &GameFieldWidget::gameOverTriggered,
            this, &MainWindow::onGameOver);

    snakeTimer->start(200);

    gameOverDialog = new GameOverDialog(this);
    connect(gameOverDialog, &GameOverDialog::replayClicked,
            this, &MainWindow::onReplayClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::onGameOver()
{
    snakeTimer->stop();
    gameOverDialog->show();
}

void MainWindow::onReplayClicked()
{
    gameOverDialog->hide();

    gameFieldWidget->resetGame();
    snakeTimer->start(200);
    gameFieldWidget->update();
}
