#include "polygon.h"

std::ostream& operator<<(std::ostream& out, const Polygon& p)
{
    out << p.ToString();
    return out;
}

std::istream& operator>>(std::istream& in, Polygon& p)
{
    p.Read(in);
    return in;
}
