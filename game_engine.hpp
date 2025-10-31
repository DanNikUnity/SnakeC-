#pragma once
#include "apple.hpp"
#include "painter.hpp"
#include "snake.hpp"
#include "board.hpp"
#include "direction.hpp"
#include <memory>
#include <vector>
#include <algorithm>

class GameEngine {
    std::unique_ptr<Apple> _apple;
    std::unique_ptr<Snake> _snake;
    std::unique_ptr<Board> _board;
    std::unique_ptr<Painter> _painter;
    int steps = 0;
    
public:
    GameEngine();
    void Init();
    void Run(Direction dir);
    
    bool CheckCollision() const;
    Point GenerateRandomApplePosition() const;
    
    const Painter& GetPainter() const { return *_painter; }
    Painter& GetPainter() { return *_painter; }
    
private:
    bool IsPositionValid(const Point& pos) const;
};