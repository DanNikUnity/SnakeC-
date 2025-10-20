#include "board.hpp"

Board::Board(int width, int height) : _width(width), _height(height) {}

int Board::GetWidth() const {
    return _width;
}

int Board::GetHeight() const {
    return _height;
}
