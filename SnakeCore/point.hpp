/**
 * @file point.hpp
 * @brief Definiția structurii Point — coordonatele unui punct din joc.
 *
 * Proiect: Snake Game — Laborator 06
 * Autor: Nicolaev Dan
 * An: 2025
 */

#pragma once
#include <iostream>

/**
 * @struct Point
 * @brief Reprezintă o poziție în plan, prin coordonatele (x, y).
 *
 * Structura Point este utilizată în întreg jocul pentru:
 * - poziția șarpelui
 * - poziția mărului
 * - verificări de coliziune
 */
struct Point {
    int x; ///< Coordonata X
    int y; ///< Coordonata Y

    /**
     * @brief Constructor implicit, setează (0,0).
     */
    Point();

    /**
     * @brief Constructor cu coordonate.
     * @param _x coordonata X
     * @param _y coordonata Y
     */
    Point(int _x, int _y);

    /// Operator de egalitate.
    bool operator==(const Point& other) const;

    /// Operator de diferență.
    bool operator!=(const Point& other) const;

    /// Operator pentru sortare (folosit în teste/algoritmi).
    bool operator<(const Point& other) const;

    /// Serializare în flux.
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /// Deserializare din flux.
    friend std::istream& operator>>(std::istream& is, Point& p);
};
