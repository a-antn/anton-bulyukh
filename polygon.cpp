#include "polygon.h"

Polygon::Polygon () {
    
}

std::istream& operator>>(std::istream& in, Polygon data) {
    in >> data.points_amount >> data.side_length;
    return in;
}

std::ostream& operator<<(std::ostream& os, const Polygon data) {
    
}