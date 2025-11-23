#pragma once
#include "point.hpp"
#include <iostream>
#include <memory>

class Apple {
    Point _position;
public:
    Apple();
    explicit Apple(const Point& position);
    Apple(const Apple& other) = default;
    Apple& operator=(const Apple& other) = default;
    
    bool operator==(const Apple& other) const;
    bool operator!=(const Apple& other) const;
    
    Point GetPosition() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Apple& a);
    friend std::istream& operator>>(std::istream& is, Apple& a);
};