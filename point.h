#include <iostream>

class Point {
    private:
        double x;
        double y;
    public:
        Point();
        double GetX() const;
        double GetY() const;
        friend std::ostream& operator<<(std::ostream, const Point p);
};