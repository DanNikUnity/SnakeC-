#include "snake.hpp"

Snake::Snake() {
    _segments.emplace_back(0, 0);
}

Snake::Snake(const Point& position) {
    _segments.push_back(position);
}

bool Snake::operator==(const Snake& other) const {
    return _segments == other._segments;
}

bool Snake::operator!=(const Snake& other) const {
    return !(*this == other);
}

void Snake::Move(Direction direction) {
    for (size_t i = _segments.size() - 1; i > 0; --i) {
        _segments[i] = _segments[i - 1];
    }
    
    Point& head = _segments[0];
    switch (direction) {
        case Direction::Top: head.y -= 1; break;
        case Direction::Bottom: head.y += 1; break;
        case Direction::Left: head.x -= 1; break;
        case Direction::Right: head.x += 1; break;
    }
}

int Snake::GetSize() const {
    return static_cast<int>(_segments.size());
}

Point Snake::GetPosition() const {
    return _segments.front();
}

const std::vector<Point>& Snake::GetSegments() const {
    return _segments;
}

std::vector<Point>& Snake::GetSegments() {
    return _segments;
}

void Snake::Eat(const Apple& apple) {
    if (!_segments.empty()) {
        _segments.push_back(_segments.back());
    }
}

bool Snake::ContainsPoint(const Point& point) const {
    return std::find(_segments.begin(), _segments.end(), point) != _segments.end();
}

void Snake::SetHeadPosition(const Point& newPosition) {
    if (!_segments.empty()) {
        _segments[0] = newPosition;
    }
}

std::ostream& operator<<(std::ostream& os, const Snake& s) {
    os << "Snake(";
    for (size_t i = 0; i < s._segments.size(); i++) {
        os << s._segments[i];
        if (i < s._segments.size() - 1) os << ", ";
    }
    os << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Snake& s) {
    int segmentCount;
    is >> segmentCount;
    s._segments.resize(segmentCount);
    for (int i = 0; i < segmentCount; i++) {
        is >> s._segments[i];
    }
    return is;
}