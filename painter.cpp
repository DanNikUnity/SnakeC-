#include "painter.hpp"
#include <iostream>
#include <vector>
#include <string>

void Painter::DrawBoard(int width, int height, const std::vector<Point>& snake, Point apple) {
    std::vector<std::string> grid(height, std::string(width, ' '));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Array[y][x] = 0;
        }
    }
    if (apple.y >= 0 && apple.y < height && apple.x >= 0 && apple.x < width) {
        Array[apple.y][apple.x] = 2;
    }

    for (size_t i = 0; i < snake.size(); i++) {
        int x = snake[i].x;
        int y = snake[i].y;
        if (x >= 0 && x < width && y >= 0 && y < height) {
            Array[y][x] = 1;
        }
    }

    std::cout << "\n";
    for (int y = 0; y < height; y++) {
        std::cout << "|";
        for (int x = 0; x < width; x++) {
            std::cout << grid[y][x];
        }
        std::cout << "|\n";
    }
}