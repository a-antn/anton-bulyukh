#include <iostream>
#include "point.h"

Point::Point() {
    double inputedX;
    double inputedY;
    std::cout<<"Введите X точки: ";
    std::cin>>inputedX;
    std::cout<<std::endl;
    std::cout<<"Введите X точки: ";
    std::cin>>inputedY;
    std::cout<<std::endl;
    this->x = inputedX;
    this->y = inputedY;
}  

double Point::GetX() const {
    return this->x;
}

double Point::GetY() const {
    return this->y;
}

std::ostream& operator<<(std::ostream& out, const Point& p){
    std::cout << "Point. X: " << p.GetX() << "Y: " << p.GetY();
}

bool Point::operator==(const Point& other) const {
    return x == other.GetX() && y == other.GetY(); 
}

bool Point::checkOneLine(Point& p1, Point& p2, Point& p3) {
    return (p2.GetX() - p1.GetX())*(p3.GetY() - p1.GetY()) - (p2.GetY() - p1.GetY())*(p3.GetY()-p1.GetY()) == 0;
}