
#include "snake.hpp"

Snake::Snake() : _nr_segments(1) {
   _segments[0] = {0, 0};
}

Snake::Snake(const Point &_position) : _nr_segments(1) {
   _segments[0] = _position;
}

void Snake::Move(Direction direction) {
   for (int i = _nr_segments - 1; i > 0; --i) {
      _segments[i] = _segments[i - 1];
   }

   switch (direction) {
      case Direction::Top:    _segments[0].y -= 1; break;
      case Direction::Bottom: _segments[0].y += 1; break;
      case Direction::Left:   _segments[0].x -= 1; break;
      case Direction::Right:  _segments[0].x += 1; break;
   }
}

int Snake::GetSize() const {
   return _nr_segments;
}

Point Snake::GetPosition() const {
   return _segments[0];
}

void Snake::Eat(const Apple &apple) {
   if (_nr_segments < 100) {
      _segments[_nr_segments] = _segments[_nr_segments - 1];
      _nr_segments++;
   }
}

const Point* Snake::GetSegments() const {
   return _segments;
}

Snake::Snake(const Snake& other) : _nr_segments(other._nr_segments) {
    for (int i = 0; i < _nr_segments; i++)
        _segments[i] = other._segments[i];
}

Snake& Snake::operator=(const Snake& other) {
    if (this != &other) {
        _nr_segments = other._nr_segments;
        for (int i = 0; i < _nr_segments; i++)
            _segments[i] = other._segments[i];
    }
    return *this;
}

bool Snake::operator==(const Snake& other) const {
    if (_nr_segments != other._nr_segments) return false;
    for (int i = 0; i < _nr_segments; i++)
        if (_segments[i] != other._segments[i])
            return false;
    return true;
}

bool Snake::operator!=(const Snake& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Snake& s) {
    os << "Snake(";
    for (int i = 0; i < s._nr_segments; i++) {
        os << s._segments[i];
        if (i < s._nr_segments - 1) os << ", ";
    }
    os << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Snake& s) {
    is >> s._nr_segments;
    for (int i = 0; i < s._nr_segments; i++) {
        is >> s._segments[i];
    }
    return is;
}

