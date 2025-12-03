/**
 * @file mainwindow.hpp
 * @author Nicolaev Dan
 * @date 2025
 * @brief Declarația ferestrei principale care conține jocul Snake.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "snaketimer.hpp"
#include "gamefieldwidget.hpp"
#include "gameoverdialog.hpp"

/**
 * @class MainWindow
 * @brief Fereastra principală a aplicației, gestionând widget-ul de joc și dialogurile.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    /**
     * @brief Creează fereastra principală.
     * @param parent Fereastra părinte.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Este apelat când jocul se termină.
     */
    void onGameOver();

    /**
     * @brief Este apelat când utilizatorul apasă „Replay”.
     */
    void onReplayClicked();

private:
    GameFieldWidget *gameFieldWidget; ///< Widget cu logica și afișarea jocului.
    SnakeTimer *snakeTimer;           ///< Timer pentru actualizările periodice.
    GameOverDialog *gameOverDialog;   ///< Dialogul Game Over.
};

#endif
