#include <cmath>
#include <limits>
#include <sstream>

#include "point.h"

Point::Point(const double x, const double y)
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
    const double dx = x - other.x;
    const double dy = y - other.y;
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
    return std::fabs(x - other.x) <= std::numeric_limits<double>::epsilon()
        && std::fabs(y - other.y) <= std::numeric_limits<double>::epsilon();
}

bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

bool Point::operator<(const Point& other) const
{
    if (std::fabs(x - other.x) > std::numeric_limits<double>::epsilon())
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
