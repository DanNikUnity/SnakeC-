#include <gtest/gtest.h>

#include <iostream>

#include "../SnakeCore/apple.hpp"
#include "../SnakeCore/board.hpp"
#include "../SnakeCore/direction.hpp"
#include "../SnakeCore/game_engine.hpp"
#include "../SnakeCore/painter.hpp"
#include "../SnakeCore/point.hpp"
#include "../SnakeCore/snake.hpp"

TEST(TestsSnakeModel, Subtest0) {
  Snake snake;

  ASSERT_EQ(snake.GetSize(), 1);
}

TEST(TestsSnakeModel, TestMove) {
    Snake snake;
    Point initialPos = snake.GetPosition();
    snake.Move(Direction::Bottom);
    Point newPos = snake.GetPosition();
    
    ASSERT_FALSE(initialPos == newPos);
}