#pragma once
#include "apple.hpp"
#include "direction.hpp"
#include "point.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Snake {
    std::vector<Point> _segments;

    bool _growNextMove = false;
    
public:
    Snake();
    explicit Snake(const Point& position);
    Snake(const Snake& other) = default;
    Snake& operator=(const Snake& other) = default;
    
    bool operator==(const Snake& other) const;
    bool operator!=(const Snake& other) const;
    
    void Move(Direction direction);
    int GetSize() const;
    Point GetPosition() const;
    const std::vector<Point>& GetSegments() const;
    std::vector<Point>& GetSegments();

    void Eat(const Apple& apple);
    
    bool ContainsPoint(const Point& point) const;
    void SetHeadPosition(const Point& newPosition);
    
    friend std::ostream& operator<<(std::ostream& os, const Snake& s);
    friend std::istream& operator>>(std::istream& is, Snake& s);
};