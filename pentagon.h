#include "point.h"
#include "polygon.h"

class Pentagon:Polygon {
    private:
        Point points[5];
        double* sides[5];
    public:
        Pentagon();
        void ToString();
        double GetSquare() const;
        double GetPerimetr() const;
        double GetRadius() const;
};