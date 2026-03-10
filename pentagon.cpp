#include "pentagon.h"
#include "point.h"

Pentagon::Pentagon() {
    for (int i = 0; i<5; ++i){
        std::cout<<"Точка "<<i<<std::endl;
        Point point;
        this->points[i] = point;
    }
}