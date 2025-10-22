#pragma once
#include "apple.hpp"
#include "painter.hpp"
#include "snake.hpp"
#include "board.hpp"
#include "direction.hpp"

class GameEngine {
   Apple _apple;
   Snake _snake;
   Board _board;
   int steps = 0;
public:
   GameEngine();
   void Init();
   void Run(Direction dir);
   Painter painter;   
};