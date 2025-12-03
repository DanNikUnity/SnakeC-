#include "game_engine.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

GameEngine::GameEngine()
    : _snake(std::make_unique<Snake>(Point{0, 0}))
    , _apple(std::make_unique<Apple>(Point{5, 5}))
    , _board(std::make_unique<Board>(10, 20))
    , _painter(std::make_unique<Painter>())
{
}

void GameEngine::Init() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    steps = 0;
    gameOver = false;
}

void GameEngine::Run(Direction dir) {
    _snake->Move(dir);
    Point head = _snake->GetPosition();

    int boardWidth = _board->GetWidth();
    int boardHeight = _board->GetHeight();

    if (head.x < 0) head.x = boardWidth - 1;
    else if (head.x >= boardWidth) head.x = 0;

    if (head.y < 0) head.y = boardHeight - 1;
    else if (head.y >= boardHeight) head.y = 0;

    _snake->SetHeadPosition(head);

    if (head == _apple->GetPosition()) {
        _snake->Eat(*_apple);
        _apple = std::make_unique<Apple>(GenerateRandomApplePosition());
    }

    if (CheckCollision()) {
        gameOver = true;
        return;
    }

    const auto& snakeSegments = _snake->GetSegments();
    _painter->DrawBoard(boardWidth, boardHeight, snakeSegments, _apple->GetPosition());

    steps++;
}

bool GameEngine::CheckCollision() const {
    Point head = _snake->GetPosition();
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
