#include "painter.hpp"
#include <iostream>

void Painter::DrawBoard(int width, int height, const std::vector<Point>& snake, Point apple) {
    if (Array.size() != static_cast<size_t>(height) || (Array.size() > 0 && Array[0].size() != static_cast<size_t>(width))) {
        Array = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
    } else {
        for (auto& row : Array) {
            std::fill(row.begin(), row.end(), 0);
        }
    }
    
    if (apple.y >= 0 && apple.y < height && apple.x >= 0 && apple.x < width) {
        Array[apple.y][apple.x] = 2;
    }
    
    for (const auto& segment : snake) {
        int x = segment.x;
        int y = segment.y;
        if (x >= 0 && x < width && y >= 0 && y < height) {
            Array[y][x] = 1;
        }
    }
    
    std::cout << "\n";
    for (int y = 0; y < height; y++) {
        std::cout << "|";
        for (int x = 0; x < width; x++) {
            char symbol = ' ';
            if (Array[y][x] == 1) symbol = 'S';
            else if (Array[y][x] == 2) symbol = 'A';
            std::cout << symbol;
        }
        std::cout << "|\n";
    }
}