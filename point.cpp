#include <cmath>
#include <sstream>

#include "point.h"

Point::Point(double x, double y)
    : x{x}, y{y}
{
}

double Point::GetX() const
{
    return x;
}

double Point::GetY() const
{
    return y;
}

double Point::DistanceTo(const Point& other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

std::string Point::ToString() const
{
    std::ostringstream oss;
    oss << "(" << x << "; " << y << ")";
    return oss.str();
}

bool Point::operator==(const Point& other) const
{
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

bool Point::operator<(const Point& other) const
{
    if (x != other.x)
    {
        return x < other.x;
    }
    return y < other.y;
}

bool Point::operator>(const Point& other) const
{
    return other < *this;
}

bool Point::operator<=(const Point& other) const
{
    return !(other < *this);
}

bool Point::operator>=(const Point& other) const
{
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
    out << "(" << p.x << "; " << p.y << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Point& p)
{
    in >> p.x >> p.y;
    return in;
}
