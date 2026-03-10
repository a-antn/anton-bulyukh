#include "point.h"

class Polygon {
    private:
        Point* points[5];
        double* sides;     
    public:
        Polygon();
        void ToString() const;
    
};