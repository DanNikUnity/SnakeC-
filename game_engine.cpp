#include "game_engine.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>

GameEngine::GameEngine()
    : _apple(Point{5, 5}), _snake(Point{0, 0}), _board(10, 20) {}

void GameEngine::Init() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << "Snake Game Initialized! Board " 
              << _board.GetWidth() << "x" << _board.GetHeight() << "\n";
}

void GameEngine::Run(Direction dir) {
    char input;
   // for (int step = 0; step < 5; step++) {
        // std::cout << "Move (WASD): ";
        // std::cin >> input;
        // switch (input) {
        //     case 'w': dir = Direction::Top; break;
        //     case 'a': dir = Direction::Left; break;
        //     case 's': dir = Direction::Bottom; break;
        //     case 'd': dir = Direction::Right; break;
        //     default: break;
        // }
        _snake.Move(dir);

        Point head = _snake.GetPosition();
        if (head.x == _apple.GetPosition().x && head.y == _apple.GetPosition().y) {
            _snake.Eat(_apple);
            Point newApplePos{std::rand() % _board.GetWidth(),
                              std::rand() % _board.GetHeight()};
            _apple = Apple(newApplePos);
        }

        std::vector<Point> body;
        const Point* segs = _snake.GetSegments();
        for (int i = 0; i < _snake.GetSize(); i++) {
            body.push_back(segs[i]);
        }

        painter.DrawBoard(_board.GetWidth(), _board.GetHeight(), body, _apple.GetPosition());

        steps++;
    //}
}