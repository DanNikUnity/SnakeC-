#include "game_engine.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

GameEngine::GameEngine() 
    : _apple(std::make_unique<Apple>(Point{5, 5}))
    , _snake(std::make_unique<Snake>(Point{0, 0}))
    , _board(std::make_unique<Board>(10, 20))
    , _painter(std::make_unique<Painter>()) {
}

void GameEngine::Init() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << "Snake Game Initialized! Board " << _board->GetWidth() << "x" << _board->GetHeight() << "\n";
}

void GameEngine::Run(Direction dir) {
    _snake->Move(dir);
    Point head = _snake->GetPosition();
    
    if (head == _apple->GetPosition()) {
        _snake->Eat(*_apple);

        Point newApplePos = GenerateRandomApplePosition();
        _apple = std::make_unique<Apple>(newApplePos);
    }
    
    if (CheckCollision()) {
        std::cout << "Game Over! Collision detected.\n";
        return;
    }
    
    const auto& segments = _snake->GetSegments();
    _painter->DrawBoard(_board->GetWidth(), _board->GetHeight(), segments, _apple->GetPosition());
    steps++;
}

bool GameEngine::CheckCollision() const {
    Point head = _snake->GetPosition();
    
    if (head.x < 0 || head.x >= _board->GetWidth() || 
        head.y < 0 || head.y >= _board->GetHeight()) {
        return true;
    }
    
    const auto& segments = _snake->GetSegments();
    if (segments.size() > 1) {
        return std::find(segments.begin() + 1, segments.end(), head) != segments.end();
    }
    
    return false;
}

Point GameEngine::GenerateRandomApplePosition() const {
    std::vector<Point> validPositions;
    
    for (int y = 0; y < _board->GetHeight(); y++) {
        for (int x = 0; x < _board->GetWidth(); x++) {
            Point pos{x, y};
            if (!_snake->ContainsPoint(pos)) {
                validPositions.push_back(pos);
            }
        }
    }
    
    if (validPositions.empty()) {
        return Point{0, 0};
    }
    
    int randomIndex = std::rand() % validPositions.size();
    return validPositions[randomIndex];
}

bool GameEngine::IsPositionValid(const Point& pos) const {
    return pos.x >= 0 && pos.x < _board->GetWidth() && 
           pos.y >= 0 && pos.y < _board->GetHeight() &&
           !_snake->ContainsPoint(pos);
}