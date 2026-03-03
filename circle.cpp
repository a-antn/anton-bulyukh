#define _USE_MATH_DEFINES
#include "circle.h"
#include "point.h"
#include <math.h>

Circle::Circle(const Point center, const double radius) {
    if (radius <= DBL_EPSILON) {
        std::cout<<"Error\n";
        exit(EXIT_FAILURE);
    }
    this->center = center;
    this->radius = radius;
}

double Circle::GetSquare() const {
    return M_PI*radius*radius;
}

double Circle::GetLength() const {
    return 2*M_PI*radius;

}
