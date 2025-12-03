/**
 * @file game_engine.hpp
 * @brief Clasa GameEngine — logica principală a jocului.
 *
 * Proiect: Snake Game — Laborator 06
 * Autor: Nicolaev Dan
 * An: 2025
 */

#pragma once
#include <memory>
#include <vector>
#include "snake.hpp"
#include "apple.hpp"
#include "board.hpp"
#include "painter.hpp"
#include "direction.hpp"

/**
 * @class GameEngine
 * @brief Controlează jocul: mișcare, coliziuni, generare de mere.
 */
class GameEngine {
    std::unique_ptr<Snake> _snake;   ///< Șarpele
    std::unique_ptr<Apple> _apple;   ///< Mărul curent
    std::unique_ptr<Board> _board;   ///< Tabla de joc
    std::unique_ptr<Painter> _painter; ///< Painter-ul responsabil de randare

    bool gameOver = false; ///< Dacă jocul s-a încheiat
    int steps = 0;         ///< Numărul de pași efectuați

public:
    /// Constructorul principal
    GameEngine();

    /// Inițializează jocul
    void Init();

    /// Execută o etapă a jocului în funcție de direcție
    void Run(Direction dir);

    /// Verifică starea jocului
    bool IsGameOver() const { return gameOver; }

    /// Acces pentru verificarea numărului de pași
    int GetSteps() const { return steps; }

    /// Generează o nouă poziție validă pentru măr
    Point GenerateRandomApplePosition() const;

    /// Acces la Painter
    const Painter& GetPainter() const { return *_painter; }

private:
    /// Verifică coliziunea șarpelui cu propriul corp
    bool CheckCollision() const;
};
