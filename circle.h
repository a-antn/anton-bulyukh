#include <iostream>
#include "point.h"
/**
 * @brief Класс Окружность 
 */
class Circle {
    private:
        /**
         * @brief координата Х центра окружности
         */
        double center_x;
        
        /**
         * @brief координата Y центра окружности
         */
        double center_y;

        /**
         * @brief радиус окружности
         */
        double radius;
    public:
        /**
         * @brief конструктор
         * @param center_x координата Х центра окружности
         * @param center_y координата Y центра окружности
         * @param radius радиус окружности
         */
        Circle(const Point center, const double radius);

        /**
         * @brief Рассчет площади
         * @return Значение площади
         */
        double GetSquare() const;

        /**
         * @brief Рассчет длины окружности
         * @return Значение длины окружности
         */
        double GetLength() const;
};