#include <iostream>

/**
 * @brief Класс Точка 
 */
class Point {
    private:
        /**
         * @brief координата Х точки
         */
        double x;

        /**
         * @brief координата Y точки
         */
        double y;
    public:
        /**
         * @brief конструктор
         * @param center_x координата Х точки
         * @param center_y координата Y точки
         */
        Point(const double x, const double y);
        /**
         * @brief Получение координаты X точки
         * @return Координата X точки
         */
        double GetX() const;
        /**
         * @brief Получение координаты Y точки
         * @return Координата Y точки
         */
        double GetY() const;
};

