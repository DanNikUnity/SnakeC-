#include "apple.hpp"

Apple::Apple() : _position{0, 0} {}

Apple::Apple(const Point &position) : _position(position) {}

Point Apple::GetPosition() const {
    return _position;
}
