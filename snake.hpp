#pragma once
#include "apple.hpp"
#include "direction.hpp"
#include "point.hpp"
#include <iostream>

class Snake {
    Point _segments[100];
    int _nr_segments;
public:
    Snake();
    Snake(const Point& position);
    Snake(const Snake& other);
    Snake& operator=(const Snake& other);

    bool operator==(const Snake& other) const;
    bool operator!=(const Snake& other) const;

    void Move(Direction direction);
    int GetSize() const;
    Point GetPosition() const;
    const Point* GetSegments() const;
    void Eat(const Apple& apple);

    friend std::ostream& operator<<(std::ostream& os, const Snake& s);
    friend std::istream& operator>>(std::istream& is, Snake& s);
};
