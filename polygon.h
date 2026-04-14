#include "point.h"

class Polygon {
    protected:
        int points_amount;
        Point points[5];
        double side_length;     
    public:
        Polygon();
        virtual void ToString() const;
        virtual double GetSquare() const;
        virtual double GetPerimetr();
        virtual double GetRadius() const;
        friend std::istream& operator>>(std::istream& in, const Polygon data);
        friend std::ostream& operator<<(std::ostream& os, const Polygon data);
        virtual ~Polygon() = default;
};