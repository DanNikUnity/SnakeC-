#pragma once
#include <iostream>

class Board {
    int _width;
    int _height;
public:
    Board(int width = 20, int height = 20);
    Board(const Board& other);
    Board& operator=(const Board& other);

    bool operator==(const Board& other) const;
    bool operator!=(const Board& other) const;

    int GetWidth() const;
    int GetHeight() const;

    friend std::ostream& operator<<(std::ostream& os, const Board& b);
    friend std::istream& operator>>(std::istream& is, Board& b);
};
