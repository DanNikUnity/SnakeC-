/**
 * @file gamefieldwidget.hpp
 * @author Nicolaev Dan
 * @date 2025
 * @brief Widget-ul principal care afișează câmpul jocului și gestionează logica de joc.
 */

#ifndef GAMEFIELDWIDGET_H
#define GAMEFIELDWIDGET_H

#include "game_engine.hpp"
#include <QWidget>
#include <memory>

/**
 * @class GameFieldWidget
 * @brief Widget responsabil pentru reprezentarea grafică a jocului și input-ul utilizatorului.
 *
 * Utilizează GameEngine pentru logica jocului și redă starea pe ecran.
 */
class GameFieldWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Creează widget-ul câmpului de joc.
     * @param parent Widget părinte.
     */
    explicit GameFieldWidget(QWidget *parent = nullptr);

public slots:
    /**
     * @brief Actualizare periodică a jocului (tick).
     */
    void gameTick();

    /**
     * @brief Resetează jocul.
     */
    void resetGame();

private:
    std::unique_ptr<GameEngine> _gameEngine; ///< Motorul jocului.
    Direction userAction = Direction::Right; ///< Ultima acțiune direcțională a utilizatorului.

protected:
    /**
     * @brief Desenează elementele jocului.
     */
    void paintEvent(QPaintEvent *event) override;

    /**
     * @brief Gestionează apăsările de taste (input).
     */
    void keyPressEvent(QKeyEvent *event) override;

    static constexpr int CELL_SIZE = 40; ///< Dimensiunea unei celule pe grid.

signals:
    /**
     * @brief Semnal emis când este declanșat Game Over.
     */
    void gameOverTriggered();

};

#endif
