#include "game_engine.hpp"
#include "painter.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>

GameEngine::GameEngine()
    : _apple(Point{5, 5}), _snake(Point{0, 0}), _board(20, 10) {}

void GameEngine::Init() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << "Snake Game Initialized! Board " 
              << _board.GetWidth() << "x" << _board.GetHeight() << "\n";
}

void GameEngine::Run() {
    Painter painter;
    Direction dir = Direction::Right;
    char input;
    for (int step = 0; step < 100; step++) {
        std::cout << "Move (WASD): ";
        std::cin >> input;
        switch (input) {
            case 'w': dir = Direction::Top; break;
            case 'a': dir = Direction::Left; break;
            case 's': dir = Direction::Bottom; break;
            case 'd': dir = Direction::Right; break;
            default: break;
        }
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

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        painter.DrawBoard(_board.GetWidth(), _board.GetHeight(), body, _apple.GetPosition());
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
