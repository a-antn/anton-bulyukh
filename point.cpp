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

std::ostream& operator<<(std::ostream, const Point p){
    std::cout << "Point. X: " << p.x << "Y: " << p.y;
}