#include "point.h"

class Pentagon {
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