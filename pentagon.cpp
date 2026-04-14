#include "pentagon.h"
#include "point.h"

Pentagon::Pentagon() {
    for (int i = 0; i<5; ++i){
        std::cout<<"Точка "<<i+1<<std::endl;
        Point point;
        for (int j = 0; j < 5; j++) {
            if (points[j] == point) {
                std::cout<<"Данная точка уже была введена. Попробуйте другую:"<<std::endl;
                i--;
                continue;
            }
        }
        points[i] = point;
    }
}