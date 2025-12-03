/**
 * @file apple.hpp
 * @brief Clasa Apple — poziția mărului de pe tablă.
 *
 * Proiect: Snake Game — Laborator 06
 * Autor: Nicolaev Dan
 * An: 2025
 */

#pragma once
#include "point.hpp"
#include <iostream>

/**
 * @class Apple
 * @brief Reprezintă un măr plasat pe tablă.
 */
class Apple {
    Point _position; ///< Poziția curentă a mărului

public:
    /// Constructor implicit — poziția (0,0)
    Apple();

    /**
     * @brief Constructor cu poziție.
     * @param position poziția mărului
     */
    explicit Apple(const Point& position);

    /// Operator ==
    bool operator==(const Apple& other) const;

    /// Operator !=
    bool operator!=(const Apple& other) const;

    /// Obține poziția mărului.
    Point GetPosition() const;

    /// Serializare.
    friend std::ostream& operator<<(std::ostream& os, const Apple& a);

    /// Deserializare.
    friend std::istream& operator>>(std::istream& is, Apple& a);
};
