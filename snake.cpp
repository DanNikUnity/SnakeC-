
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
