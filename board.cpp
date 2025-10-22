#include "board.hpp"

Board::Board(int width, int height) : _width(width), _height(height) {}
Board::Board(const Board& other) : _width(other._width), _height(other._height) {}
Board& Board::operator=(const Board& other) {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
    }
    return *this;
}

bool Board::operator==(const Board& other) const {
    return _width == other._width && _height == other._height;
}

bool Board::operator!=(const Board& other) const {
    return !(*this == other);
}

int Board::GetWidth() const { return _width; }
int Board::GetHeight() const { return _height; }

std::ostream& operator<<(std::ostream& os, const Board& b) {
    os << "Board(" << b._width << "x" << b._height << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Board& b) {
    is >> b._width >> b._height;
    return is;
}
