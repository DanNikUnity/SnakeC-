/**
 * @file snake.hpp
 * @brief Clasa Snake — logica șarpelui (segmente, mișcare, creștere).
 *
 * Proiect: Snake Game — Laborator 06
 * Autor: Nicolaev Dan
 * An: 2025
 */

#pragma once
#include "point.hpp"
#include "apple.hpp"
#include "direction.hpp"
#include <vector>
#include <iostream>

/**
 * @class Snake
 * @brief Reprezintă șarpele: corpul, mișcarea și creșterea.
 */
class Snake {
    std::vector<Point> _segments; ///< Segmentele șarpelui
    bool _growNextMove = false;       ///< Dacă șarpele trebuie să crească la următoarea mutare

public:
    /// Constructor implicit — un singur segment la (0,0)
    Snake();

    /// Constructor cu poziție inițială
    explicit Snake(const Point& position);

    /// Operator ==
    bool operator==(const Snake& other) const;

    /// Operator !=
    bool operator!=(const Snake& other) const;

    /**
     * @brief Mută șarpele într-o direcție.
     * @param direction direcția de mers
     */
    void Move(Direction direction);

    /**
     * @brief Crește șarpele dacă mănâncă mărul.
     */
    void Eat(const Apple& apple);

    /**
     * @brief Returnează poziția capului.
     */
    Point GetPosition() const;

    /**
     * @brief Returnează numărul de segmente.
     */
    int GetSize() const;

    /**
     * @brief Returnează segmentele șarpelui.
     */
    const std::vector<Point>& GetSegments() const;

    /// Verifică dacă punctul dat aparține corpului.
    bool ContainsPoint(const Point& p) const;

    /// Setează poziția capului (folosit la respawn/teleport).
    void SetHeadPosition(const Point& p);

    friend std::ostream& operator<<(std::ostream& os, const Snake& s);
    friend std::istream& operator>>(std::istream& is, Snake& s);
};
