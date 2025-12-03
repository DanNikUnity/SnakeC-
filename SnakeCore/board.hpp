/**
 * @file board.hpp
 * @brief Clasa Board — dimensiunile tablei de joc.
 *
 * Proiect: Snake Game — Laborator 06
 * Autor: Nicolaev Dan
 * An: 2025
 */

#pragma once
#include <iostream>

/**
 * @class Board
 * @brief Reprezintă tabla de joc (lățime + înălțime).
 */
class Board {
    int _width;  ///< Lățimea tablei
    int _height; ///< Înălțimea tablei

public:
    /**
     * @brief Constructor.
     * @param width lățime
     * @param height înălțime
     */
    Board(int width = 20, int height = 20);

    /// Operator ==
    bool operator==(const Board& other) const;

    /// Operator !=
    bool operator!=(const Board& other) const;

    /// Returnează lățimea tablei.
    int GetWidth() const;

    /// Returnează înălțimea tablei.
    int GetHeight() const;

    friend std::ostream& operator<<(std::ostream& os, const Board& b);
    friend std::istream& operator>>(std::istream& is, Board& b);
};
