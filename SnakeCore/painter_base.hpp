#pragma once
#include "point.hpp"
#include <vector>

class IPainter {
public:
    virtual ~IPainter() = default;
    virtual void DrawBoard(int width, int height, const std::vector<Point>& snake, Point apple) = 0;
};
