#include "point.h"

Point::Point(const double x, const double y) {
    this->x = x;
    this->y = y;
}

double Point::GetX() const {
    return this->x;
}

double Point::GetY() const {
    return this->y;
}