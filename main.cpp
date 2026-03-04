#include "circle.h"
#include "point.h"

/**
 * @brief Считывает введенное значение
 * @params message Сообщение пользователю
 * @returns Введенное значение
 */
double getValue(std::string message);

/**
 * @brief Точка входа в программу
 * @return 0 в случае успеха
 */
int main () {
    double center_x = getValue("Enter centerX: ");
    double center_y = getValue("Enter centerY: ");
    Point center(center_x, center_y);
    double radius = getValue("Enter radius");
    Circle myCircle(center, radius);
    std::cout<<"Square is: "<<myCircle.GetSquare()<<std::endl;
    std::cout<<"Length is: "<<myCircle.GetLength()<<std::endl;
    
    return 0;
}

double getValue(std::string message) {
    double value;
    std::cout<<message;
    std::cin>>value;
    return value;
}