#pragma once
#include "point.hpp"
#include <iostream>

class Apple {
    Point _position;
public:
    Apple();
    Apple(const Point& position);
    Apple(const Apple& other);
    Apple& operator=(const Apple& other);

    bool operator==(const Apple& other) const;
    bool operator!=(const Apple& other) const;

    Point GetPosition() const;

    friend std::ostream& operator<<(std::ostream& os, const Apple& a);
    friend std::istream& operator>>(std::istream& is, Apple& a);
};
