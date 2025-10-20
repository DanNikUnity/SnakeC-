#include "painter.hpp"
#include <iostream>
#include <vector>
#include <string>

void Painter::DrawBoard(int width, int height, const std::vector<Point>& snake, Point apple) {
    std::vector<std::string> grid(height, std::string(width, ' '));

    if (apple.y >= 0 && apple.y < height && apple.x >= 0 && apple.x < width) {
        grid[apple.y][apple.x] = 'A';
    }

    for (size_t i = 0; i < snake.size(); i++) {
        int x = snake[i].x;
        int y = snake[i].y;
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x] = (i == 0 ? 'O' : 'o');
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
