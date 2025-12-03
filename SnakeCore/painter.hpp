/**
 * @file painter.hpp
 * @brief Asamblarea reprezentării grafice interne a tablei.
 *
 * Proiect: Snake Game — Laborator 06
 * Autor: Nicolaev Dan
 * An: 2025
 */

#pragma once
#include "point.hpp"
#include <vector>

/**
 * @class IPainter
 * @brief Interfață abstractă pentru redarea tablei.
 */
class IPainter {
public:
    virtual ~IPainter() = default;

    /**
     * @brief Desenează tabla și populează structura internă.
     */
    virtual void DrawBoard(int width, int height,
                           const std::vector<Point>& snake,
                           Point apple) = 0;
};

/**
 * @class Painter
 * @brief Implementarea standard a IPainter.
 */
class Painter : public IPainter {
public:
    std::vector<std::vector<int>> Array; ///< Reprezentarea internă a tablei

    Painter() = default;
    Painter(int height, int width);

    void DrawBoard(int width, int height,
                   const std::vector<Point>& snake,
                   Point apple) override;

private:
    void Init(int width, int height);
    void PlaceSnake(const std::vector<Point>& snake);
    void PlaceApple(const Point& apple);
};
