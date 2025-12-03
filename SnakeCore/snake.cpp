#include "snake.hpp"
#include <algorithm>


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

    Point newHead(0,0);
    if (!_segments.empty()) newHead = _segments.front();
    
    switch (direction) {
        case Direction::Top: newHead.y -= 1; break;
        case Direction::Bottom: newHead.y += 1; break;
        case Direction::Left: newHead.x -= 1; break;
        case Direction::Right: newHead.x += 1; break;
    }
    
    if (_segments.empty()) {
        _segments.push_back(newHead);

        if (_growNextMove) _growNextMove = false;
        return;
    }
    

    _segments.insert(_segments.begin(), newHead);
    if (_growNextMove) {
        _growNextMove = false;
    } else {
        _segments.pop_back();
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


void Snake::Eat(const Apple& apple) {
    (void)apple;

    _growNextMove = true;
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