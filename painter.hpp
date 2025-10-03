#pragma once
#include "point.hpp"
#include <vector>

class Painter {
public:
   void DrawBoard(int width, int height, const std::vector<Point>& snake, Point apple);
};
