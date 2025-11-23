#pragma once
#include "point.hpp"
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

class IPainter {
public:
    virtual ~IPainter() = default;
    virtual void DrawBoard(int width, int height, const std::vector<Point>& snake, Point apple) = 0;
};

class Painter : public IPainter {
public:
    std::vector<std::vector<int>> Array;
    
    Painter() = default;
    explicit Painter(int height, int width) : Array(height, std::vector<int>(width, 0)) {}
    
    void DrawBoard(int width, int height, const std::vector<Point>& snake, Point apple) override;
    
private:
    void InitializeArray(int width, int height);
    void PlaceApple(const Point& apple, int width, int height);
    void PlaceSnake(const std::vector<Point>& snake, int width, int height);
};